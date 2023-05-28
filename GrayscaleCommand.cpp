#include "GrayscaleCommand.hpp"
#include "Grayscaler.hpp"

GrayscaleCommand::GrayscaleCommand( Sessions& _sessions ) 
    : sessions( _sessions ) {}
void GrayscaleCommand::interpret( std::istream& ) {
    Grayscaler grayscaler;
    this->sessions.getActiveSession().addOperation(&grayscaler);
}