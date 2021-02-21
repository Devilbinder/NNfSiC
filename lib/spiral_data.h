#ifndef SPIRAL_DATA_H_INCLUDED
#define SPIRAL_DATA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "NNfsC_util.h"

typedef struct{
    double *x; /* Holds the x y axis data. Data is formated x y x y x y*/
    double *y; /* Holds the group the data belongs too. Two steps of x is a single step of y*/
}spiral_data_t;

void spiral_data(int points,int classes,spiral_data_t *data);

void deloc_spiral(spiral_data_t *data);

#endif // SPIRAL_DATA_H_INCLUDED
