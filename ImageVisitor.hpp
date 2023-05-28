#ifndef IMAGEVISITOR_HPP
#define IMAGEVISITOR_HPP

class ImagePBM;
class ImagePGM;
class ImagePPM;

class ImageVisitor {
    public:
        virtual void visit( ImagePBM* imagePBM ) const = 0;
        virtual void visit( ImagePGM* imagePGM ) const = 0;
        virtual void visit( ImagePPM* imagePPM ) const = 0;
};

#endif