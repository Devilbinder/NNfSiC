#ifndef NNFSC_UTIL_H_INCLUDED
#define NNFSC_UTIL_H_INCLUDED

#include <stdlib.h>

#define RAND_HIGH_RANGE (0.10)
#define RAND_MIN_RANGE (-0.10)

/**@brief Generate a random range in a uniform distribution.
 * @Note Code was lifted from here https://stackoverflow.com/questions/11641629/generating-a-uniform-distribution-of-integers-in-c
 *
 * @param[in]   rangeLow   	Lowest value that in the range that can be genarated.
 * @param[in]   rangeHigh  	Highest value that in the range that can be genarated.
 * @retval[out] rng_scaled	Random mumber that has been generated.
 */
double uniform_distribution(double rangeLow, double rangeHigh);

// Generate a random floating point number from min to max
double rand_range(double min, double max);


#endif // NNFSC_UTIL_H_INCLUDED
