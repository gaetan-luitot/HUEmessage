/*
 * testImage.cpp
 *
 *  Created on: 9 sept. 2020
 *      Author: marsevil
 */

#include <iostream>
#include <memory>
#include "../headers/Image.hpp"

int main() {
	std::unique_ptr<Image> img(new Image(3, 1));

	img->pixel(0, 0).setRGB(255, 0, 0);
	img->pixel(1, 0).setRGB(0, 255, 0);
	img->pixel(2, 0).setRGB(0, 0, 255);

	for (std::size_t y = 0; y < img->getHeight(); ++y) {
		for (std::size_t x = 0; x < img->getWidth(); ++x) {
			Color* color = new Color(img->getPixel(x, y));
			std::cout << "pixel (" << x << ", " << y << ") : r = " << (int)color->getR() << ", g = " << (int)color->getG() << ", b = " << (int)color->getB() << std::endl;
			delete color;
		}
	}

	std::cout << "Terminated" << std::endl;

	return EXIT_SUCCESS;
}


