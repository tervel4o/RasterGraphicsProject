#include "CommandInterpretator.hpp"


CommandInterpretator::CommandInterpretator()
    : helpCommand( this ), exitCommmand( this ), closeCommand( this ) {
    this->interpretable = true;
    this->enteredCloseCommand = false;
    this->addCommand( "exit", "exits the program", &( this->exitCommmand ) );
    this->addCommand( "help", "prints info for commands", &( this->helpCommand ) );
    this->addCommand( "close", "closes current session", &( this->closeCommand ) );
}

void CommandInterpretator::start() {
    std::cout << "Welcome to Raster Graphics Editor TGS! Have fun!\n\n";
    std::cout << "You can see the interpretable commands when you type 'help'\n";
    while( this->interpretable ) {
        std::string currentCommand;
        std::cout << "> ";
        std::cin >> currentCommand;

        std::size_t indexOfCurrentCommand = this->indexOfCommand( currentCommand );

        if ( indexOfCurrentCommand != this->commands.size() ) {
            if ( this->enteredCloseCommand ) {
                if ( currentCommand != "load" && currentCommand != "switch" ) {
                    this->stop();
                }
                else {
                    this->enteredCloseCommand = false;
                }
            }
            else {
                this->commands[ indexOfCurrentCommand ].command->interpret( std::cin );
            }
        }
        else {
            std::cout << "Unknown command, try again\n";
        }
    }
}
void CommandInterpretator::stop() {
    this->interpretable = false;
}
void CommandInterpretator::enteredClose() {
    this->enteredCloseCommand = true;
}
void CommandInterpretator::addCommand( const std::string& newCommandName, const std::string& newCommandDescr, Command* newCommand ) {
    this->commands.push_back( { newCommandName, newCommandDescr, newCommand } );
} 
std::size_t CommandInterpretator::indexOfCommand( const std::string& commandName ) const {
    for ( std::size_t i = 0 ; i < this->commands.size() ; ++ i ) {
        if ( commandName == this->commands[ i ].commandName ) {
            return i;
        }
    }

    return this->commands.size();
}