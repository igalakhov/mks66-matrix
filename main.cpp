#include <iostream>
#include <zconf.h>
#include <thread>
#include "drawing/display.h"
#include "drawing/drawer.h"
#include "matrix/edge_matrix.h"
#include "matrix/transformation_matrix.h"


void matrix_tests(){
    std::cout << "Setting the value for A\n";
    float_mat * vals = new float_mat[16]{
            1, 2, 3, 4,
            5, 6, 7, 8,
            9, 10, 11, 12,
            13, 14, 15, 16
    };
    TransformationMatrix * A = new TransformationMatrix(vals);
    std::cout << "Setting the value for B\n";
    EdgeMatrix * B = new EdgeMatrix();
    B->add_point(11, 15, 19, 23);
    B->add_point(12, 16, 20, 24);
    B->add_point(13, 17, 21, 25);
    B->add_point(14, 18, 22, 26);
    B->print_self();

    std::cout << "Multiplying A by B ans saving the result in B\n";
    B->apply_transformation(A);
    std::cout << "Printing A\n";
    A->print_self();
    std::cout << "Printing B\n";
    B->print_self();

    // swap a and b (ew)
    EdgeMatrix * new_A = EdgeMatrix::from_transformation(A);
    TransformationMatrix * new_B = TransformationMatrix::from_edge(B);

    std::cout << "Multiplying B by A and saving the result in A\n";

    new_A->apply_transformation(new_B);

    std::cout << "Printing A\n";
    new_A->print_self();
    std::cout << "Printing B\n";
    new_B->print_self();

    TransformationMatrix * IDENT = TransformationMatrix::identity();

    std::cout << "Multiplying A by identity matrix and saving the result in A\n";
    new_A->apply_transformation(IDENT);
    std::cout << "Printing A\n";
    new_A->print_self();


    delete new_A;
    delete new_B;
    delete A;
    delete B;
    delete IDENT;
}


void draw_prism(Drawer * d, int x, int y, int z, int w, int h, int l){
    // picture stuff
    EdgeMatrix * m = new EdgeMatrix();

    m->add_edge(x, y, z, x + w, y, z);
    m->add_edge(x + w, y, z, x + w, y + h, z);
    m->add_edge(x + w, y + h, z, x, y + h, z);
    m->add_edge(x, y + h, z, x, y, z);

    m->add_edge(x + w, y, z, x + w, y, z + l);
    m->add_edge(x, y + h, z, x, y + h, z + l);
    m->add_edge(x + w, y + h, z, x + w, y + h, z + l);
    m->add_edge(x, y, z, x, y, z + l);

    m->add_edge(x, y, z + l, x + w, y, z + l);
    m->add_edge(x + w, y, z + l, x + w, y + h, z + l);
    m->add_edge(x + w, y + h, z + l, x, y + h, z + l);
    m->add_edge(x, y + h, z + l, x, y, z + l);

    m->translate(-x - w/2, -y - h/2, -z - l/2);

    m->rotateXYZ(std::rand(), std::rand(), std::rand());

    m->translate(x + w/2, y + h/2, z + l/2);


    d->draw_edges(m);

    delete m;
}


int main(){
    std::srand(std::time(NULL));


    matrix_tests();

    EdgeMatrix * m = new EdgeMatrix();
    Drawer * d = new Drawer;

    int rects[][6] = {{50, 50, -25, 50, 150, 50},
                      {250, 50, -25, 50, 150, 50},
                      {350, 100, -25, 50, 100, 50},
                      {50, 300, -25, 50, 150, 50},
                      {150, 300, -25, 50, 150, 50},
                      {250, 300, -25, 50, 150, 50},
                      {350, 400, -25, 100, 50, 50}};

    for(int i = 0; i < 7; i++){
        int * cur = rects[i];

        draw_prism(d, cur[0], cur[1], cur[2], cur[3], cur[4], cur[5]);
    }

    d->save("out.ppm");


    delete m;
    delete d;

    return 0;
}