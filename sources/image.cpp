#include "../headers/image.hpp"

void skip_line(std::istream & is)
{
    char tmp;
    is >> tmp;
    while (tmp != '\n')
    {
        is.get(tmp);
    }
}

void skip_comments(std::istream & is)
{
    char read;
    is.get(read);
    while (read == '#')
    {
        skip_line(is);
        is.get(read);
    }
    is.putback(read);
}

uint16_t char2int(char * c)
{
    uint16_t p = 0;
    for (size_t i = 0; i < 3; i++)
    {
        if (c[i] == 'X')
            p++;
        //std::cout << "i : "<< i << " | p : "<<  p << std::endl;
    }

    if (p == 0)
        return ((int)c[0]-48) * 100 + ((int)c[1]-48) * 10 + ((int)c[2]-48);
    else if (p == 1)
        return ((int)c[0]-48) * 10 + ((int)c[1]-48);
    else if (p == 2)
        return ((int)c[0]-48);
    else if (p == 3)
        return 0;
    else
        throw std::runtime_error("char2int : To much X");
 }

char * int2char(uint16_t i)
{
    return new char[3] {int(i/100) == 0? (char)32:char(i/100+48), int(i/100) == 0 && int((i%100))/10 == 0?(char)32:char((i%100)/10+48), char((i%100)%10+48)};
}
