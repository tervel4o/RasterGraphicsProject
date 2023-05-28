#include <cassert>
#include "ColoredImageMatrix.hpp"

unsigned int ColoredImageMatrix::INIT_VALUE = 0;
ColoredImageMatrix::ColoredImageMatrix()
    : matrix( nullptr ), rows( 0 ), cols( 0 ), maxValue( 0 ) {}
ColoredImageMatrix::ColoredImageMatrix( std::size_t _rows, std::size_t _cols,
                                        const unsigned char _maxValue ) {
    this->rows = _rows;
    this->cols = _cols;
    this->maxValue = _maxValue;

    this->matrix = this->createMatrix( this->rows, this->cols );
}
ColoredImageMatrix::ColoredImageMatrix( const ColoredImageMatrix& other ) {
    this->copy( other );
}
ColoredImageMatrix::~ColoredImageMatrix() {
    this->destroy();
}

ColoredImageMatrix& ColoredImageMatrix::operator=( const ColoredImageMatrix& other ) {
    if ( this != &other ) {
        this->destroy();
        this->copy( other );
    }

    return *this;
}

bool ColoredImageMatrix::operator==( const ColoredImageMatrix& other ) {
    if ( this->rows != other.rows || this->cols != other.cols || this->maxValue != other.maxValue ) {
        return false;
    }

    for ( std::size_t i = 0 ; i < this->rows ; ++ i ) {
        for ( std::size_t j = 0 ; j < this->cols ; ++ j ) {
            if ( this->value( i , j ) != other.value( i , j ) ) {
                return false;
            }
        }
    }
    return true;
}

void ColoredImageMatrix::serialize( std::ostream& out ) const {
    out << this->cols << ' ' << this->rows << '\n';
    out << this->maxValue << '\n';

    for ( std::size_t i = 0 ; i < this->rows ; ++ i ) {
        for ( std::size_t j = 0 ; j < this->cols - 1 ; ++ j ) {
            out << this->value( i, j ) << ' '; 
        }
        out << this->value( i, this->cols - 1 ) << '\n';
    }
}
void ColoredImageMatrix::deserialize( std::istream& in ) {
    std::size_t rows, cols;
    in >> cols >> rows;
    
    unsigned int maxValue;
    in >> maxValue;

    *this = ColoredImageMatrix( rows, cols, maxValue );

    for ( std::size_t i = 0 ; i < this->rows ; ++ i ) {
        for ( std::size_t j = 0 ; j < this->cols ; ++ j ) {
            unsigned int c;
            in >> c;
            
            if ( c > this->maxValue ) {
                c = 0;
            }
            this->value( i, j ) = c;
        }
    }
}

void ColoredImageMatrix::destroy() {
    for ( std::size_t i = 0 ; i < this->rows ; ++ i ) {
        delete[] this->matrix[ i ];
    }
    delete[] this->matrix;
}
void ColoredImageMatrix::copy( const ColoredImageMatrix& other ) {
    this->rows = other.rows;
    this->cols = other.cols;
    this->maxValue = other.maxValue;

    this->matrix = this->createMatrix( this->rows, this->cols );

    for ( std::size_t i = 0 ; i < this->rows ; ++ i ) {
        for ( std::size_t j = 0 ; j < this->cols ; ++ j ) {
            this->value( i, j ) = other.value( i, j );
        }
    }
}
unsigned int** ColoredImageMatrix::createMatrix( std::size_t r, std::size_t c ) {
    unsigned int** ptrToMatrix = new unsigned int*[ r ];
    
    for ( std::size_t i = 0 ; i < r ; ++ i ) {
        ptrToMatrix[ i ] = new unsigned int[ c ];
        this->initialize( ptrToMatrix[ i ] );
    }
    return ptrToMatrix;
}
void ColoredImageMatrix::initialize( unsigned int* arr ) {
    for ( std::size_t i = 0 ; i < this->cols ; ++ i ) {
        arr[ i ] = this->INIT_VALUE;
    }
}

const unsigned int& ColoredImageMatrix::value( std::size_t row, std::size_t col ) const {
    assert( row < this->rows && col < this->cols );//exception

    return this->matrix[ row ][ col ];
}
unsigned int& ColoredImageMatrix::value( std::size_t row, std::size_t col ) {
    assert( row < this->rows && col < this->cols );//exception 

    return this->matrix[ row ][ col ];
}

void ColoredImageMatrix::rotateLeft() {
    ColoredImageMatrix rotated( this->cols, this->rows, this->maxValue );
    std::size_t tempRow = 0, tempCol = 0;

    for ( int i = cols - 1 ; i >= 0 ; -- i ) {
        for ( std::size_t j = 0 ; j < rows ; ++ j ) {
            rotated.value( tempRow, tempCol ) = this->value( j, ( std::size_t )i );
            ++ tempCol;
        }
        ++ tempRow;
        tempCol = 0;
    }
    
    *this = rotated;
}
void ColoredImageMatrix::rotateRight() {
    ColoredImageMatrix rotated( this->cols, this->rows, this->maxValue );
    std::size_t tempRow = 0, tempCol = 0;

    for ( std::size_t i = 0 ; i < cols ; ++ i ) {
        for ( int j = rows - 1 ; j >= 0 ; -- j ) {
            rotated.value( tempRow, tempCol ) = this->value( (std::size_t)j, i );
            ++ tempCol;
        }
        ++ tempRow; tempCol = 0;
    }
    
    *this = rotated;
}
void ColoredImageMatrix::invertColor() {
    for ( std::size_t i = 0 ; i < this->rows ; ++ i ) {
        for ( std::size_t j = 0 ; j < this->cols ; ++ j ) {
            this->value( i, j ) = this->maxValue - this->value( i, j );
        }
    }
}

std::size_t ColoredImageMatrix::getRows() const {
    return this->rows;
}
std::size_t ColoredImageMatrix::getCols() const {
    return this->cols;
}
unsigned int ColoredImageMatrix::getMaxValue() const {
    return this->maxValue;
}

ColoredImageMatrix& ColoredImageMatrix::mergeHorizontally( const ColoredImageMatrix& other ) {
assert( this->rows == other.rows && this->maxValue == other.maxValue );

    ColoredImageMatrix merged( this->rows, this->cols + other.cols, this->maxValue );

    for ( std::size_t i = 0 ; i < this->rows ; ++ i ) {
        for ( std::size_t j = 0 ; j < this->cols ; ++ j ) {
            merged.value( i, j ) = this->value( i, j );
        }
    }
    for ( std::size_t i = 0 ; i < other.rows ; ++ i ) {
        for ( std::size_t j = 0 ; j < other.cols ; ++ j ) {
            merged.value( i, j + this->cols ) = other.value( i, j );
        } 
    }

    *this = merged;

    return *this;
}
ColoredImageMatrix& ColoredImageMatrix::mergeVertically( const ColoredImageMatrix& other ) {
    assert( this->cols == other.cols && this->maxValue == other.maxValue );

    ColoredImageMatrix merged( this->rows + other.rows, this->cols, this->maxValue );

    for ( std::size_t i = 0 ; i < this->rows ; ++ i ) {
        for ( std::size_t j = 0 ; j < this->cols ; ++ j ) {
            merged.value( i, j ) = this->value( i, j );
        }
    }
    for ( std::size_t i = 0 ; i < other.rows ; ++ i ) {
        for ( std::size_t j = 0 ; j < other.cols ; ++ j ) {
            merged.value( i + this->rows, j ) = other.value( i, j );
        } 
    }
    *this = merged;

    return *this;
}