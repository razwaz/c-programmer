#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define DELTA 0.1

int main(void) {
  double r = 1;
  double x;
  double y;
  printf("Please enter coordinates: ");
  scanf(" %lf %lf", &x, &y );

  double dist = sqrt((x*x)+(y*y));

  if (dist >= r - DELTA && dist <= r + DELTA){
    printf("hit \n");
  } else {
    printf("miss \n");
  }
}
