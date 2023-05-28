#include "HorizontalCollager.hpp"
#include "Serializer.hpp"

HorizontalCollager::HorizontalCollager()
    : toCollageWith( nullptr ) , collagedName( "" ) {}
HorizontalCollager::HorizontalCollager( Image* _toCollageWith, const std::string& _collagedName )
    : toCollageWith( _toCollageWith->clone() ), collagedName( _collagedName ) {}
HorizontalCollager::HorizontalCollager( const HorizontalCollager& other ) {
    this->copy( other );
}
HorizontalCollager::~HorizontalCollager() {
    this->destroy();
}

HorizontalCollager& HorizontalCollager::operator= ( const HorizontalCollager& other ) {
    if ( this != &other ) {
        this->destroy();
        this->copy( other );
    }

    return *this;
}
        
void HorizontalCollager::visit( ImagePBM* imagePBM ) const {
    ImagePBM* ptrToImage = dynamic_cast<ImagePBM*>( this->toCollageWith );

    imagePBM->getImageMatrix().mergeHorizontally( ptrToImage->getImageMatrix() );

    std::ofstream outs( this->collagedName );
    Serializer s( outs );
    imagePBM->accept( &s );

    outs.close();
}
void HorizontalCollager::visit( ImagePGM* imagePGM ) const {
    ImagePGM* ptrToImage = dynamic_cast<ImagePGM*>( this->toCollageWith );

    imagePGM->getImageMatrix().mergeHorizontally( ptrToImage->getImageMatrix() );

    std::ofstream outs( this->collagedName );
    Serializer s( outs );
    imagePGM->accept( &s );

    outs.close();
}
void HorizontalCollager::visit( ImagePPM* imagePPM ) const {
    ImagePPM* ptrToImage = dynamic_cast<ImagePPM*>( this->toCollageWith );

    imagePPM->getImageMatrixRed().mergeHorizontally( ptrToImage->getImageMatrixRed() );
    imagePPM->getImageMatrixGreen().mergeHorizontally( ptrToImage->getImageMatrixGreen() );
    imagePPM->getImageMatrixBlue().mergeHorizontally( ptrToImage->getImageMatrixBlue() );

    std::ofstream outs( this->collagedName );
    Serializer s( outs );
    imagePPM->accept( &s );

    outs.close();
}

ImageOperation* HorizontalCollager::clone() {
    return new HorizontalCollager( *this );
}

void HorizontalCollager::copy( const HorizontalCollager& other ) {
    this->toCollageWith = other.toCollageWith->clone();
    this->collagedName = other.collagedName;
}
void HorizontalCollager::destroy() {
    delete this->toCollageWith;
}
void HorizontalCollager::print() const {
    std::cout << "collage horizontal";
}
void HorizontalCollager::setToCollageWith( const Image*& _toCollageWith ) {
    this->toCollageWith = _toCollageWith->clone();
}
void HorizontalCollager::setCollagedName( const std::string& _collagedName ) {
    this->collagedName = _collagedName;
}