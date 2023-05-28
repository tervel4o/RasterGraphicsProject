#ifndef COLOREDIMAGEMATRIX_HPP
#define COLOREDIMAGEMATRIX_HPP

#include <cstdio>
#include <fstream>
#include <iostream>

class ColoredImageMatrix {
    public:
        ColoredImageMatrix();
        ColoredImageMatrix( std::size_t _rows, std::size_t _cols,
                            const unsigned char _maxValue );
        ColoredImageMatrix( const ColoredImageMatrix& other );
        ~ColoredImageMatrix();

        ColoredImageMatrix& operator=( const ColoredImageMatrix& other );
        bool operator==( const ColoredImageMatrix& other );

        void serialize( std::ostream& out ) const;
        void deserialize( std::istream& in );

        void rotateLeft();
        void rotateRight();
        void invertColor();

        unsigned int& value( std::size_t row, std::size_t col );
        const unsigned int& value( std::size_t row, std::size_t col ) const;

        std::size_t getRows() const;
        std::size_t getCols() const;
        unsigned int getMaxValue() const;

        ColoredImageMatrix& mergeHorizontally( const ColoredImageMatrix& other );
        ColoredImageMatrix& mergeVertically( const ColoredImageMatrix& other );

        void printMatrix() const {
            for ( std::size_t i = 0 ; i < this->rows ; ++ i ) {
                for ( std::size_t j = 0 ; j < this->cols ; ++ j ) {
                    std::cout << this->value( i , j ) << ' ';
                }
                std::cout << '\n';
            }
        }

    private:

        void destroy();
        void copy( const ColoredImageMatrix& other );

        unsigned int** createMatrix( std::size_t r, std::size_t c );
        void initialize( unsigned int* arr );

    private:    
        unsigned int** matrix;
        unsigned int maxValue;
        std::size_t rows, cols;
        static unsigned int INIT_VALUE;
};

#endif