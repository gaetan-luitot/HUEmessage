/*
 * Image.hpp
 *
 *  Created on: 9 sept. 2020
 *      Author: marsevil
 */

#ifndef HEADERS_IMAGE_HPP_
#define HEADERS_IMAGE_HPP_

#include <cstdint>
#include <memory>
#include "Color.hpp"

class Image {
	Color* array;
	std::size_t width, height;

public:

	Image(std::size_t _width = 0, std::size_t _height = 0);

	~Image();

	/**
	 * Constant getter.
	 */
	inline Color getPixel(std::size_t x, std::size_t y) const { return array[width * y + x]; }
	/**
	 * Setter by replacement.
	 */
	inline void setPixel(std::size_t x, std::size_t y, Color color) { array[width * y + x] = color; }
	/**
	 * Return reference to edit value.
	 */
	inline Color& pixel(std::size_t x, std::size_t y) {	return array[width * y + x]; }
};


#endif /* HEADERS_IMAGE_HPP_ */
