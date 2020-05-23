/*
 * Color.cpp
 *
 *  Created on: 23 mai 2020
 *      Author: marsevil
 */

#include "../headers/Color.hpp"

const float Color::RGB2TSL[] = {0.2627, 0.6780, 0.0593};

Color::Color(uint8_t _r, uint8_t _g, uint8_t _b, float _a)
: r(_r), g(_g), b(_b), a(_a), h(0), s(0), v(0) {
    // Check arguments values
    if (a < 0 || a > 1) {
        a = 0;
        throw std::invalid_argument("Transparency value a, have to be between 0 and 1");
    }

    fillHSV();
}

Color::Color(float _h, float _s, float _v, float _a)
: h(_h), s(_s), v(_v), a(_a), r(0), g(0), b(0){
    // Check argument values.
    if (h < 0 || h > 360 || s < 0 || s > 1 || v < 0 || v > 1 || a < 0 || a > 1) {
        h = 0;
        s = 0;
        v = 0;
        a = 0;
        throw std::invalid_argument("H, S, V and transparency (a) values have to be between 0 and 1");
    }

    fillRGB();
}

void Color::fillHSV() {
    // Construct HSV representation.
    // Process rgb value between 0 and 1.
    float red = r / 255;
    float green = g / 255;
    float blue = b / 255;

    // Find min, max and chroma.
    float min = red < green ? (red < blue ? red : blue) : (green < blue ? green : blue);
    float max = red > green ? (red > blue ? red : blue) : (green > blue ? green : blue);
    float chroma = max - min;

    // Process hue.
    if (chroma == 0) h = 0;
    else if (max == red) h = int((green - blue) / chroma) % 6;
    else if (max == green) h = int((blue - red) / chroma) + 2;
    else if (max == blue) h = int((red - green) / chroma) + 4;
    h *= 60;

    // Process value.
    v = max;

    // Process saturation
    s = v == 0 ? 0 : (chroma / v);
}

void Color::fillRGB() {
    // Construct RGB representation.
    float chroma = (1 - abs(2 * v - 1) * s);

    int hPrime = int(h / 60);
    float x = chroma * (1 - abs((hPrime % 2) - 1));

    switch (hPrime) {
        case 1:
            r = int(chroma * 255);
            g = int(x * 255);
            b = 0;
            break;
        case 2:
            r = int(x * 255);
            g = int(chroma * 255);
            b = 0;
            break;
        case 3:
            r = 0;
            g = int(chroma * 255);
            b = int(x * 255);
            break;
        case 4:
            r = 0;
            g = int(x * 255);
            b = int(chroma * 255);
            break;
        case 5:
            r = int(x * 255);
            g = 0;
            b = int(chroma * 255);
            break;
        case 6:
            r = int(chroma * 255);
            g = 0;
            b = int(x * 255);
            break;

        default:
            r = 0;
            g = 0;
            b = 0;
            break;
    }
}
