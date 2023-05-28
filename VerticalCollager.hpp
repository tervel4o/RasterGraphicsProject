#ifndef VERTICALCOLLAGER_HPP
#define VERTICALCOLLAGER_HPP

#include "ImageOperation.hpp"

class VerticalCollager : public ImageOperation {
    public:
        VerticalCollager();
        VerticalCollager( Image* _toCollageWith, const std::string& _collagedName );
        VerticalCollager( const VerticalCollager& other );
        ~VerticalCollager();

        VerticalCollager& operator=( const VerticalCollager& other );

        void visit( ImagePBM* imagePBM ) const override;
        void visit( ImagePGM* imagePGM ) const override;
        void visit( ImagePPM* imagePPM ) const override;

        ImageOperation* clone() override;
        void print() const override;
        void setToCollageWith( const Image*& _toCollageWith );
        void setCollagedName( const std::string& _collagedName );

    private:
        void copy( const VerticalCollager& other );
        void destroy();

    private:
        Image* toCollageWith;
        std::string collagedName;
};

#endif