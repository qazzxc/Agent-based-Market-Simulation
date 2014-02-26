#ifndef __UTL__
#define __UTL__
#include <stdio.h>
#include<time.h>
#include <math.h>
#include "MT.h"

#define p(x, y) printf(x, y)
#define puts(x) printf("%s\n",x)
#define puti(x) printf("%d\n",x)
#define putl(x) printf("%ld\n",x)
#define putd(x) printf("%lf\n",x)

double init_rand(int * myid)
{
struct timeval t0;
gettimeofday(&t0, NULL);


  init_genrand(t0.tv_usec*(*myid + 1));
//  srand(tv.tv_usec * (*myid + 1));
  return 0;
}

double urand()
{
  return genrand_real3();
  
}

double grand()
{


    return sqrt( -2.0 * log(urand() )) * sin( 2.0 * M_PI * urand() );

/*  return 2*(urand()-0.5);

    double tmp=((double)rand()+1.0)/((double)RAND_MAX+2.0);
    
    return 2*(tmp-0.5);
*/

}

double max(double * values, int size)
{
  double max;
  double * value;
  for(value = values, max = *value; size--; ++value)
    max = max > *value ? max : *value;

  return max;
}

double min(double * values, int size)
{
  double min = *values;
  double * value;
  for(value = values, min = *value; size--; ++value)
    min = min < *value ? min : *value;

  return min;
}
#endif

