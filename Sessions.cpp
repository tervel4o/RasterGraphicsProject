#include <cassert>
#include "Sessions.hpp"

Sessions::Sessions() 
    : sessions(), activeSessionIndex( 0 ) {}
Sessions::Sessions( const Session& newSession )
    : sessions() {
    this->sessions.push_back( newSession );
    this->activeSessionIndex = 0;
}

Session& Sessions::getActiveSession() {
    if ( this->sessions.size() > 0 ) {
        return this->sessions[ this->activeSessionIndex ];
    }
}
const Session& Sessions::getActiveSession() const {
    if ( this->sessions.size() > 0 ) {
        return this->sessions[ this->activeSessionIndex ];
    }
}
const std::size_t Sessions::getActiveSessionIndex() const {
    return this->activeSessionIndex;
}

void Sessions::switchActiveSession( std::size_t newActiveIndex ) {
    assert( newActiveIndex < this->sessions.size() );

    this->activeSessionIndex = newActiveIndex;
}
void Sessions::loadNewSession( const Session& newSession ) {
    this->sessions.push_back( newSession );
    this->switchActiveSession( this->sessions.size() - 1 );
}