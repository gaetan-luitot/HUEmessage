/*
 * Color.hpp
 *
 *  Created on: 23 mai 2020
 *      Author: marsevil
 */

#ifndef HEADERS_COLOR_HPP_
#define HEADERS_COLOR_HPP_

#include <cstdint>
#include <stdexcept>
#include <cmath>

class Color {
    static const float RGB2TSL[];

  // RGB
  uint8_t r, g, b;
	// HSV
	float h, s, l;
	// Transparency
	float a;

	void fillHSV();
	void fillRGB();

	void validateRGBConfig();
	void validateHSVConfig();

public:
    // Constructor
	Color(uint8_t _r = 0, uint8_t _g = 0, uint8_t _b = 0, float _a = 1);
	Color(float _h, float _s, float _v, float _a = 1);

	// Accessor.
	inline uint8_t getR() const { return r; }
	inline uint8_t getG() const { return g; }
	inline uint8_t getB() const { return b; }

	inline float getH() const { return h; }
	inline float getS() const { return s; }
	inline float getL() const { return l; }

	inline float getA() const { return a; }

	// Modifier
	void setR(uint8_t _r);
	void setG(uint8_t _g);
	void setB(uint8_t _b);

	void setH(float _h);
	void setS(float _s);
	void setL(float _l);

	inline void setA(float _a) { a = _a; validateRGBConfig(); }

	void setRGB(uint8_t _r, uint8_t _g, uint8_t _b, float _a);
	void setHSL(float _h, float _s, float _v, float _a);
};


#endif /* HEADERS_COLOR_HPP_ */
