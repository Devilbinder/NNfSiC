#ifndef NNFSC_ACTIAVTION_H_INCLUDED
#define NNFSC_ACTIAVTION_H_INCLUDED

#include <math.h>
#include "NNfsC_types.h"

//sigmoid activation function
double activation_sigmoid(double x);

//ReLU activation function
double activation_ReLU(double x);

/**@brief Gets the sum of the output layer and normalizes each output value.
 *
 * @note C can not do inline summation of arrays. This can only be done after a forward pass has been done.
 *
 * @param[in/out]   	output_layer   		Pointer the output layer struct.
 */
void activation_softmax(layer_dense_t *output_layer);

/**@brief Test function. Sums the output after activation_softmax has run on the output layer. Correct output is 1.0.
 *
 * @param[in]   	output_layer   		Pointer the output layer struct.
 */
double sum_softmax_layer_output(layer_dense_t *output_layer);

#endif // NNFSC_ACTIAVTION_H_INCLUDED
