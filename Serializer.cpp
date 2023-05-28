#include "Serializer.hpp"

Serializer::Serializer( std::ostream& _out )
    : out( _out ) {}

void Serializer::printCommentars( const std::vector<std::string>& commentars ) const {
    for ( std::string comment : commentars ) {
        this->out << comment << '\n';
    }
}

void Serializer::visit( ImagePBM* imagePBM ) const {
    this->out << imagePBM->getImageHeader() << '\n';
    
    printCommentars( imagePBM->Image::getCommentars() );

    imagePBM->getImageMatrix().serialize( this->out );
}
void Serializer::visit( ImagePGM* imagePGM ) const {
    this->out << imagePGM->getImageHeader() << '\n';

    printCommentars( imagePGM->Image::getCommentars() );

    imagePGM->getImageMatrix().serialize( this->out );
}
void Serializer::visit( ImagePPM* imagePPM ) const {
    this->out << imagePPM->getImageHeader() << '\n';

    printCommentars( imagePPM->Image::getCommentars() );

    std::size_t rows = imagePPM->getImageMatrixRed().getRows(),
                cols = imagePPM->getImageMatrixRed().getCols();
    unsigned int maxValue = imagePPM->getImageMatrixRed().getMaxValue();
    this->out << cols << ' ' << rows << '\n';
    this->out << maxValue << '\n';

    for ( std::size_t i = 0 ; i < rows ; ++ i ) {
        for ( std::size_t j = 0 ; j < cols ; ++ j ) {
            this->out << imagePPM->getImageMatrixRed().value( i, j ) << ' '
                      << imagePPM->getImageMatrixGreen().value( i, j ) << ' '
                      << imagePPM->getImageMatrixBlue().value( i, j ) << '\n';
        }
    }
}