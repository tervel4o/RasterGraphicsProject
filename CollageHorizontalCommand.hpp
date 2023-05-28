#ifndef COLLAGEHORIZONTALCOMMAND_HPP
#define COLLAGEHORIZONTALCOMMAND_HPP

#include "Command.hpp"
#include "Session.hpp"
#include "Sessions.hpp"

class CollageHorizontalCommand : public Command {
    public:
        CollageHorizontalCommand( Sessions& _sessions );

        void interpret( std::istream& );

    private:
        Sessions& sessions;
};

#endif