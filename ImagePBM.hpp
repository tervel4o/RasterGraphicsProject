#ifndef IMAGEPBM_HPP
#define IMAGEPBM_HPP

#include <string>
#include <vector>
#include "Image.hpp"
#include "ImageMatrix.hpp"

class ImagePBM : public Image {
    public:
        ImagePBM();
        ImagePBM( const std::string& _imageName );
        ImagePBM( const std::string& _imageName,
                  std::size_t imageWidth, std::size_t imageHeight );
        ImagePBM( const std::string& _imageName,
                  const ImageMatrix& _imageMatrix );

        bool operator==( const ImagePBM& other );

        Image* clone() const override;
        void accept( ImageVisitor* imageVisitor ) override;

        const ImageMatrix& getImageMatrix() const;
        ImageMatrix& getImageMatrix();

        const std::string& getImageHeader() const;

    private:
        static std::string imageHeader;
        ImageMatrix imageMatrix;
};

#endif