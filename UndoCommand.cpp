#include "UndoCommand.hpp"

UndoCommand::UndoCommand( Sessions& _sessions )
    : sessions( _sessions ) {}

void UndoCommand::interpret( std::istream& ) {
    this->sessions.getActiveSession().undo();
}