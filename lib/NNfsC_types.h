#ifndef NNFSC_TYPES_H_INCLUDED
#define NNFSC_TYPES_H_INCLUDED

//Callback function template definition
typedef void (*actiavtion_callback)(double * output);

typedef struct{
    double *weights;    /*Neural layer network weights*/
    double *biase;      /*Neural layer network biase*/
    double *output;     /*Output of the neural layer*/
    int input_size;     /*Size of the input layer*/
    int output_size;    /*Size of the output layer*/
    actiavtion_callback callback; /* Pionter to the callback used for the activation function */
}layer_dense_t;

#endif // NNFSC_TYPES_H_INCLUDED
