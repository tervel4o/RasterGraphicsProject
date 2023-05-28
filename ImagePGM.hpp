#ifndef IMAGEPGM_HPP
#define IMAGEPGM_HPP

#include <vector>
#include "Image.hpp"
#include "ColoredImageMatrix.hpp"

class ImagePGM : public Image {
    public:
        ImagePGM();
        ImagePGM( const std::string& _imageName );
        ImagePGM( const std::string& _imageName,
                  std::size_t _imageWidth, std::size_t _imageHeight,
                  unsigned char _maxValue );
        ImagePGM( const std::string& _imageName,
                  const ColoredImageMatrix& _imageMatrix );

        bool operator==( const ImagePGM& other );

        Image* clone() const override;
        void accept( ImageVisitor* imageVisitor );

        const std::string& getImageHeader() const;
        const ColoredImageMatrix& getImageMatrix() const;
        ColoredImageMatrix& getImageMatrix();
    
    private:
        static std::string imageHeader;
        ColoredImageMatrix imageMatrix;

        std::vector<std::string> commentars;
};

#endif