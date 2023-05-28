#include "ImagePPM.hpp"

std::string ImagePPM::imageHeader = "P3";
ImagePPM::ImagePPM()
    : Image::Image(), imageMatrixRed( ColoredImageMatrix() ),
      imageMatrixGreen( ColoredImageMatrix() ), imageMatrixBlue( ColoredImageMatrix() ) {}
ImagePPM::ImagePPM( const std::string& _imageName )
    : Image::Image( _imageName ) , imageMatrixRed( ColoredImageMatrix() ) ,
    imageMatrixGreen( ColoredImageMatrix() ) , imageMatrixBlue( ColoredImageMatrix() ) {}
ImagePPM::ImagePPM( const std::string& _imageName,
                  std::size_t _imageWidth, std::size_t _imageHeight,
                  unsigned char _maxValue ) 
    : Image::Image( _imageName ), imageMatrixRed( ColoredImageMatrix( _imageHeight, _imageWidth, _maxValue ) ),
      imageMatrixGreen( ColoredImageMatrix( _imageHeight, _imageWidth, _maxValue ) ),
      imageMatrixBlue( ColoredImageMatrix( _imageHeight, _imageWidth, _maxValue ) ) {}
ImagePPM::ImagePPM( const std::string& _imageName,
                  const ColoredImageMatrix& _imageMatrixRed,
                  const ColoredImageMatrix& _imageMatrixGreen,
                  const ColoredImageMatrix& _imageMatrixBlue )
    : Image::Image( _imageName ), imageMatrixRed( _imageMatrixRed ),
      imageMatrixGreen( _imageMatrixGreen ),
      imageMatrixBlue( _imageMatrixBlue ) {}

bool ImagePPM::operator==( const ImagePPM& other ) {
    return this->getImageMatrixRed() == other.getImageMatrixRed()
        && this->getImageMatrixGreen() == other.getImageMatrixGreen()
        && this->getImageMatrixBlue() == other.getImageMatrixBlue();
}

Image* ImagePPM::clone() const {
    return new ImagePPM( *this );
}
void ImagePPM::accept( ImageVisitor* imageVisitor ) {
    imageVisitor->visit( this );
}

const std::string& ImagePPM::getImageHeader() const {
    return this->imageHeader;
}
const ColoredImageMatrix& ImagePPM::getImageMatrixRed() const {
    return this->imageMatrixRed;
}
ColoredImageMatrix& ImagePPM::getImageMatrixRed() {
    return this->imageMatrixRed;
}
const ColoredImageMatrix& ImagePPM::getImageMatrixGreen() const {
    return this->imageMatrixGreen;
}
ColoredImageMatrix& ImagePPM::getImageMatrixGreen() {
    return this->imageMatrixGreen;
}
const ColoredImageMatrix& ImagePPM::getImageMatrixBlue() const {
    return this->imageMatrixBlue;
}
ColoredImageMatrix& ImagePPM::getImageMatrixBlue() {
    return this->imageMatrixBlue;
}