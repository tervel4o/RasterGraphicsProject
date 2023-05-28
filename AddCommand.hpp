#ifndef ADDCOMMAND_HPP
#define ADDCOMMAND_HPP

#include "Command.hpp"
#include "Sessions.hpp"
#include "Session.hpp"

class AddCommand : public Command {
    public:
        AddCommand( Sessions& _sessions );
        void interpret( std::istream& );
        
    private:
    Sessions& sessions;
};

#endif