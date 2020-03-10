#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <fstream>
#include <cstdint>
#include <iostream>

/*
    template d'une Image :
*/
template <typename T>
class Image
{
protected:
    const uint16_t _width, _height;
    uint16_t max_c = 255;
    T * _array;

public:

    // On ne veut pas de Constructeur par défaut :
    Image() = delete;

    // Ni de
    Image & operator=(const Image & b ) = delete;

    // Constructeur :
    Image(uint16_t width, uint16_t height) : _width(width), _height(height), _array(nullptr)
    {
        _array = new T[_width * _height];
    }

    // Constructeur par copie :
    Image(const Image & o ) : Image(o._width, o._height)
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

    // Destructeur :
    ~Image()
    {
        delete[] _array;
    }

    // GETTERS :
    inline const uint16_t & getWidth ( ) const { return _width ; }
    inline const uint16_t & getHeight ( ) const { return _height ; }
    inline T & pixel ( uint16_t x , uint16_t y ) { return _array[ y * _width + x ] ; }
    inline const uint32_t & getSize ( ) const { return _width * _height ; }

    // SETTERS :
    inline const T & pixel ( uint16_t x, uint16_t y ) const { return _array[ y * _width + x ] ; }
    inline T const * const pixels () const { return _array; }

    void clear(T c = T{0})
    {
        for (size_t i = 0; i < (size_t)_width * _height; ++i)
        {
            *(_array+i) = c;
        }
    }

};

// Méthodes statiques, externes au template :
void skip_line(std::istream & is);
void skip_comments(std::istream & is);
uint16_t char2int(char * c);
char * int2char(uint16_t i);
#endif /* end of include guard: IMAGE_HPP */
