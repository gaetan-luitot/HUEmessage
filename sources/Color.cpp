/*
 * Color.cpp
 *
 *  Created on: 23 mai 2020
 *      Author: marsevil
 */

#include "../headers/Color.hpp"

const float Color::RGB2TSL[] = {0.2627, 0.6780, 0.0593};

void Color::validateRGBConfig() {
    // Check arguments values
    if (a < 0 || a > 1) {
        throw std::invalid_argument("Transparency value a, have to be between 0 and 1");
    }
}

void Color::validateHSVConfig() {
    // Check argument values.
    if (h < 0 || h > 360) {
        throw std::invalid_argument("H value have to be between 0 and 360");
    }
    if (s < 0 || s > 1) {
        throw std::invalid_argument("S value have to be between 0 and 1");
    }
    if (v < 0 || v > 1) {
        throw std::invalid_argument("V value have to be between 0 and 1");
    }
    if (a < 0 || a > 1) {
        throw std::invalid_argument("A value have to be between 0 and 1");
    }
}

Color::Color(uint8_t _r, uint8_t _g, uint8_t _b, float _a)
: r(_r), g(_g), b(_b), a(_a), h(0), s(0), v(0) {
    validateRGBConfig();
    fillHSV();
}

Color::Color(float _h, float _s, float _v, float _a)
: h(_h), s(_s), v(_v), a(_a), r(0), g(0), b(0){
    validateHSVConfig();
    fillRGB();
}

void Color::fillHSV() {
    // Construct HSV representation.
    // Process rgb value between 0 and 1.
    float red = (float)r / 255;
    float green = (float)g / 255;
    float blue = (float)b / 255;

    // Find min, max and chroma.
    //float min = red < green ? (red < blue ? red : blue) : (green < blue ? green : blue);
    //float max = red > green ? (red > blue ? red : blue) : (green > blue ? green : blue);
    float min = std::min(std::min(red, green), blue);
    float max = std::max(std::max(red, green), blue);
    float chroma = max - min;

    // Process hue.
    if (chroma == 0) h = 0;
    else if (max == red) h = ((green - blue) / chroma);
    else if (max == green) h = ((blue - red) / chroma) + 2;
    else if (max == blue) h = ((red - green) / chroma) + 4;
    h *= 60;
    if (h < 0) h += 360;

    // Process value.
    v = max;

    // Process saturation
    s = v == 0 ? 0 : (chroma / max);
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

void Color::setR(uint8_t _r) {
    r = _r;
    validateRGBConfig();
    fillHSV();
}

void Color::setG(uint8_t _g) {
    g = _g;
    validateRGBConfig();
    fillHSV();
}

void Color::setB(uint8_t _b) {
    b = _b;
    validateRGBConfig();
    fillHSV();
}

void Color::setH(float _h) {
    h = _h;
    validateHSVConfig();
    fillRGB();
}

void Color::setS(float _s) {
    s = _s;
    validateHSVConfig();
    fillRGB();
}

void Color::setV(float _v) {
    v = _v;
    validateHSVConfig();
    fillRGB();
}

void Color::setRGB(uint8_t _r, uint8_t _g, uint8_t _b, float _a) {
    r = _r;
    g = _g;
    b = _b;
    a = _a;
    validateRGBConfig();
    fillHSV();
}

void Color::setHSL(float _h, float _s, float _v, float _a) {
    h = _h;
    s = _s;
    v = _v;
    a = _a;
    validateHSVConfig();
    fillRGB();
}
