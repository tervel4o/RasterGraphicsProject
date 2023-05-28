#ifndef SESSIONINFOCOMMAND_HPP
#define SESSIONINFOCOMMAND_HPP

#include "Command.hpp"
#include "Sessions.hpp"
#include "Session.hpp"

class SessionInfoCommand : public Command {
    public:
        SessionInfoCommand( Sessions& _sessions );
        void interpret( std::istream& );
        
    private:
        Sessions& sessions;
};

#endif