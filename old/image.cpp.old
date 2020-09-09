#include "../headers/image.hpp"

Image::Image(uint16_t w, uint16_t h) : _width(w) , _height(h)
{
    _array = new Pixel<int>[_width * _height];
}

// Constructeur par copie :
Image::Image(const Image & o ) : Image(o._width, o._height)
{
    // On recopie le tableau de la copie :
    for (size_t i = 0; i < _width * _height; ++i)
    {
        _array[i] = o._array[i];
    }
    /*
    -/ Si on ne fait pas ça nos images auront juste la même taille en commun.
    -/ Et on assigne pas les pointeurs entre eux,
    -/ car on ne veut pas que nos deux images partagent le même tableau.
    */
}

void Image::clear(int value)
{
    for (size_t i = 0; i < _height; ++i) {
        for (size_t j = 0; j < _width; ++j) {
            _array[i * _height + j].value() = value;
        }
    }
}

void Image::swap(uint16_t a, uint16_t b)
{
    Pixel<int> * c = new Pixel<int>(_array[a]);

    _array[a] = _array[b];
    _array[b] = *c;

    delete c;
}
