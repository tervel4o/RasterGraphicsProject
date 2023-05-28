#ifndef TESTS_HPP
#define TESTS_HPP

#include <cassert>
#include "Deserializer.hpp"
#include "Grayscaler.hpp"
#include "Monochromer.hpp"
#include "Negativer.hpp"
#include "RightRotator.hpp"
#include "LeftRotator.hpp"
#include "ImagePBM.hpp"
#include "HorizontalCollager.hpp"
#include "VerticalCollager.hpp"

void TestPBMGrayscaler() {
	ImagePBM imgPBM( "imgPBM.pbm");
	Deserializer des( "imgPBM.pbm" );
	des.visit( &imgPBM );

	Grayscaler gr;
	gr.visit(&imgPBM);

	ImagePBM imgPBMGrayscale( "imgPBMGrayscale.pbm" );
	Deserializer des1( "imgPBMGrayscale.pbm" );
	des1.visit( &imgPBMGrayscale );

	assert( imgPBM == imgPBMGrayscale );
}
void TestPBMMonochromer() {
	ImagePBM imgPBM( "imgPBM.pbm" );
	Deserializer des( "imgPBM.pbm" );
	des.visit( &imgPBM );

	Monochromer mn;
	mn.visit( &imgPBM );

	ImagePBM imgPBMMonochrome( "imgPBMMonochrome.pbm" );
	Deserializer des1( "imgPBMMonochrome.pbm" );
	des1.visit( &imgPBMMonochrome );

	assert( imgPBM == imgPBMMonochrome );
}
void TestPBMNegativer() {
	ImagePBM imgPBM( "imgPBM.pbm" );
	Deserializer des( "imgPBM.pbm" );
	des.visit( &imgPBM );

	Negativer neg;
	neg.visit( &imgPBM );

	ImagePBM imgPBMNegative( "imgPBMNegative.pbm" );
	Deserializer des1( "imgPBMNegative.pbm" );
	des1.visit( &imgPBMNegative );

	assert( imgPBM == imgPBMNegative );
}
void TestPBMRotateRight() {
	ImagePBM imgPBM( "imgPBM.pbm" );
	Deserializer des( "imgPBM.pbm" );
	des.visit( &imgPBM );

	RightRotator rr;
	rr.visit( &imgPBM );

	ImagePBM imgPBMRotateRight( "imgPBMRotateRight.pbm" );
	Deserializer des1( "imgPBMRotateRight.pbm" );
	des1.visit( &imgPBMRotateRight );

	assert( imgPBM == imgPBMRotateRight );
}

void TestPBMRotateLeft() {
	ImagePBM imgPBM( "imgPBM.pbm" );
	Deserializer des( "imgPBM.pbm" );
	des.visit( &imgPBM );

	LeftRotator lr;
	lr.visit( &imgPBM );

	ImagePBM imgPBMRotateLeft( "imgPBMRotateLeft.pbm" );
	Deserializer des1( "imgPBMRotateLeft.pbm" );
	des1.visit( &imgPBMRotateLeft );

	assert( imgPBM == imgPBMRotateLeft );
}

/////////////////////////////////////////

void TestPGMGrayscaler() {
	ImagePGM imgPGM( "imgPGM.pgm" );
	Deserializer des( "imgPGM.pgm" );
	des.visit( &imgPGM );

	Grayscaler gr;
	gr.visit( &imgPGM );

	ImagePGM imgPGMGrayscale( "imgPGMGrayscale.pgm" );
	Deserializer des1( "imgPGMGrayscale.pgm" );
	des1.visit( &imgPGMGrayscale );

	assert( imgPGM == imgPGMGrayscale );
}
void TestPGMMonochromer() {
	ImagePGM imgPGM( "imgPGM.pgm" );
	Deserializer des( "imgPGM.pgm" );
	des.visit( &imgPGM );

	Monochromer mn;
	mn.visit( &imgPGM );

	ImagePGM imgPGMMonochrome( "imgPGMMonochrome.pgm" );
	Deserializer des1( "imgPGMMonochrome.pgm" );
	des1.visit( &imgPGMMonochrome );

	assert( imgPGM == imgPGMMonochrome );
}
void TestPGMNegativer() {
	ImagePGM imgPGM( "imgPGM.pgm" );
	Deserializer des( "imgPGM.pgm" );
	des.visit( &imgPGM );

	Negativer neg;
	neg.visit( &imgPGM );

	ImagePGM imgPGMNegative( "imgPGMNegative.pgm" );
	Deserializer des1( "imgPGMNegative.pgm" );
	des1.visit( &imgPGMNegative );

	assert( imgPGM == imgPGMNegative );
}
void TestPGMRotateRight() {
	ImagePGM imgPGM( "imgPGM.pgm" );
	Deserializer des( "imgPGM.pgm" );
	des.visit( &imgPGM );

	RightRotator rr;
	rr.visit( &imgPGM );

	ImagePGM imgPGMRotateRight( "imgPGMRotateRight.pgm" );
	Deserializer des1( "imgPGMRotateRight.pgm" );
	des1.visit( &imgPGMRotateRight );

	assert( imgPGM == imgPGMRotateRight );
}

void TestPGMRotateLeft() {
	ImagePGM imgPGM( "imgPGM.pgm" );
	Deserializer des( "imgPGM.pgm" );
	des.visit( &imgPGM );

	LeftRotator lr;
	lr.visit( &imgPGM );

	ImagePGM imgPGMRotateLeft( "imgPGMRotateLeft.pgm" );
	Deserializer des1( "imgPGMRotateLeft.pgm" );
	des1.visit( &imgPGMRotateLeft );

	assert( imgPGM == imgPGMRotateLeft );
}

/////////////////////////////////////////////////////

void TestPPMGrayscaler() {
	ImagePPM imgPPM( "imgPPM.ppm" );
	Deserializer des( "imgPPM.ppm" );
	des.visit( &imgPPM );

	Grayscaler gr;
	gr.visit( &imgPPM );

	ImagePPM imgPPMGrayscale( "imgPPMGrayscale.ppm" );
	Deserializer des1( "imgPPMGrayscale.ppm" );
	des1.visit( &imgPPMGrayscale );

	assert( imgPPM == imgPPMGrayscale );
}
void TestPPMMonochromer() {
	ImagePPM imgPPM( "imgPPM.ppm" );
	Deserializer des( "imgPPM.ppm" );
	des.visit( &imgPPM );

	Monochromer mn;
	mn.visit( &imgPPM );

	ImagePPM imgPPMMonochrome( "imgPPMMonochrome.ppm" );
	Deserializer des1( "imgPPMMonochrome.ppm" );
	des1.visit( &imgPPMMonochrome );

	assert( imgPPM == imgPPMMonochrome );
}
void TestPPMNegativer() {
	ImagePPM imgPPM( "imgPPM.ppm" );
	Deserializer des( "imgPPM.ppm" );
	des.visit( &imgPPM );

	Negativer neg;
	neg.visit( &imgPPM );

	ImagePPM imgPPMNegative( "imgPPMNegative.ppm" );
	Deserializer des1( "imgPPMNegative.ppm" );
	des1.visit( &imgPPMNegative );

	assert( imgPPM == imgPPMNegative );
}
void TestPPMRotateRight() {
	ImagePPM imgPPM( "imgPPM.ppm" );
	Deserializer des( "imgPPM.ppm" );
	des.visit( &imgPPM );

	RightRotator rr;
	rr.visit( &imgPPM );

	ImagePPM imgPPMRotateRight( "imgPPMRotateRight.ppm" );
	Deserializer des1( "imgPPMRotateRight.ppm" );
	des1.visit( &imgPPMRotateRight );

	assert( imgPPM == imgPPMRotateRight );
}

void TestPPMRotateLeft() {
	ImagePPM imgPPM( "imgPPM.ppm" );
	Deserializer des( "imgPGP.ppm" );
	des.visit( &imgPPM );

	LeftRotator lr;
	lr.visit( &imgPPM );

	ImagePPM imgPPMRotateLeft( "imgPPMRotateLeft.ppm" );
	Deserializer des1( "imgPPMRotateLeft.ppm" );
	des1.visit( &imgPPMRotateLeft );

	assert( imgPPM == imgPPMRotateLeft );
}
#endif