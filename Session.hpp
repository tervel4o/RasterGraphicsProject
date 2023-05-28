#ifndef SESSION_HPP
#define SESSION_HPP

#include <vector>
#include "ImageEntity.hpp"

class Session {
    public:
        Session();
        Session( const ImageEntity& element );

        Session& addEntity( const ImageEntity& newElement );
        void printSessionInfo() const;

        void addOperation( ImageOperation* imageOperation );
        void undo();

        void saveChanges();
        void saveAs( const std::string& newImageName );

        std::vector<ImageEntity>& getEntitties();
        ImageEntity& getImageEntity( const std::string& name );

    private:
        std::vector<ImageEntity> entities;
};

#endif