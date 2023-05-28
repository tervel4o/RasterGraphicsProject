#include "ImagePBM.hpp"

std::string ImagePBM::imageHeader = "P1";

ImagePBM::ImagePBM()
    : Image::Image(),
      imageMatrix( ImageMatrix() ) {}
ImagePBM::ImagePBM( const std::string& _imageName )
    : Image::Image( _imageName ) ,
    imageMatrix( ImageMatrix() ) {}
ImagePBM::ImagePBM( const std::string& _imageName,
          std::size_t imageWidth, std::size_t imageHeight ) 
    : Image::Image( _imageName ),
      imageMatrix( ImageMatrix( imageHeight, imageWidth ) ) {}
ImagePBM::ImagePBM( const std::string& _imageName,
                    const ImageMatrix& _imageMatrix ) 
    : Image::Image( _imageName ),
      imageMatrix( _imageMatrix ) {}

bool ImagePBM::operator==( const ImagePBM& other ) {
    return this->getImageMatrix() == other.getImageMatrix();
}

Image* ImagePBM::clone() const {
    return new ImagePBM( *this );
}
void ImagePBM::accept( ImageVisitor* imageVisitor ) {
    imageVisitor->visit( this );
}

const ImageMatrix& ImagePBM::getImageMatrix() const {
    return this->imageMatrix;
}
ImageMatrix& ImagePBM::getImageMatrix() {
    return this->imageMatrix;
}
const std::string& ImagePBM::getImageHeader() const {
    return this->imageHeader;
}