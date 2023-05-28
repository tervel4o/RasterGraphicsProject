#include "Image.hpp"

Image::Image()
    : imageName( "" ) {}
Image::Image( const std::string& _imageName ) 
    : imageName( _imageName ) {}

const std::string& Image::getName() const {
    return this->imageName;
}
const std::vector<std::string>& Image::getCommentars() const {
    return this->commentars;
}
std::vector<std::string>& Image::getCommentars() {
    return this->commentars;
}
void Image::setName( const std::string& _newImageName ) {
    this->imageName = _newImageName;
}