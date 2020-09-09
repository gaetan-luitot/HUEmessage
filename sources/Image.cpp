/*
 * Image.cpp
 *
 *  Created on: 9 sept. 2020
 *      Author: marsevil
 */

#include "../headers/Image.hpp"

Image::Image(std::size_t _width, std::size_t _height) : array(nullptr), width(_width), height(_height) { // @suppress("Class members should be properly initialized")

	if (width != 0 && height != 0) {
		array = new Color[width * height];
	}
}

Image::~Image() {
	delete[] array;
}
