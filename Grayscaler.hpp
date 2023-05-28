#ifndef GRAYSCALER_HPP
#define GRAYSCALER_HPP

#include "ImageOperation.hpp"

class Grayscaler : public ImageOperation {
    public:
        void visit( ImagePBM* ) const override;
        void visit( ImagePGM* ) const override;
        void visit( ImagePPM* imagePPM ) const override;

        ImageOperation* clone() override;
        void print() const override;
};

#endif