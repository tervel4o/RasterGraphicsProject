#ifndef NEGATIVECOMMAND_HPP
#define NEGATIVECOMMAND_HPP

#include "Command.hpp"
#include "Session.hpp"
#include "Sessions.hpp"

class NegativeCommand : public Command {
    public:
        NegativeCommand( Sessions& _sessions );
        void interpret( std::istream& );
        
    private:
        Sessions& sessions;
};

#endif