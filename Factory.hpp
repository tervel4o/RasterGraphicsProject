#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "Image.hpp"
#include "ImagePBM.hpp"
#include "ImagePGM.hpp"
#include "ImagePPM.hpp"

Image* factory( const std::string& type ) {
	if ( type == ".pbm" ) {
		return new ImagePBM();
	}
	else if ( type == ".pgm" ) {
		return new ImagePGM();
	}
	else if ( type == ".ppm" ) {
		return new ImagePPM();
	}

	return nullptr;
}

#endif