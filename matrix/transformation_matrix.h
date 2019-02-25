//
// Created by Ivan Galakhov on 2019-02-19.
//

#ifndef WORK_01_LINE_TRANSFORMATION_MATRIX_H
#define WORK_01_LINE_TRANSFORMATION_MATRIX_H

#include "edge_matrix.h"


#define float_mat float

class EdgeMatrix;
class TransformationMatrix {
public:
    TransformationMatrix(); // constructor
    TransformationMatrix(float_mat *); // constructor 2: electric boogaloo
    ~TransformationMatrix(); // destructor

    void print_self(); // print self

    float_mat * get_start();

    void make_identity();
    void make_zero();

    static TransformationMatrix * from_edge(EdgeMatrix *);
    static TransformationMatrix * identity();
    static TransformationMatrix * zero();

private:
    float_mat * vals; // ROW MAJOR!!!

};


#endif //WORK_01_LINE_TRANSFORMATION_MATRIX_H
