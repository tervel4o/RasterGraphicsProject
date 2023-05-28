#ifndef LOADCOMMAND_HPP
#define LOADCOMMAND_HPP

#include "Command.hpp"
#include "Sessions.hpp"

class LoadCommand : public Command {
    public:
        LoadCommand( Sessions& _sessions );
        void interpret( std::istream& in );
    private:
    Sessions& sessions;
};

#endif