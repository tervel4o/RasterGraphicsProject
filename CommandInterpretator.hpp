#ifndef COMMANDINTERPRETATOR_HPP
#define COMMANDINTERPRETATOR_HPP

#include <vector>
#include <utility>
#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>

#include "Command.hpp"
#include "LoadCommand.hpp"

class CommandInterpretator {
    public:
        CommandInterpretator();
        
        void start();
        void stop();

        void addCommand( const std::string& newCommandName, const std::string& newCommandDescr, Command* newCommand );

    private:
        std::size_t indexOfCommand( const std::string& commandName ) const;
        void enteredClose();
    
    private:
        class HelpCommand : public Command {
            public:
                HelpCommand( CommandInterpretator* _interpretator )
                    : interpretator( _interpretator ) {}
                
                void interpret( std::istream& ) {
                    for ( std::size_t i = 0 ; i < interpretator->commands.size() ; ++ i ) {
                        std::cout.width( 20 ); std::cout << std::left << interpretator->commands[ i ].commandName;
                        std::cout << interpretator->commands[ i ].commandDescr << '\n';
                    }
                }
            
            private:
                CommandInterpretator* interpretator;
        };
    private:
        class ExitCommand : public Command {
            public:
                ExitCommand( CommandInterpretator* _interpretator ) 
                    : interpretator( _interpretator ) {}
                
                void interpret( std::istream& ) {
                    this->interpretator->stop();
                }
            
            private:
                CommandInterpretator* interpretator;
        };

    private:
        class CloseCommand : public Command {
        public:
            CloseCommand( CommandInterpretator* _interpretator )
                : interpretator( _interpretator ) {}
            void interpret( std::istream& ) {
                std::cout << "You should load a new session or switch session to continue!\n";
                this->interpretator->enteredClose();
            }
        private:
            CommandInterpretator* interpretator;
};
    
    private:
        struct commandDescription {
            std::string commandName;
            std::string commandDescr;
            Command* command;
        };
        std::vector< commandDescription > commands;
        bool interpretable;
        bool enteredCloseCommand;

        CloseCommand closeCommand;
        ExitCommand exitCommmand;
        HelpCommand helpCommand;
};

#endif