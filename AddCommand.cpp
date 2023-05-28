#include "AddCommand.hpp"
#include "Deserializer.hpp"
#include "Image.hpp"
//#include "Factory.hpp"

Image* factory2(const std::string& type) {
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

AddCommand::AddCommand( Sessions& _sessions )
    : sessions( _sessions ) {}
void AddCommand::interpret( std::istream& in ) {
    std::string newImageName;
    in >> newImageName;
    try {
        Deserializer des( newImageName );
        
        Image* newImage = factory2( newImageName.substr( newImageName.find( '.' ) , newImageName.size() - newImageName.find( '.' ) ) );
        if ( newImage != nullptr ) {
            newImage->accept( &des );
            ImageEntity newImageEntity( newImage );
            this->sessions.getActiveSession().addEntity(newImageEntity);

            std::cout << "Image " << newImageName << " added\n\n";
        }
    }
    catch (std::runtime_error) {
        std::cout << "The application does not operate with images from this type\n";
    }
}