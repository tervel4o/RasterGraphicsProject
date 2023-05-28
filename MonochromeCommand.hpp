#ifndef MONOCHROMECOMMAND_HPP
#define MONOCHROMECOMMAND_HPP

#include "Command.hpp"
#include "Session.hpp"
#include "Sessions.hpp"

class MonochromeCommand : public Command {
    public:
        MonochromeCommand( Sessions& _sessions );
        void interpret( std::istream& in );
        
    private:
        Sessions& sessions;
};

#endif