#ifndef IMAGEENTITY_HPP
#define IMAGEENTITY_HPP

#include <vector>
#include "Image.hpp"
#include "ImageOperation.hpp"
#include "Serializer.hpp"

class ImageEntity {
    public:
        ImageEntity( Image* _image );
        ImageEntity( const ImageEntity& other );
        ~ImageEntity();

        ImageEntity& operator=( const ImageEntity& other );

        bool notEmpty() const;

        void addOperation( ImageOperation* newOperation );
        void removeLastOperation();
        void applyOperations();
        void serialize( Serializer& serializer );

        void print() const;
        const Image* getImage() const;
        Image* getImage();

    private:
        void copy( const ImageEntity& other );
        void destroy();

    private:
        Image* image;
        std::vector<ImageOperation*> operations;
};

#endif