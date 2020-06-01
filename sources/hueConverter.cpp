#include "../headers/hueConverter.hpp"


/*std::string const * const*/
void HueConverter::imgToMsg(Image const * const img)
{
    Image * tmpImg = new Image(*img);
    /*
    for (size_t i = 0; i < tmpImg->getWidth(); ++i)
    {
        for (size_t j = 0; j < tmpImg->getHeight(); ++j)
        {
            std::cout << tmpImg->pixel(i, j).value() << std::endl;
        }
    }
    */
    std::cout << tmpImg->pixel(0).value() << " " << tmpImg->pixel(1).value() << std::endl;
    tmpImg->swap(0, 1);
    std::cout << tmpImg->pixel(0).value() << " " << tmpImg->pixel(1).value() << std::endl;

}

void HueConverter::msgToImg(std::string const * const message)
{
    std::cout << message << std::endl;
}
