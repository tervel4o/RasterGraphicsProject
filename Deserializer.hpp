#ifndef DESERIALIZER_HPP
#define DESERIALIZER_HPP

#include <fstream>
#include "ImageVisitor.hpp"
#include "ImagePBM.hpp"
#include "ImagePGM.hpp"
#include "ImagePPM.hpp"

class Deserializer : public ImageVisitor {
    public:
        Deserializer( const std::string& _fileName );

        void visit( ImagePBM* imagePBM ) const override;
        void visit( ImagePGM* imagePGM ) const override;
        void visit( ImagePPM* imagePPM ) const override;

    private:
        void readCommentars( std::vector<std::string>& commentars, std::ifstream& ifs ) const;

    private:
        std::string fileName;
};

#endif