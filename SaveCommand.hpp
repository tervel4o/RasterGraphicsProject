#ifndef SAVECOMMAND_HPP
#define SAVECOMMAND_HPP

#include "Command.hpp"
#include "Sessions.hpp"
#include "Session.hpp"

class SaveCommand : public Command {
    public:
        SaveCommand( Sessions& _sessions );
        void interpret( std::istream& );
        
    private:
    Sessions& sessions;
};

#endif