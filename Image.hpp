#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <string>
#include <vector>
#include "ImageVisitor.hpp"

class Image {
    public:
        Image();
        Image( const std::string& _imageName );
        virtual ~Image() = default;

        virtual void accept( ImageVisitor* imageVisitor ) = 0;
        virtual Image* clone() const = 0;

        const std::string& getName() const;
        std::vector<std::string>& getCommentars();
        const std::vector<std::string>& getCommentars() const;

        void setName( const std::string& _newImageName );

    private:
        std::string imageName;
        std::vector<std::string> commentars;
};

#endif