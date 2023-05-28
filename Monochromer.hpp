#ifndef MONOCHROMER_HPP
#define MONOCHROMER_HPP

#include "ImageOperation.hpp"

class Monochromer : public ImageOperation {
    public:
        void visit( ImagePBM* ) const override;
        void visit( ImagePGM* imagePGM ) const override;
        void visit( ImagePPM* imagePPM ) const override;

        ImageOperation* clone() override;
        void print() const override;
};

#endif