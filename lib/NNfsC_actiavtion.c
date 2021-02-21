#include "NNfsC_actiavtion.h"


//sigmoid activation function
double activation_sigmoid(double x) {
     double result;
     result = 1 / (1 + exp(-x));
     return result;
}

//ReLU activation function
double activation_ReLU(double x){
    if(x < 0.0){
       x = 0.0;
    }
    return x;
}


/**@brief Gets the sum of the output layer and normalizes each output value.
 *
 * @note C can not do inline summation of arrays. This can only be done after a forward pass has been done.
 *
 * @param[in/out]   	output_layer   		Pointer the output layer struct.
 */
void activation_softmax(layer_dense_t *output_layer){
    double sum = 0.0;
    double maxu = 0.0;
    int i = 0;

    maxu = output_layer->output[0];
    for(i = 1; i < output_layer->output_size;i++){
        if(output_layer->output[i] > maxu){
            maxu = output_layer->output[i];
        }
    }

    for(i = 0; i < output_layer->output_size;i++){
        output_layer->output[i] = exp(output_layer->output[i] - maxu);
        sum += output_layer->output[i];
    }

    for(i = 0; i < output_layer->output_size;i++){
        output_layer->output[i] = output_layer->output[i] / sum;
    }
}

/**@brief Test function. Sums the output after activation_softmax has run on the output layer. Correct output is 1.0.
 *
 * @param[in]   	output_layer   		Pointer the output layer struct.
 */
double sum_softmax_layer_output(layer_dense_t *output_layer){
    double sum = 0.0;
    int i = 0;

    for(i = 0; i < output_layer->output_size;i++){
        sum += output_layer->output[i];
    }

    return sum;

}
