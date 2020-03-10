#include <iostream>
#include "../headers/libPNG.hpp"

int main(int argc, char** argv) {

	std::cout << int(LibPNG::readPNG("/home/gaga/Documents/projets/git/HUEmessage/img/random.png").pixel(1, 1.).a()) << std::endl;
}
