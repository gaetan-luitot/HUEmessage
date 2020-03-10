#include "../headers/libPNG.hpp"

Image<Pixel> LibPNG::readPNG(std::string path)
{
    std::ifstream bits_picture(path, std::iostream::binary);

    if (!bits_picture.is_open())
    {
        std::cout << "failed to open " << path << '\n';
    }
    else
    {
        size_t counter = 0;
        while(bits_picture)
        {
            bits_picture.get();
            counter++;
            //std::cout << bits_picture.get() << std::endl;
        }
        std::cout << counter << std::endl;
    }

    Image<Pixel> img = Image<Pixel>(16, 16);

    return img;
}
