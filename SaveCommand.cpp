#include "SaveCommand.hpp"

SaveCommand::SaveCommand( Sessions& _sessions )
    : sessions( _sessions ) {}

void SaveCommand::interpret( std::istream& ) {
    this->sessions.getActiveSession().saveChanges();
}