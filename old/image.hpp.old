#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <fstream>
#include <cstdint>
#include <iostream>

#include "./pixel.hpp"

class Image
{
protected:
    uint16_t const _width, _height;
    // uint16_t max_c = 255;
    Pixel<int> * _array;

public:
    Image() = delete;

    Image(uint16_t w, uint16_t h);

    Image(const Image & o);

    // Destructeur :
    ~Image()
    {
        delete[] _array;
    }

    // GETTERS :
    inline const uint16_t & getWidth () const { return _width ; }
    inline const uint16_t & getHeight () const { return _height ; }
    inline Pixel<int> & pixel (uint16_t x , uint16_t y ) { return _array[ y * _width + x ] ; }
    inline Pixel<int> & pixel (uint32_t i) { return _array[i] ; }
    inline uint32_t getSize () const { return _width * _height ; }

    // SETTERS :
    inline const Pixel<int> & pixel ( uint16_t x, uint16_t y ) const { return _array[ y * _width + x ] ; }
    inline const Pixel<int> & pixel (uint32_t i) const { return _array[i] ; }
    inline Pixel<int> const * const pixels () const { return _array; }
    void clear(int value);
    void swap(uint16_t a, uint16_t b);
};

#endif /* end of include guard: IMAGE_HPP */
