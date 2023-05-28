#include "SwitchCommand.hpp"

SwitchCommand::SwitchCommand( Sessions& _sessions )
    : sessions( _sessions ) {}

void SwitchCommand::interpret( std::istream& in ) {
    std::size_t newActiveSession;
    in >> newActiveSession;

    this->sessions.switchActiveSession( newActiveSession );

    std::cout << "Switched to session with ID " << this->sessions.getActiveSessionIndex() << '\n';
    this->sessions.getActiveSession().printSessionInfo();
    std::cout << '\n';
}