/*
 * testImage.cpp
 *
 *  Created on: 9 sept. 2020
 *      Author: marsevil
 */

#include <iostream>
#include "../headers/Image.hpp"

int main() {
	Image* img = new Image(3, 1);

	img->pixel(0, 0).setRGB(255, 0, 0);
	img->pixel(1, 0).setRGB(0, 255, 0);
	img->pixel(2, 0).setRGB(0, 0, 255);

	delete img;

	std::cout << "Terminated" << std::endl;

	return EXIT_SUCCESS;
}


