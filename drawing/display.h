#include <iostream>
#include <cassert>


#include "../settings.h"

#ifndef WORK_01_LINE_DISPLAY_H
#define WORK_01_LINE_DISPLAY_H

struct color {
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

class Display {
public:
    void save(std::string);  // save into file

    Display(); // constructor
    ~Display(); // destructor

    void set(int, int, struct color *); // set a pixel to a value


protected:

private:
    unsigned char * values; // pixel values (1d array because I'm cool)

};


#endif //WORK_01_LINE_DISPLAY_H
