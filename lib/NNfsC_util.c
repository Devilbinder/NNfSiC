#include "NNfsC_util.h"

/**@brief Generate a random range in a uniform distribution.
 * @Note Code was lifted from here https://stackoverflow.com/questions/11641629/generating-a-uniform-distribution-of-integers-in-c
 *
 * @param[in]   rangeLow   	Lowest value that in the range that can be genarated.
 * @param[in]   rangeHigh  	Highest value that in the range that can be genarated.
 * @retval[out] rng_scaled	Random mumber that has been generated.
 */
double uniform_distribution(double rangeLow, double rangeHigh) {
    double rng = rand()/(1.0 + RAND_MAX);
    double range = rangeHigh - rangeLow + 1;
    double rng_scaled = (rng * range) + rangeLow;
    return rng_scaled;
}


// Generate a random floating point number from min to max
double rand_range(double min, double max)
{
    double range = (max - min);
    double div = RAND_MAX / range;
    return min + (rand() / div);
}
