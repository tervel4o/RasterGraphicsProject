#include "VerticalCollager.hpp"
#include "Serializer.hpp"

VerticalCollager::VerticalCollager()
    : toCollageWith( nullptr ) , collagedName( "" ) {}
VerticalCollager::VerticalCollager( Image* _toCollageWith, const std::string& _collagedName )
    : toCollageWith( _toCollageWith->clone() ), collagedName( _collagedName ) {}
VerticalCollager::VerticalCollager( const VerticalCollager& other ) {
    this->copy( other );
}
VerticalCollager::~VerticalCollager() {
    this->destroy();
}

VerticalCollager& VerticalCollager::operator=( const VerticalCollager& other ) {
    if ( this != &other ) {
        this->destroy();
        this->copy( other );
    }

    return *this;
}
        
void VerticalCollager::visit( ImagePBM* imagePBM ) const {
    ImagePBM* ptrToImage = dynamic_cast<ImagePBM*>( this->toCollageWith );

    imagePBM->getImageMatrix().mergeVertically( ptrToImage->getImageMatrix() );

    std::ofstream outs( this->collagedName );
    Serializer s( outs );
    imagePBM->accept( &s );

    outs.close();
}
void VerticalCollager::visit( ImagePGM* imagePGM ) const {
    ImagePGM* ptrToImage = dynamic_cast<ImagePGM*>( this->toCollageWith );

    imagePGM->getImageMatrix().mergeVertically( ptrToImage->getImageMatrix() );

    std::ofstream outs( this->collagedName );
    Serializer s( outs );
    imagePGM->accept( &s );

    outs.close();
}
void VerticalCollager::visit( ImagePPM* imagePPM ) const {
    ImagePPM* ptrToImage = dynamic_cast<ImagePPM*>( this->toCollageWith );

    imagePPM->getImageMatrixRed().mergeVertically( ptrToImage->getImageMatrixRed() );
    imagePPM->getImageMatrixGreen().mergeVertically( ptrToImage->getImageMatrixGreen() );
    imagePPM->getImageMatrixBlue().mergeVertically( ptrToImage->getImageMatrixBlue() );

    std::ofstream outs( this->collagedName );
    Serializer s( outs );
    imagePPM->accept( &s );

    outs.close();
}

ImageOperation* VerticalCollager::clone() {
    return new VerticalCollager( *this );
}

void VerticalCollager::copy( const VerticalCollager& other ) {
    this->toCollageWith = other.toCollageWith->clone();
    this->collagedName = other.collagedName;
}
void VerticalCollager::destroy() {
    delete this->toCollageWith;
}

void VerticalCollager::print() const {
    std::cout << "collage vertical";
}
void VerticalCollager::setToCollageWith( const Image*& _toCollageWith ) {
    this->toCollageWith = _toCollageWith->clone();
}
void VerticalCollager::setCollagedName( const std::string& _collagedName ) {
    this->collagedName = _collagedName;
}