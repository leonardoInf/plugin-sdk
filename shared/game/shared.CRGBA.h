/*
    Plugin-SDK (Grand Theft Auto) SHARED header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/
#pragma once

#include "RenderWare.h"

class CRGBA {
public:
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;

	CRGBA(unsigned char red, unsigned char green, unsigned char blue) {
		Set(red, green, blue, 255);
	}

	CRGBA(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha) {
		Set(red, green, blue, alpha);
	}

	CRGBA(CRGBA const &rhs) {
		Set(rhs);
	}

	CRGBA(unsigned int intValue) {
		Set(intValue);
	}

	CRGBA(RwRGBA const &rhs) {
		Set(rhs);
	}

	CRGBA() {}

	void Set(unsigned char red, unsigned char green, unsigned char blue) {
		r = red;
		g = green;
		b = blue;
	}

	void Set(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha) {
		Set(red, green, blue);
		a = alpha;
	}

	void Set(unsigned int intValue) {
		r = intValue & 0xFF;
		g = (intValue >> 8) & 0xFF;
		g = (intValue >> 16) & 0xFF;
		g = (intValue >> 24) & 0xFF;
	}

	void Set(CRGBA const &rhs) {
		Set(rhs.r, rhs.g, rhs.b, rhs.a);
	}

	void Set(CRGBA const &rhs, unsigned char alpha) {
		Set(rhs.r, rhs.g, rhs.b, alpha);
	}

	void Set(RwRGBA const &rwcolor) {
		Set(rwcolor.red, rwcolor.green, rwcolor.blue, rwcolor.alpha);
	}

	unsigned int ToInt() const {
		return r | (g << 8) | (b << 16) | (a << 24);
	}

	RwRGBA ToRwRGBA() const {
		return { r, g, b, a };
	}

	void FromRwRGBA(RwRGBA const &rwcolor) {
		Set(rwcolor);
	}

	void Invert() {
		Set(255 - r, 255 - g, 255 - b);
	}

	CRGBA Inverted() const {
		CRGBA invertedColor = *this;
		invertedColor.Invert();
		return invertedColor;
	}

	bool operator==(CRGBA const &rhs) const {
		return r == rhs.r && g == rhs.g && b == rhs.b && a == rhs.a;
	}

	CRGBA &operator=(CRGBA const &rhs) {
		Set(rhs);
		return *this;
	}

	CRGBA ToRGB() const {
		return CRGBA(r, g, b, 255);
	}
};
