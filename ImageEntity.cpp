#include "ImageEntity.hpp"

ImageEntity::ImageEntity::ImageEntity( Image* _image )
    : image( _image->clone() ), operations() {}
ImageEntity::ImageEntity( const ImageEntity& other ) {
    this->copy( other );
}
ImageEntity::~ImageEntity() {
    this->destroy();
}

ImageEntity& ImageEntity::operator=( const ImageEntity& other ) {
    if ( this != &other ) {
        this->destroy();
        this->copy( other );
    }

    return *this;
}

bool ImageEntity::notEmpty() const {
    return this->operations.size() > 0;
}

void ImageEntity::addOperation( ImageOperation* newOperation ) {
    this->operations.push_back( newOperation->clone() );
}
void ImageEntity::removeLastOperation() {
    if ( this->notEmpty() ) {
        this->operations.pop_back();
    }
    
}

void ImageEntity::applyOperations() {
    if ( this->notEmpty() ) {
        for ( ImageOperation* imageOperation : this->operations ) {
            this->image->accept( imageOperation );
        }
    }
}
void ImageEntity::serialize( Serializer& serializer ) {
    this->image->accept( &serializer );
}

void ImageEntity::copy( const ImageEntity& other ) {
    this->image = other.image->clone();
    for ( ImageOperation* imageOperation : other.operations ) {
        this->operations.push_back( imageOperation->clone() );
    }
}
void ImageEntity::destroy() {
    delete this->image;
    for ( ImageOperation* imageOperation : this->operations ) {
        delete imageOperation;
    }
}

void ImageEntity::print() const {
    std::cout << this->image->getName() << " with pending transformations:";

    for ( ImageOperation* imageOperation : this->operations ) {
        std::cout << ' ';
        imageOperation->print();
        std::cout << '\n';
    }
    std::cout << '\n';
}

const Image* ImageEntity::getImage() const {
    return this->image;
}
Image* ImageEntity::getImage() {
    return this->image;
}