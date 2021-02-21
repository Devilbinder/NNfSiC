#include "spiral_data.h"

/**@brief Generate a random range in a uniform distribution.
 * @Note Credit to shreeviknesh (#106) saved alot of time.
 *
 * @param[in]   points   	Number of points to generate per class.
 * @param[in]   classes  	Number of classes to generate.
 * @param[out]  data	    Structure holding the generated spiral data.
 */
void spiral_data(int points,int classes,spiral_data_t *data){

    data->x = (double*)malloc(sizeof(double)*points*classes*2);
    if(data->x == NULL){
        printf("data mem error\n");
        return;
    }
    data->y = (double*)malloc(sizeof(double)*points*classes);
    if(data->y == NULL){
        printf("pionts mem error\n");
        return;
    }
    int ix = 0;
    int iy = 0;
    int class_number = 0;
    for(class_number = 0; class_number < classes; class_number++) {
		double r = 0;
		double t = class_number * 4;

		while(r <= 1 && t <= (class_number + 1) * 4) {
			// adding some randomness to t
			double random_t = t + uniform_distribution(-1.0,1.0) * 0.2;

			// converting from polar to cartesian coordinates
			data->x[ix] = r * sin(random_t * 2.5);
			data->x[ix+1] = r * cos(random_t * 2.5);

			data->y[iy] = class_number;


			// the below two statements achieve linspace-like functionality
			r += 1.0f / (points - 1);
			t += 4.0f / (points - 1);
			iy++;
			ix+=2; // increment index
		}
	}
}




/**@brief Free the allocated memory for the spiral data.
 *
 * @param[in]  data	    Structure holding the generated spiral data.
 */
void deloc_spiral(spiral_data_t *data){
    if(data->x != NULL){
        free(data->x);
    }
     if(data->y != NULL){
        free(data->y);
    }
}
