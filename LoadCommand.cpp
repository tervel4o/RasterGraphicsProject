#include <sstream>
#include <iostream>

#include "LoadCommand.hpp"
#include "Deserializer.hpp"
#include "ImageEntity.hpp"
#include "Session.hpp"
#include "Image.hpp"
#include "ImagePBM.hpp"
#include "ImagePGM.hpp"
#include "ImagePPM.hpp"

//#include "Factory.hpp"

Image* factory(const std::string& type) {
    if ( type == ".pbm" ) {
        return new ImagePBM();
    }
    else if ( type == ".pgm" ) {
        return new ImagePGM();
    }
    else if ( type == ".ppm" ) {
        return new ImagePPM();
    }

    return nullptr;
}

LoadCommand::LoadCommand( Sessions& _sessions )
    : sessions( _sessions ) {}

void LoadCommand::interpret( std::istream& in ) {
    Session newSession;
    in.get();
    std::string line, newImageName;
    std::getline( in, line );

    std::stringstream lineS( line );

    try {
        while( std::getline( lineS, newImageName, ' ' ) ) {
            Deserializer des( newImageName );

            Image* newImage = factory( newImageName.substr( newImageName.find( '.' ) , newImageName.size() - newImageName.find( '.' ) ) );
            if ( newImage != nullptr ) {
                newImage->accept( &des );
                ImageEntity newImageEntity( newImage );
                newSession.addEntity( newImageEntity );

                std::cout << "Image " << newImageName << " added\n";
            }
        }

        this->sessions.loadNewSession( newSession );
        std::cout << "Session with ID " << this->sessions.getActiveSessionIndex() << " started\n\n";
    }
    catch(std::exception& exception) {
        std::cout << exception.what() << '\n';
    }
}