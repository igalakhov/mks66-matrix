#include <iostream>
#include "display.h"
#include "drawer.h"

using namespace std;

#define NUM_LINES 15

int main() {
    Drawer * drawer = new Drawer();

    for(int i = 0; i < 1000; i++);

    drawer->change_color(100, 123, 87);
    // lines
    for(int i = 0; i < NUM_LINES; i++){
        drawer->draw_line(0, i * 500/NUM_LINES, i * 500/NUM_LINES, 499);
    }

    drawer->change_color(112, 244, 62);
    // more lines
    for(int i = 0; i < NUM_LINES; i++){
        drawer->draw_line(i * 500/NUM_LINES, 0, 499,  i * 500/NUM_LINES);
    }

    drawer->change_color(0, 255, 255);

    // loss
    drawer->draw_rectangle(50, 50, 50, 150);
    drawer->draw_rectangle(250, 50, 50, 150);
    drawer->draw_rectangle(350, 100, 50, 100);
    drawer->draw_rectangle(50, 300, 50, 150);
    drawer->draw_rectangle(150, 300, 50, 150);
    drawer->draw_rectangle(250, 300, 50, 150);
    drawer->draw_rectangle(350, 400, 100, 50);


    // save
    drawer->save("out.ppm");

    delete drawer; // delete
    return 0;
}