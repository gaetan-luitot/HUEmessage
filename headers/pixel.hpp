#ifndef PIXEL_HPP
#define PIXEL_HPP

template <typename T>
class Pixel
{
private:
    T _value;

public:
    // Constructor :
    Pixel() {
        _value = T();
    }

    Pixel(T value) {
        _value = value;
    }

    // Getter and Setter _value :
    inline const T & value () const { return _value; };
    inline T & value () { return _value; };

};

#endif /* end of include guard: PIXEL_HPP */
