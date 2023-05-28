#ifndef UNDOCOMMAND_HPP
#define UNDOCOMMAND_HPP

#include "Command.hpp"
#include "Sessions.hpp"
#include "Session.hpp"

class UndoCommand : public Command {
    public:
        UndoCommand( Sessions& _sessions );
        void interpret( std::istream& );
        
    private:
    Sessions& sessions;
};

#endif