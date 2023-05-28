#include "Sessions.hpp"
#include "CommandInterpretator.hpp"
#include "LoadCommand.hpp"
#include "SaveCommand.hpp"
#include "SaveAsCommand.hpp"
#include "GrayscaleCommand.hpp"
#include "MonochromeCommand.hpp"
#include "NegativeCommand.hpp"
#include "RotateCommand.hpp"
#include "UndoCommand.hpp"
#include "AddCommand.hpp"
#include "SessionInfoCommand.hpp"
#include "SwitchCommand.hpp"
#include "CollageHorizontalCommand.hpp"
#include "CollageVerticalCommand.hpp"


int main() {
    CommandInterpretator commandInterpretator;
    Sessions sessions;
    LoadCommand loadCommand( sessions );
    SaveCommand saveCommand( sessions );
    SaveAsCommand saveAsCommand( sessions );
    GrayscaleCommand grayscaleCommand( sessions );
    MonochromeCommand monochromeCommand( sessions );
    NegativeCommand negativeCommand( sessions );
    RotateCommand rotateCommand( sessions );
    UndoCommand undoCommand( sessions );
    AddCommand addCommand( sessions );
    SessionInfoCommand sessionInfoCommand( sessions );
    SwitchCommand switchCommand( sessions );
    CollageHorizontalCommand collageHorizontalCommand( sessions );
    CollageVerticalCommand collageVerticalCommand( sessions );

    commandInterpretator.addCommand( "load", "loads new session", &loadCommand );
    commandInterpretator.addCommand( "save", "saves the images from the current session", &saveCommand );
    commandInterpretator.addCommand( "saveAs", "saves only the first image from the current session with new name", &saveAsCommand );
    commandInterpretator.addCommand( "grayscale", "grayscales the images from the current session", &grayscaleCommand );
    commandInterpretator.addCommand( "monochrome", "makes the images from the current session black&white", &monochromeCommand );
    commandInterpretator.addCommand( "negative", "inverts the colors of the images from the current session", &negativeCommand );
    commandInterpretator.addCommand( "rotate", "rotates left or right the images from the active session", &rotateCommand );
    commandInterpretator.addCommand( "undo", "removes the last command of the images from the current session", &undoCommand );
    commandInterpretator.addCommand( "add", "adds an image to the current session", &addCommand );
    commandInterpretator.addCommand( "sessionInfo", "gives detailed information for the images from the current session", &sessionInfoCommand );
    commandInterpretator.addCommand( "switch", "switches the current session", &switchCommand );
    commandInterpretator.addCommand( "collageHorizontal", "collages horizontally an image from the current session with another one and saves the result as a new image from the same type", &collageHorizontalCommand );
    commandInterpretator.addCommand( "collageVertical", "collages vertically an image from the current session with another one and saves the result as a new image from the same type", &collageVerticalCommand );
    

    commandInterpretator.start();
    
    return 0;
}

//dobavi ime, description kym command