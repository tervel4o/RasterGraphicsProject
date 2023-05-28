#include "SaveAsCommand.hpp"
#include "Serializer.hpp"

SaveAsCommand::SaveAsCommand( Sessions& _sessions )
    : sessions( _sessions ) {}

void SaveAsCommand::interpret( std::istream& in ) {
    std::string newImageName;
    in >> newImageName; 
    
    this->sessions.getActiveSession().saveAs(newImageName);
}