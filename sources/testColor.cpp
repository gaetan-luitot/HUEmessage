/*
 * testColor.cpp
 *
 *  Created on: 24 mai 2020
 *      Author: marsevil
 */

#include <iostream>
#include "../headers/Color.hpp"

int main(int argc, char** argv) {
    Color* colorFromRGB = new Color((uint8_t)142, (uint8_t)44, (uint8_t)89);
    std::cout << "ColorRGB -> TSL :"
        << " h = " << colorFromRGB->getH()
        << " s = " << colorFromRGB->getS()
        << " v = " << colorFromRGB->getV()
        << " a = " << colorFromRGB->getA()
        << std::endl;

    Color* colorFromHSV = new Color((float)332.0, 0.527, 0.365);
    std::cout << "ColorHSV -> RGB :"
        << " r = " << (int)colorFromHSV->getR()
        << " g = " << (int)colorFromHSV->getG()
        << " b = " << (int)colorFromHSV->getB()
        << std::endl;

    delete colorFromRGB;
    delete colorFromHSV;

    return EXIT_SUCCESS;
}
