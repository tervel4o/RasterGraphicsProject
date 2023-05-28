#include "CollageVerticalCommand.hpp"
#include "VerticalCollager.hpp"

CollageVerticalCommand::CollageVerticalCommand( Sessions& _sessions )
    : sessions( _sessions ) {}

void CollageVerticalCommand::interpret( std::istream& in ) {
    std::string imageName1, imageName2, collaged;
    in >> imageName1 >> imageName2 >> collaged;

    std::string suffix1 = imageName1.substr( imageName1.find( '.' ), imageName1.size() - imageName1.find( '.' ) ),
                suffix2 = imageName2.substr( imageName2.find( '.' ), imageName2.size() - imageName2.find( '.' ) ),
                suffixC = collaged.substr( collaged.find( '.' ), collaged.size() - collaged.find( '.' ) );
    
    if ( suffix1 == suffix2 && suffix1 == suffixC ) {
        VerticalCollager verticalCollager( this->sessions.getActiveSession().getImageEntity(imageName2).getImage() , collaged);
        this->sessions.getActiveSession().getImageEntity(imageName1).getImage()->accept(&verticalCollager);
    }
    else {
        std::cout << "Can not collage images from different types\n"; 
    }
    
}