#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <fstream>
#include "ImageVisitor.hpp"
#include "ImagePBM.hpp"
#include "ImagePGM.hpp"
#include "ImagePPM.hpp"

class Serializer : public ImageVisitor {
    public:
        Serializer( std::ostream& _out );

        void visit( ImagePBM* imagePBM ) const override;
        void visit( ImagePGM* imagePGM ) const override;
        void visit( ImagePPM* imagePPM ) const override;

    private:
        void printCommentars( const std::vector<std::string>& commentars ) const;

    private:
        std::ostream& out;
};

#endif