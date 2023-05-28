#include "RightRotator.hpp"

void RightRotator::visit( ImagePBM* imagePBM ) const {
    imagePBM->getImageMatrix().rotateRight();
}
void RightRotator::visit( ImagePGM* imagePGM ) const {
    imagePGM->getImageMatrix().rotateRight();
}
void RightRotator::visit( ImagePPM* imagePPM ) const {
    imagePPM->getImageMatrixRed().rotateRight();
    imagePPM->getImageMatrixGreen().rotateRight();
    imagePPM->getImageMatrixBlue().rotateRight();
}

ImageOperation* RightRotator::clone() {
    return new RightRotator( *this );
}
void RightRotator::print() const {
    std::cout << "rotate right";
}