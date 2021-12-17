/*
 * Eksamensopgave 1
 * 17-12-2021
 * by Andrzej Piotr Dudko, adudko21@student.aau.dk, SW1
 * A calculator program
 */

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void run_calculator(double *accumulator, double *operand, char *operator, bool *run);

void scan_data(char *operator, double *operand);
void do_next_op(double *accumulator, char *operator, double *operand, bool *run);
void print(double *accumulator, char *operator);
bool unary(char *operator);

double add(double *accumulator, double *operand);
double subtract(double *accumulator, double *operand);
double multiply(double *accumulator, double *operand);
double divide(double *accumulator, double *operand);
double power(double *accumulator, double *operand);

double squareRoot(double *accumulator);
double invertSign(double *accumulator);
double dividend(double *accumulator);

bool quit(bool exit);

int main(void) {
  double accumulator = 0.0;
  double operand;
  char operator;
  bool run = true;

  run_calculator(&accumulator, &operand, &operator, &run);

  return 0;
}

// general program functions
void run_calculator (double *accumulator, double *operand, char *operator, bool *run) {
  while (*run) {
    scan_data(&*operator, &*operand);
    do_next_op(&*accumulator, &*operator, &*operand, &*run);
  }
}

void scan_data (char *operator, double *operand) {
  printf("Enter operator, and an optional operand: ");
  *operand = 0;
  scanf(" %c", &*operator);
  if (unary(&*operator) == true) {
  } else {
    scanf("%lf", &*operand);
  }
}

void do_next_op (double *accumulator, char *operator, double *operand, bool *run) {

  switch (*operator) {
    case '+':
    *accumulator = add(&*accumulator, &*operand); break;
    case '-':
    *accumulator = subtract(&*accumulator, &*operand); break;
    case '*':
    *accumulator = multiply(&*accumulator, &*operand); break;
    case '/':
    *accumulator = divide(&*accumulator, &*operand); break;
    case '^':
    *accumulator = power(&*accumulator, &*operand); break;
    case '#':
    *accumulator = squareRoot(&*accumulator); break;
    case '%':
    *accumulator = invertSign(&*accumulator); break;
    case '!':
    *accumulator = dividend(&*accumulator); break;
    case 'q':
    *run = quit(*run); break;
  }

  print(&*accumulator, &*operator);
}

bool unary(char *operator) {
  if (*operator == '#' || *operator == '%' || *operator == '!'|| *operator == 'q') {
    return true;
  } else {
    return false;
  }
}

void print(double *accumulator, char *operator) {
  if (*operator == 'q') {
    printf(
    "----------------------------------------------\n"
    "Final result is: %lf\n"
    "----------------------------------------------\n"
    , *accumulator);
  } else {
    printf(
    "----------------------------------------------\n"
    "Result so far is: %lf\n"
    "----------------------------------------------\n"
    , *accumulator);
  }
}

// functions for binary operations
double add(double *accumulator, double *operand) {
  return (*accumulator + *operand);
}

double subtract(double *accumulator, double *operand) {
  return (*accumulator - *operand);
}

double multiply(double *accumulator, double *operand) {
  return (*accumulator * *operand);
}

double divide(double *accumulator, double *operand) {
  if (*operand == 0) {
    return *accumulator;
  } else {
    return (*accumulator / *operand);
  }
}

double power(double *accumulator, double *operand) {
  if (*accumulator < 0) {
    return -pow(*accumulator, *operand);
  } else {
  return pow(*accumulator, *operand);
  }
}


// functions for unary opertaions
double squareRoot(double *accumulator) {
  if (*accumulator < 0) {
    return *accumulator;
  } else {
    return (sqrt(*accumulator));
  }
}

double invertSign(double *accumulator) {
  return (-*accumulator);
}

double dividend(double *accumulator) {
  if (*accumulator != 0) {
    return (1/(*accumulator));
  } else {
    return *accumulator;
  }
}

// function for ending the calculator
bool quit(bool exit) {
  return exit = false;
}
