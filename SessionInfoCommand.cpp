#include "SessionInfoCommand.hpp"

SessionInfoCommand::SessionInfoCommand( Sessions& _sessions )
    : sessions( _sessions ) {}

void SessionInfoCommand::interpret( std::istream& ) {
    this->sessions.getActiveSession().printSessionInfo();
}