#include "Grayscaler.hpp"

void Grayscaler::visit( ImagePBM* ) const {
    return;
}
void Grayscaler::visit( ImagePGM* ) const {
    return;
}
void Grayscaler::visit( ImagePPM* imagePPM ) const {
    std::size_t rows = imagePPM->getImageMatrixRed().getRows(),
                cols = imagePPM->getImageMatrixRed().getCols();
    const double redCoeff = 0.299, greenCoeff = 0.587, blueCoeff = 0.114;

    for ( std::size_t i = 0 ; i < rows ; ++ i ) {
        for ( std::size_t j = 0 ; j < cols ; ++ j ) {
            unsigned char grayscaledColor = ( unsigned char ) ( redCoeff * ( double )imagePPM->getImageMatrixRed().value( i, j )
                                                              + greenCoeff * ( double )imagePPM->getImageMatrixGreen().value( i, j )
                                                              + blueCoeff * ( double )imagePPM->getImageMatrixBlue().value( i, j ) );
            
            imagePPM->getImageMatrixRed().value( i, j ) = grayscaledColor;
            imagePPM->getImageMatrixGreen().value( i, j ) = grayscaledColor;
            imagePPM->getImageMatrixBlue().value( i, j ) = grayscaledColor;
        }
    }
}

ImageOperation* Grayscaler::clone() {
    return new Grayscaler( *this );
}
void Grayscaler::print() const {
    std::cout << "grayscale";
}