#include <cassert>
#include <iostream>
#include "ImageMatrix.hpp"

unsigned int ImageMatrix::INIT_VALUE = 0;
ImageMatrix::ImageMatrix()
    : matrix( nullptr ), rows( 0 ), cols( 0 ) {}
ImageMatrix::ImageMatrix( std::size_t _rows, std::size_t _cols ) {
    this->rows = _rows;
    this->cols = _cols;

    this->matrix = this->createMatrix( this->rows, this->cols );

}
ImageMatrix::ImageMatrix( const ImageMatrix& other ) {
    this->copy( other );
}
ImageMatrix::~ImageMatrix() {
    this->destroy();
}

ImageMatrix& ImageMatrix::operator=( const ImageMatrix& other ) {
    if ( this != &other ) {
        this->destroy();
        this->copy( other );
    }

    return *this;
}

bool ImageMatrix::operator==( const ImageMatrix& other ) {
    if ( this->rows != other.rows || this->cols != other.cols ) {
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

void ImageMatrix::serialize( std::ostream& out ) const {
    out << this->cols << ' ' << this->rows << '\n';

    for ( std::size_t i = 0 ; i < this->rows ; ++ i ) {
        for ( std::size_t j = 0 ; j < this->cols - 1 ; ++ j ) {
            out << this->value( i, j ) << ' '; 
        }
        out << this->value( i, this->cols - 1 ) << '\n';
    }
}
void ImageMatrix::deserialize( std::istream& in ) {
    std::size_t rows, cols;
    in >> cols >> rows;

    *this = ImageMatrix( rows, cols );

    for ( std::size_t i = 0 ; i < this->rows ; ++ i ) {
        for ( std::size_t j = 0 ; j < this->cols ; ++ j ) {
            unsigned int c;
            in >> c;
            
            if ( c != 1 && c != 0 ) {
                c = 0; // default value to not terminate the programm
            }
            this->value( i, j ) = c;
        }
    }
}

void ImageMatrix::destroy() {
    for ( std::size_t i = 0 ; i < this->rows ; ++ i ) {
        delete[] this->matrix[ i ];
    }
    delete[] this->matrix;
}
void ImageMatrix::copy( const ImageMatrix& other ) {
    this->rows = other.rows;
    this->cols = other.cols;

    this->matrix = this->createMatrix( this->rows, this->cols );

    for ( std::size_t i = 0 ; i < this->rows ; ++ i ) {
        for ( std::size_t j = 0 ; j < this->cols ; ++ j ) {
            this->value( i, j ) = other.value( i, j );
        }
    }
}
unsigned int** ImageMatrix::createMatrix( std::size_t r, std::size_t c ) {
    unsigned int** ptrToMatrix = new unsigned int*[ r ];
    
    for ( std::size_t i = 0 ; i < r ; ++ i ) {
        ptrToMatrix[ i ] = new unsigned int[ c ];
        this->initialize( ptrToMatrix[ i ] );
    }
    return ptrToMatrix;
}
void ImageMatrix::initialize( unsigned int* arr ) {
    for ( std::size_t i = 0 ; i < this->cols ; ++ i ) {
        arr[ i ] = this->INIT_VALUE;
    }
}

const unsigned int& ImageMatrix::value( std::size_t row, std::size_t col ) const {
    assert( row < this->rows && col < this->cols );

    return this->matrix[ row ][ col ];
}
unsigned int& ImageMatrix::value( std::size_t row, std::size_t col ) {
    assert( row < this->rows && col < this->cols ); 

    return this->matrix[ row ][ col ];
}

void ImageMatrix::rotateLeft() {
    ImageMatrix rotated( this->cols, this->rows );
    std::size_t tempRow = 0, tempCol = 0;

    for ( int i = cols - 1 ; i >= 0 ; -- i ) {
        for ( std::size_t j = 0 ; j < rows ; ++ j ) {
            rotated.value( tempRow, tempCol ) = this->value( j, (std::size_t)i );
            ++ tempCol;
        }
        ++ tempRow;
        tempCol = 0;
    }
    
    *this = rotated;
}
void ImageMatrix::rotateRight() {
    ImageMatrix rotated( this->cols, this->rows );
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
void ImageMatrix::invertColor() {
    const unsigned char maxValue = 1;

    for ( std::size_t i = 0 ; i < this->rows ; ++ i ) {
        for ( std::size_t j = 0 ; j < this->cols ; ++ j ) {
            this->value( i, j ) = maxValue - this->value( i, j );
        }
    }
}


std::size_t ImageMatrix::getRows() const {
    return this->rows;
}
std::size_t ImageMatrix::getCols() const {
    return this->cols;
}

ImageMatrix& ImageMatrix::mergeHorizontally( const ImageMatrix& other ) {
    if ( this->rows != other.rows ) {
        std::cout << "Can not collage horizontally images with different number of rows.\n";

        return *this;
    }

    ImageMatrix merged( this->rows, this->cols + other.cols );

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
ImageMatrix& ImageMatrix::mergeVertically( const ImageMatrix& other ) {
    if ( this->cols != other.cols ) {
        std::cout << "Can not collage vertically images with different number of columns.\n";
        
        return *this;
    }

    ImageMatrix merged( this->rows + other.rows, this->cols );

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