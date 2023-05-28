#include "NegativeCommand.hpp"
#include "Negativer.hpp"

NegativeCommand::NegativeCommand( Sessions& _sessions ) 
    : sessions( _sessions ) {}

void NegativeCommand::interpret( std::istream& ) {
    Negativer negativer;
    this->sessions.getActiveSession().addOperation( &negativer );
}