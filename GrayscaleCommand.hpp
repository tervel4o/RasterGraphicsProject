#ifndef GRAYSCALECOMMAND_HPP
#define GRAYSCALECOMMAND_HPP

#include "Command.hpp"
#include "Session.hpp"
#include "Sessions.hpp"

class GrayscaleCommand : public Command {
    public:
        GrayscaleCommand( Sessions& _sessions );
        void interpret( std::istream& );
        
    private:
        Sessions& sessions;
};

#endif