#ifndef NNFSC_H_INCLUDED
#define NNFSC_H_INCLUDED

#include <math.h>
#include "NNfsC_types.h"
#include "NNfsC_actiavtion.h"
#include "NNfsC_config.h"
#include "spiral_data.h"

/**@brief Setup a layer with random weights and bais as well as allocating memory for the storage buffers.
 *
 * @param[in]   	layer   		Pointer to an empty layer with no values.
 * @param[in]   	intput_size  	Size of the input layer.
 * @param[in]   	output_size	 	Size of the output layer.
 */
void layer_init(layer_dense_t *layer,int intput_size,int output_size);

/**@brief Does a forward pass in the network from one layer to the next.
 *
 * @param[in]   	previos_layer   		Pointer the previos layer struct.
 * @param[in]   	next_layer  			Pointer the next layer struct.
 */
void forward(layer_dense_t *previos_layer,layer_dense_t *next_layer);

//free the memory allocated by a layer
void deloc_layer(layer_dense_t *layer);



#endif // NNFSC_H_INCLUDED
