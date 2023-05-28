#include <cassert>
#include "Deserializer.hpp"

Deserializer::Deserializer( const std::string& _fileName )
    : fileName(_fileName ) {}

void Deserializer::readCommentars( std::vector<std::string>& commentars, std::ifstream& ifs ) const {
    std::string comment;

    while( ifs.peek() == '#' ) {
        std::getline( ifs, comment );
        commentars.push_back( comment );
    }
}
 
void Deserializer::visit( ImagePBM* imagePBM ) const {
    std::ifstream ifs( this->fileName, std::ios::in );
    std::string header;
    ifs >> header;
    assert( header == "P1" );

    std::vector<std::string> commentars;
    this->readCommentars( commentars, ifs );

    ImageMatrix imageMatrix;
    imageMatrix.deserialize( ifs );
    
    imagePBM->Image::setName( this->fileName );
    *imagePBM = ImagePBM( imagePBM->Image::getName(), imageMatrix );
    imagePBM->Image::getCommentars() = commentars;

    ifs.close();
}
void Deserializer::visit(ImagePGM* imagePGM) const {
    std::ifstream ifs( this->fileName, std::ios::in );
    std::string header;
    ifs >> header;
    assert( header == "P2" );

    std::vector<std::string> commentars;
    this->readCommentars( commentars, ifs );

    ColoredImageMatrix imageMatrix;
    imageMatrix.deserialize( ifs );
    
    imagePGM->Image::setName( this->fileName );
    *imagePGM = ImagePGM( imagePGM->Image::getName(), imageMatrix );
    imagePGM->Image::getCommentars() = commentars;

    ifs.close();
}
void Deserializer::visit( ImagePPM* imagePPM ) const {
    std::ifstream ifs( this->fileName , std::ios::in );
    std::string header;
    ifs >> header;
    assert( header == "P3" );

    std::vector<std::string> commentars;
    this->readCommentars( commentars, ifs );

    std::size_t imageWidth, imageHeight;
    ifs >> imageWidth >> imageHeight;

    unsigned int maxValue;
    ifs >> maxValue;

    ColoredImageMatrix imageMatrixRed( imageHeight, imageWidth, maxValue ),
                       imageMatrixGreen( imageHeight, imageWidth, maxValue ),
                       imageMatrixBlue( imageHeight, imageWidth, maxValue );

    for ( std::size_t i = 0 ; i < imageHeight ; ++ i ) {
        for ( std::size_t j = 0 ; j < imageWidth ; ++ j ) {
            unsigned int redValue , greenValue , blueValue;
            ifs >> redValue >> greenValue >> blueValue;

            if ( redValue > maxValue ) {
                redValue = 0;
            }
            if ( greenValue > maxValue ) {
                greenValue = 0;
            }
            if ( blueValue > maxValue ) {
                blueValue = 0;
            }
            imageMatrixRed.value( i , j ) = redValue;
            imageMatrixGreen.value( i , j ) = greenValue;
            imageMatrixBlue.value( i , j ) = blueValue;
        }
    }
    imagePPM->Image::setName( this->fileName );
    *imagePPM = ImagePPM( imagePPM->Image::getName(), imageMatrixRed,
                          imageMatrixGreen, imageMatrixBlue );
    imagePPM->Image::getCommentars() = commentars;

    ifs.close();
}