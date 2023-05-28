#ifndef ROTATECOMMAND_HPP
#define ROTATECOMMAND_HPP

#include <utility>
#include "Command.hpp"
#include "Session.hpp"
#include "Sessions.hpp"

class RotateCommand : public Command {
    public:
        RotateCommand( Sessions& _sessions );
        RotateCommand( const RotateCommand& ) = delete;
        RotateCommand& operator=( const RotateCommand& ) = delete;
        ~RotateCommand();

        void interpret( std::istream& in );
        
    private:
        Sessions& sessions;
        std::vector<std::pair< std::string, ImageOperation* >> rotations;
};

#endif