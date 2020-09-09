#include <iostream>
#include "../headers/hueConverter.hpp"
#include "../headers/image.hpp"

int main(int argc, char** argv)
{
	Image * img = new Image(10, 10);
	img->clear(4);
	img->pixel(0) = 10;
	img->pixel(1) = 20;
	HueConverter::imgToMsg(img);

	delete img;
}
