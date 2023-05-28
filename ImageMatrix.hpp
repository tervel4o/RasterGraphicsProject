#ifndef IMAGEMATRIX_HPP
#define IMAGEMATRIX_HPP

#include <cstdio>
#include <fstream>
#include <iostream>

class ImageMatrix {
    public:
        ImageMatrix();
        ImageMatrix( std::size_t _rows, std::size_t _cols );
        ImageMatrix( const ImageMatrix& other );
        ~ImageMatrix();

        ImageMatrix& operator=( const ImageMatrix& other );
        bool operator==( const ImageMatrix& other );

        void serialize( std::ostream& out ) const;
        void deserialize( std::istream& in );

        void rotateLeft();
        void rotateRight();
        void invertColor();

        unsigned int& value( std::size_t row, std::size_t col );
        const unsigned int& value( std::size_t row, std::size_t col ) const;

        std::size_t getRows() const;
        std::size_t getCols() const;

        ImageMatrix& mergeHorizontally( const ImageMatrix& other );
        ImageMatrix& mergeVertically( const ImageMatrix& other );

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
        void copy( const ImageMatrix& other );

        unsigned int** createMatrix( std::size_t r, std::size_t c );
        void initialize( unsigned int* arr );

    private:    
        unsigned int** matrix;
        std::size_t rows, cols;
        static unsigned int INIT_VALUE;
};

#endif