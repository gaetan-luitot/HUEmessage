#include <iostream>
#include "../headers/pixel.hpp"

int main(int argc, char** argv) {
	Pixel<int> p = Pixel<int>(4);

	std::cout << p.value() << std::endl;
}
