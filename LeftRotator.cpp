#include "LeftRotator.hpp"

void LeftRotator::visit( ImagePBM* imagePBM ) const {
    imagePBM->getImageMatrix().rotateLeft();
}
void LeftRotator::visit( ImagePGM* imagePGM ) const {
    imagePGM->getImageMatrix().rotateLeft();
}
void LeftRotator::visit( ImagePPM* imagePPM ) const {
    imagePPM->getImageMatrixRed().rotateLeft();
    imagePPM->getImageMatrixGreen().rotateLeft();
    imagePPM->getImageMatrixBlue().rotateLeft();
}

ImageOperation* LeftRotator::clone() {
    return new LeftRotator( *this );
}
void LeftRotator::print() const {
    std::cout << "rotate left";
}