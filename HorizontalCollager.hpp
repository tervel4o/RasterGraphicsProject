#ifndef HORIZONTALCOLLAGER_HPP
#define HORIZONTALCOLLAGER_HPP

#include "ImageOperation.hpp"

class HorizontalCollager : public ImageOperation {
    public:
        HorizontalCollager();
        HorizontalCollager( Image* _toCollageWith, const std::string& _collagedName );
        HorizontalCollager( const HorizontalCollager& other );
        ~HorizontalCollager();

        HorizontalCollager& operator= ( const HorizontalCollager& other );

        void visit( ImagePBM* imagePBM ) const override;
        void visit( ImagePGM* imagePGM ) const override;
        void visit( ImagePPM* imagePPM ) const override;

        ImageOperation* clone() override;
        void print() const override;
        void setToCollageWith( const Image*& _toCollageWith );
        void setCollagedName( const std::string& _collagedName );
    
    private:
        void copy( const HorizontalCollager& other );
        void destroy();

    private:
        Image* toCollageWith;
        std::string collagedName;
};

#endif