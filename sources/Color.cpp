/*
 * Color.cpp
 *
 *  Created on: 23 mai 2020
 *      Author: marsevil
 */

#include "../headers/Color.hpp"

const float Color::RGB2TSL[] = {0.2627, 0.6780, 0.0593};

/**
 * Check if values set by the user are correct.
 */
void Color::validateRGBConfig() {
    // Check arguments values
    if (a < 0 || a > 1) {
        throw std::invalid_argument("Transparency value a, have to be between 0 and 1");
    }
}

/**
 * Check if values set by the user are correct.
 */
void Color::validateHSVConfig() {
    // Check argument values.
    if (h < 0 || h > 360) {
        throw std::invalid_argument("H value have to be between 0 and 360");
    }
    if (s < 0 || s > 1) {
        throw std::invalid_argument("S value have to be between 0 and 1");
    }
    if (l < 0 || l > 1) {
        throw std::invalid_argument("V value have to be between 0 and 1");
    }
    if (a < 0 || a > 1) {
        throw std::invalid_argument("A value have to be between 0 and 1");
    }
}

Color::Color(uint8_t _r, uint8_t _g, uint8_t _b, float _a)
: r(_r), g(_g), b(_b), h(0), s(0), l(0), a(_a) {
    validateRGBConfig();
    fillHSV();
}

Color::Color(float _h, float _s, float _l, float _a)
: r(0), g(0), b(0), h(_h), s(_s), l(_l), a(_a){
    validateHSVConfig();
    fillRGB();
}

/**
 * Construct HSV represenation from RGB values.
 */
void Color::fillHSV() {
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

    // Process lightness.
    l = (min + max) / 2;

    // Process saturation
    s = chroma == 0 ? 0 : chroma / (1 - std::abs(2 * l - 1));
}

/**
 * Construct RGB representation from TSL values.
 */
void Color::fillRGB() {
    float chroma = (1 - std::abs(2*l - 1)) * s;

    float hDivided = h / 60;
    float dec = hDivided - int(hDivided);
    float x = chroma * (1 - std::abs((int(std::floor(hDivided)) % 2 + dec) - 1));

    float m = l - chroma/2;

    float rP, gP, bP;

    if (0 <= h && h < 60) {
      rP = chroma;
      gP = x;
      bP = 0;
    } else if (60 <= h && h < 120) {
      rP = x;
      gP = chroma;
      bP = 0;
    } else if (120 <= h && h < 180) {
      rP = 0;
      gP = chroma;
      bP = x;
    } else if (180 <= h && h < 240) {
      rP = 0;
      gP = x;
      bP = chroma;
    } else if (240 <= h && h < 300) {
      rP = x;
      gP = 0;
      bP = chroma;
    } else if (300 <= h && h < 360) {
      rP = chroma;
      gP = 0;
      bP = x;
    } else {
      validateHSVConfig();
    }

    r = std::floor((rP + m) * 255);
    g = std::floor((gP + m) * 255);
    b = std::floor((bP + m) * 255);
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

void Color::setL(float _l) {
    l = _l;
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

void Color::setHSL(float _h, float _s, float _l, float _a) {
    h = _h;
    s = _s;
    l = _l;
    a = _a;
    validateHSVConfig();
    fillRGB();
}
