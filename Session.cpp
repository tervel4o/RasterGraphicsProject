#include <iostream>
#include "Session.hpp"
#include "Serializer.hpp"

Session::Session()
    : entities() {}
Session::Session( const ImageEntity& element )
    : entities() {
    this->addEntity( element );
}

Session& Session::addEntity( const ImageEntity& newElement ) {
    this->entities.push_back( newElement );
    
    return *this;
}
void Session::printSessionInfo() const {
    std::cout << "Name of images in the session:" << '\n';
    
    for ( const ImageEntity& imageEntity : this->entities ) {
        imageEntity.print();
    }
}
void Session::undo() {
    if ( this->entities.size() == 0 ) {
        return;
    }

    for ( ImageEntity& imageEntity : this->entities ) {
        if ( imageEntity.notEmpty() ) {
            imageEntity.removeLastOperation();
        }
    }
}
void Session::saveChanges() {
    for ( ImageEntity& imageEntity : this->entities ) {
        imageEntity.applyOperations();
        std::ofstream outs( imageEntity.getImage()->getName() );
        Serializer s( outs );

        imageEntity.serialize( s );
        outs.close();
    }
}
void Session::saveAs( const std::string& newImageName ) {
    ImageEntity firstEntity = this->entities[ 0 ];
    firstEntity.applyOperations();

    std::ofstream out( newImageName );
    
    Serializer s( out );
    firstEntity.serialize( s );
    
    out.close();
}
void Session::addOperation( ImageOperation* imageOperation ) {
    for ( ImageEntity& imageEntity : this->entities ) {
        imageEntity.addOperation( imageOperation );
    }
}

std::vector<ImageEntity>& Session::getEntitties() {
    return this->entities;
}
ImageEntity& Session::getImageEntity( const std::string& name ) {
    for ( std::size_t i = 0 ; i < this->entities.size() ; ++ i ) {
        if ( this->entities[ i ].getImage()->getName() == name ) {
            return this->entities[ i ];
        }
    }
    throw std::runtime_error( "Image with this name does not exist!" );
}