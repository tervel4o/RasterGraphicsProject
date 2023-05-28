#ifndef COLLAGEVERTICALCOMMAND_HPP
#define COLLAGEVERTICALCOMMAND_HPP

#include "Command.hpp"
#include "Session.hpp"
#include "Sessions.hpp"

class CollageVerticalCommand : public Command {
    public:
        CollageVerticalCommand( Sessions& _sessions );

        void interpret( std::istream& );

    private:
        Sessions& sessions;
};

#endif