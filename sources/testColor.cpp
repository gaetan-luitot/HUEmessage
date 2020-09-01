/*
 * testColor.cpp
 *
 *  Created on: 24 mai 2020
 *      Author: marsevil
 */

#include <iostream>
#include "../headers/Color.hpp"

int main(int argc, char** argv) {
    Color* colorFromRGB = new Color((uint8_t)89, (uint8_t)45, (uint8_t)128);
    std::cout << "ColorRGB -> TSL :"
        << " h = " << colorFromRGB->getH()
        << " s = " << colorFromRGB->getS()
        << " v = " << colorFromRGB->getL()
        << " a = " << colorFromRGB->getA()
        << std::endl;

    Color* colorFromHSV = new Color((float)272.0, 0.480, 0.339);
    std::cout << "ColorHSV -> RGB :"
        << " r = " << (int)colorFromHSV->getR()
        << " g = " << (int)colorFromHSV->getG()
        << " b = " << (int)colorFromHSV->getB()
        << std::endl;

    delete colorFromRGB;
    delete colorFromHSV;

    return EXIT_SUCCESS;
}
