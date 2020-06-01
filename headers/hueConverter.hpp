#ifndef HUE_CONVERTER_HPP
#define HUE_CONVERTER_HPP

#include "./image.hpp"
#include <cstring>
#include <iostream>

class HueConverter
{
public:

    static void imgToMsg(Image const * const image);

    static void msgToImg(std::string const * const message);
};

#endif /* end of include guard: HUE_CONVERTER_HPP */
