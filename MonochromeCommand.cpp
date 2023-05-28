#include "MonochromeCommand.hpp"
#include "Monochromer.hpp"

MonochromeCommand::MonochromeCommand( Sessions& _sessions ) 
    : sessions( _sessions ) {}
void MonochromeCommand::interpret( std::istream& in ) {
    Monochromer monochromer;
    this->sessions.getActiveSession().addOperation( &monochromer );
}