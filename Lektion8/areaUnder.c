/*
 * Afleveringsopgave 7
 * 01-11-2021
 * by Andrzej Piotr Dudko, adudko21@student.aau.dk, SW1
 * A program that find the area under a curve with trapezoids
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void areaUnder(double a, double b, double n, double(*f)(double), char function_type);
double trap (double a, double b, double n, double (*f)(double));
double g(double x);
double h(double x);

int main(void) {
  double n;
  double (*f)(double);  // making a pointer to a funtion here
  char function;

  printf("Which function to calculate? (type 'g' or 'h')\n");
  scanf(" %c", &function);
  areaUnder(0.0, 3.14159, n, f, function);

  return 0;
}

void areaUnder(double a, double b, double n, double(*f)(double), char function_type) {
  if (function_type == 'g') {
    printf("The area under the function g(x)=x^2*sin(x) at the interval a = 0, b = 3.14159 and\n");
    f = &g;  // setting the pointer f to point at the function g
    for (n = 2.0; n <= 128; n = n*2) {
      printf("at n = %lf was found to be: %lf\n", n, trap(0.0, 3.14159, n, f));
    }
  } else if (function_type == 'h') {
    printf("The area under the function h(x)=sqrt(4-x^2) at the interval a = -2, b = 2 and\n");
    f = &h; // setting the pointer f to point at the function h
    for (n = 2.0; n <= 128; n = n*2) {
      printf("at n = %lf was found to be: %lf\n", n, trap(-2.0, 2.0, n, f));
    }
  }
}

double trap (double a, double b, double n, double (*f)(double)) {
  double h = (b-a)/n;
  double area = 0.0;
  double loop;

  double i = a;
  double j = a+h;

  for (loop = 0.0; loop < n; loop++) {
    area = area + h/2*((*f)(i)+(*f)(j));
    //printf("i = %lf, j = %lf\n", i, j); // for debugging
    i = i+h;
    j = j+h;
  }

  return area;
}

double g(double x){
  return ((x*x)*sin(x));
}

double h(double x){
  return (sqrt(4-(x*x)));
}
