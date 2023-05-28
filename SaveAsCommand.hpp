#ifndef SAVEASCOMMAND_HPP
#define SAVEASCOMMAND_HPP

#include "Command.hpp"
#include "Sessions.hpp"
#include "Session.hpp"

class SaveAsCommand : public Command {
    public:
        SaveAsCommand( Sessions& _sessions );
        void interpret( std::istream& in );
        
    private:
    Sessions& sessions;
    std::string newImageName;
};

#endif