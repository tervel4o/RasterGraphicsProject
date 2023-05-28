#ifndef SWITCHCOMMAND_HPP
#define SWITCHCOMMAND_HPP

#include "Command.hpp"
#include "Sessions.hpp"

class SwitchCommand : public Command {
    public:
        SwitchCommand( Sessions& _sessions );
        void interpret( std::istream& in );
    private:
        Sessions& sessions;
};

#endif