#ifndef LIBPNG_HPP
#define LIBPNG_HPP

#include <string>
#include <fstream>
#include <exception>
#include "./pixel.hpp"
#include "./image.hpp"

class LibPNG
{
private:

public:
    static Image<Pixel> readPNG(std::string path);
};

#endif /* end of include guard: LIBPNG_HPP */
