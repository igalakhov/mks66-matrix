//
// Created by Ivan Galakhov on 2019-02-19.
//

#include "transformation_matrix.h"

#include <iostream>


float_mat * TransformationMatrix::get_start() {
    return vals;
}

void TransformationMatrix::make_identity() {
    make_zero();

    float_mat * cur = vals;

    for(int i = 0; i < 4; i++){
        *cur = 1;
        cur += 5;
    }
}
void TransformationMatrix::make_zero() {
    float_mat * cur = vals;

    for(int i = 0; i < 16; i++){
       cur[i] = 0;
    }
}

void TransformationMatrix::print_self() {
    std::cout << "[\n";
    for(int i = 0; i < 16; i++){

        if(vals[i] < 10) {
            std::cout << vals[i] << "   ";
        } else if(vals[i] < 100){
            std::cout << vals[i] << "  ";
        } else {
            std::cout << vals[i] << " ";
        }


        if((i+1) % 4 == 0)
            std::cout << "\n";
    }
    std::cout << "]\n";
}

// constructor
TransformationMatrix::TransformationMatrix() {
    vals = (float_mat *) std::malloc(16 * sizeof(float_mat));

    make_identity();
}

// constructor 2
TransformationMatrix::TransformationMatrix(float_mat * v){
    vals = (float_mat *) std::malloc(16 * sizeof(float_mat));
    for(int i = 0; i < 16; i++){
        vals[i] = v[i];
    }

    delete v;
}

// static constructor thingy
TransformationMatrix * TransformationMatrix::from_edge(EdgeMatrix * m) {
    assert(m->get_size() >= 4);
    float_mat * p = m->get_start();
    TransformationMatrix * ret = new TransformationMatrix(new float_mat[16]{
        p[0], p[4], p[8], p[12],
        p[1], p[5], p[9], p[13],
        p[2], p[6], p[10], p[14],
        p[3], p[7], p[11], p[15]
    });

    return ret;
}

// static constructor thingy 2
TransformationMatrix * TransformationMatrix::identity(){
    TransformationMatrix * ret = new TransformationMatrix();
    ret->make_identity();
    return ret;
}

// static constructor thingy 3
TransformationMatrix * TransformationMatrix::zero(){
    TransformationMatrix * ret = new TransformationMatrix();
    ret->make_zero();
    return ret;
}

// destructor
TransformationMatrix::~TransformationMatrix() {
    std::free(vals);
}