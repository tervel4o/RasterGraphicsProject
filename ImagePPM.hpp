#ifndef IMAGEPPM_HPP
#define IMAGEPPM_HPP

#include <vector>
#include "Image.hpp"
#include "ColoredImageMatrix.hpp"

class ImagePPM : public Image {
    public:
        ImagePPM();
        ImagePPM( const std::string& _imageName );
        ImagePPM( const std::string& _imageName,
                  std::size_t _imageWidth, std::size_t _imageHeight,
                  unsigned char _maxValue );
        ImagePPM( const std::string& _imageName,
                  const ColoredImageMatrix& _imageMatrixRed,
                  const ColoredImageMatrix& _imageMatrixGreen,
                  const ColoredImageMatrix& _imageMatrixBlue );

        bool operator==( const ImagePPM& other );

        Image* clone() const override;
        void accept( ImageVisitor* imageVisitor );

        const std::string& getImageHeader() const;
        const ColoredImageMatrix& getImageMatrixRed() const;
        ColoredImageMatrix& getImageMatrixRed();
        const ColoredImageMatrix& getImageMatrixGreen() const;
        ColoredImageMatrix& getImageMatrixGreen();
        const ColoredImageMatrix& getImageMatrixBlue() const;
        ColoredImageMatrix& getImageMatrixBlue();

    private:
        static std::string imageHeader;
        ColoredImageMatrix imageMatrixRed, imageMatrixGreen, imageMatrixBlue;

        std::vector<std::string> commentars;
};

#endif