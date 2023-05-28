#include "Monochromer.hpp"

void Monochromer::visit( ImagePBM* ) const {
    return;
}
void Monochromer::visit( ImagePGM* imagePGM ) const {
    std::size_t rows = imagePGM->getImageMatrix().getRows(),
                cols = imagePGM->getImageMatrix().getCols();
    unsigned int maxValue = imagePGM->getImageMatrix().getMaxValue();

    for ( std::size_t i = 0 ; i < rows ; ++ i ) {
        for ( std::size_t j = 0 ; j < cols ; ++ j ) {
            unsigned int* value = & ( imagePGM->getImageMatrix().value( i, j ) );

            if ( *value <= maxValue / 2 ) {
                *value = 0;
            }
            else {
                *value = maxValue;
            }
        }
    }
}
void Monochromer::visit( ImagePPM* imagePPM ) const {
    std::size_t rows = imagePPM->getImageMatrixRed().getRows(),
                cols = imagePPM->getImageMatrixRed().getCols();
    unsigned int maxValue = imagePPM->getImageMatrixRed().getMaxValue();

    for ( std::size_t i = 0 ; i < rows ; ++ i ) {
        for ( std::size_t j = 0 ; j < cols ; ++ j ) {
            unsigned int* colorRed = & ( imagePPM->getImageMatrixRed().value( i, j ) );
            unsigned int* colorGreen = & ( imagePPM->getImageMatrixGreen().value( i, j ) );
            unsigned int* colorBlue = &( imagePPM->getImageMatrixBlue().value( i, j ) );

        if ( *colorRed + *colorGreen + *colorBlue <= ( ( 3 * maxValue ) / 2 ) ) {
            *colorRed = 0;
            *colorGreen = 0;
            *colorBlue = 0;
        }
        else {
            *colorRed = maxValue;
            *colorGreen = maxValue;
            *colorBlue = maxValue;
        }
        }
    }
}

ImageOperation* Monochromer::clone() {
    return new Monochromer( *this );
}
void Monochromer::print() const {
    std::cout << "monochrome";
}