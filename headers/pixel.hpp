#ifndef PIXEL_HPP
#define PIXEL_HPP

#include <cstdint>

class Pixel
{
private:
    uint8_t _x; // R or T or ...
    uint8_t _y; // G or S or ...
    uint8_t _z; // B or L or ...
    uint8_t _a; // Alpha

public:
    // Constructor :
    Pixel(uint8_t x = 0, uint8_t y = 0, uint8_t z = 0, uint8_t a = 0);

    // Getter and Setter _x :
    inline const uint8_t & x () const { return _x; };
    inline uint8_t & x () { return _x; };

    // Getter and Setter _y :
    inline const uint8_t & y () const { return _y; };
    inline uint8_t & y () { return _y; };

    // Getter and Setter _z :
    inline const uint8_t & z () const { return _z; };
    inline uint8_t & z () { return _z; };

    // Getter and Setter _a :
    inline const uint8_t & a () const { return _a; };
    inline uint8_t & a () { return _a; };
};

#endif /* end of include guard: PIXEL_HPP */
