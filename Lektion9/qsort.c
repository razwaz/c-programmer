#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

int element_compare(const void *ip1, const void *ip2);
double double_compare(const double d1, const double d2);

int main(void) {
  srand(time(NULL));
  double *store = malloc(N * sizeof(double));
  int i;

  if (store == NULL){
    printf("Cannot allocate sufficient memory. Bye\n");
    exit(EXIT_FAILURE);
  }

  for(i = 0; i < N; ++i)
    store[i] = (double)(rand())/3.0;

  for(i = 0; i < N; ++i){
    printf("%8.3f  ", store[i]);
    if (i%5 == 0) printf("\n");
  }

  qsort(store, N, sizeof(double), element_compare);

  printf("\n");
  for(i = 0; i < N; ++i){
    printf("%8.3f  ", store[i]);
    if (i%5 == 0) printf("\n");
  }

  free(store);

  return 0;
}

int element_compare(const void *ip1, const void *ip2){
  double *ipi1 = (double *)ip1,
         *ipi2 = (double *)ip2;

  return double_compare(*ipi1, *ipi2);
}

double double_compare(const double d1, const double d2){
  if (d1 < d2)
    return -1;
  else if (d1 > d2)
    return 1;
  else
    return 0;
}
