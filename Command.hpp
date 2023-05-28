#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <fstream>

class Command {
    public:
        virtual void interpret( std::istream& ) = 0;
        virtual ~Command() = default;
};

#endif