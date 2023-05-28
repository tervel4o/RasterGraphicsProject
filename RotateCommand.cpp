#include "RotateCommand.hpp"
#include "RightRotator.hpp"
#include "LeftRotator.hpp"

RotateCommand::RotateCommand( Sessions& _sessions )
    : sessions( _sessions ) {
    RightRotator* rightRotator = new RightRotator();
    LeftRotator* leftRotator = new LeftRotator();
    rotations.push_back( std::make_pair( "left", leftRotator ) );
    rotations.push_back( std::make_pair( "right", rightRotator ) );
}

RotateCommand::~RotateCommand() {
    for ( std::pair<std::string, ImageOperation*>& rot : this->rotations ) {
        delete rot.second;
    }
}

void RotateCommand::interpret( std::istream& in ) {
    std::string direction;
    in >> direction;

    for ( std::size_t i = 0 ; i < this->rotations.size() ; ++ i ) {
        if ( direction == this->rotations[ i ].first ) {
            this->sessions.getActiveSession().addOperation(this->rotations[i].second);
        }
    }
}