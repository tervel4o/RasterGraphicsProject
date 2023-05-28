#ifndef IMAGEOPERATION_HPP
#define IMAGEOPERATION_HPP

#include <iostream>
#include "ImageVisitor.hpp"
#include "ImagePBM.hpp"
#include "ImagePGM.hpp"
#include "ImagePPM.hpp"

class ImageOperation : public ImageVisitor {
    public:
        virtual ~ImageOperation() = default;
        
        virtual ImageOperation* clone() = 0;
        virtual void print() const = 0;
};

#endif