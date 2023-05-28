#include "ImagePGM.hpp"

std::string ImagePGM::imageHeader = "P2";

ImagePGM::ImagePGM() 
    : Image::Image(), imageMatrix( ColoredImageMatrix() ) {}
ImagePGM::ImagePGM( const std::string& _imageName )
    : Image::Image( _imageName ) ,
    imageMatrix( ColoredImageMatrix() ) {}
ImagePGM::ImagePGM( const std::string& _imageName,
                  std::size_t _imageWidth, std::size_t _imageHeight,
                  unsigned char _maxValue )
    : Image::Image( _imageName ), imageMatrix( _imageHeight, _imageWidth, _maxValue ) {}
ImagePGM::ImagePGM( const std::string& _imageName,
                    const ColoredImageMatrix& _imageMatrix )
    : Image::Image( _imageName ), imageMatrix( _imageMatrix ) {}

bool ImagePGM::operator==( const ImagePGM& other ) {
    return this->getImageMatrix() == other.getImageMatrix();
}

Image* ImagePGM::clone() const {
    return new ImagePGM( *this );
}
void ImagePGM::accept( ImageVisitor* imageVisitor ) {
    imageVisitor->visit( this );
}

const std::string& ImagePGM::getImageHeader() const {
    return this->imageHeader;
}
const ColoredImageMatrix& ImagePGM::getImageMatrix() const {
    return this->imageMatrix;
}
ColoredImageMatrix& ImagePGM::getImageMatrix() {
    return this->imageMatrix;
}