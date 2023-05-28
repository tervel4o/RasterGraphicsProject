#ifndef RIGHTROTATOR_HPP
#define RIGHTROTATOR_HPP

#include "ImageOperation.hpp"

class RightRotator : public ImageOperation {
    public:
        void visit( ImagePBM* imagePBM ) const override;
        void visit( ImagePGM* imagePGM ) const override;
        void visit( ImagePPM* imagePPM ) const override;

        ImageOperation* clone() override;
        void print() const override;
};

#endif