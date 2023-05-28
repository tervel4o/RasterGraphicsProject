#ifndef SESSIONS_HPP
#define SESSIONS_HPP


#include "Session.hpp"

class Sessions {
    public:
        Sessions();
        Sessions( const Session& newSession );

        Session& getActiveSession() ;
        const Session& getActiveSession() const;

        const std::size_t getActiveSessionIndex() const;

        void switchActiveSession( std::size_t newActiveIndex );
        void loadNewSession( const Session& newSession );

    private:
        std::vector<Session> sessions;
        std::size_t activeSessionIndex;
};

#endif