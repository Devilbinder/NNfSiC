#include <stdio.h>
#include <stdlib.h>

#include "NNfsC.h"

void actiavtion1(double *data){
    *data = activation_ReLU(*data);
}
int main()
{
    srand(0);

    int i = 0;
    int j = 0;
    spiral_data_t X_data;
    layer_dense_t X;
    layer_dense_t dense1;
    layer_dense_t dense2;

    spiral_data(100,3,&X_data);
    if(X_data.x == NULL){
        printf("data null\n");
        return 0;
    }

    X.callback = NULL;

    dense1.callback = actiavtion1;

    dense2.callback = NULL;

    layer_init(&dense1 ,NET_INPUT_LAYER_1_SIZE,NET_INPUT_LAYER_2_SIZE);
    layer_init(&dense2,NET_INPUT_LAYER_2_SIZE,NET_OUTPUT_LAYER_SIZE);


    for(i = 0; i < NET_BATCH_SIZE;i++){
        X.output = &X_data.x[i*2];
        forward(&X,&dense1);
       /* printf("batch: %d layer1_output: ",i);
        for(j = 0; j < dense1 .output_size; j++){
            printf("%f ",dense1 .output[j]);
        }*/
        forward(&dense1,&dense2);

        /*printf("batch: %d layer2_output: ",i);
        for(j = 0; j < dense2.output_size; j++){
            printf("%f ",dense2.output[j]);
        }
        printf("\n");*/


        activation_softmax(&dense2);

        printf("batch: %d layer2_softmax: ",i);
        for(j = 0; j < dense2.output_size; j++){
            printf("%f ",dense2.output[j]);
        }
        printf("\n");
        //printf("batch: %d layer2_normalize_sum: %f\n",i,sum_softmax_layer_output(&dense2));
    }


    deloc_layer(&dense1);
    deloc_layer(&dense2);
    deloc_spiral(&X_data);


    return 0;
}
