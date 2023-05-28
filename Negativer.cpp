#include "Negativer.hpp"

void Negativer::visit( ImagePBM* imagePBM ) const {
    imagePBM->getImageMatrix().invertColor();
}
void Negativer::visit( ImagePGM* imagePGM ) const {
    imagePGM->getImageMatrix().invertColor();
}
void Negativer::visit( ImagePPM* imagePPM ) const {
    imagePPM->getImageMatrixRed().invertColor();
    imagePPM->getImageMatrixGreen().invertColor();
    imagePPM->getImageMatrixBlue().invertColor();
}

ImageOperation* Negativer::clone() {
    return new Negativer( *this );
}
void Negativer::print() const {
    std::cout << "negative";
}