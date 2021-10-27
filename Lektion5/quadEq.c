// by Andrzej Piotr Dudko, E21 SW1, AAU
// 14-10-2021
// A program that finds discriminants and roots of quadratic equations.
// An exercise in top-down programming and stepwise refinement.

#include <stdio.h>
#include <math.h>

// Prototypes, written here so the program knows they exist
void solveQuadraticEquation(double a, double b, double c);
double findDiscriminant(double a, double b, double c);
double findRoot1(double a, double b, double c);
double findRoot2(double a, double b, double c);
void results(double a, double b, double c);

int main(void) {
  double a = 1.0, b = -8.0, c = 15.0,
  d = 2.0, e =  8.0, f =  2.0,
  g, h, i,
  amod = 0.0, bmod = 0.0, cmod = 0.0;

  /* First call - coefficents are values of variables */
  results(a, b, c);

  /* Second call - coefficents are values of expressions */
  results(d-1, -e, 7 * f + 1);

  /* Third call - coefficents are entered by user outside solveQuadraticEquation */
  printf("Enter coeficients a, b, and c: ");
  scanf("%lf %lf %lf", &g, &h, &i);
  results(g, h, i);


  /* I have no idea what im supposed to do, its an attempt to follow this intstruction:
  Programmer endvidere main således at solveQuadraticEquation kaldes i en løkke.
  I denne løkke skal de tre koeficienter a, b og c indlæses. Afslut løkken når
  alle de tre indlæste koeficienter a, b og c er lig med 0. Dette kan gøres med
  en sentinel-controlled loop. Løs ligningen (inden i løkken) i de tilfælde,
  hvor det giver mening.

  I also had a problem where if eg. amod-- was changed to amod =+ 0.1 then
  a+amod will never be considered as == 0 and make the loop infinite */

  printf("The sentinel controlled solveQuadraticEquation loop:\n");
  while (a+amod != 0.0 || b+bmod != 0.0 || c+cmod != 0.0) {

    if (a+amod == 0.0) {

    } else {
      solveQuadraticEquation(a + amod, b + bmod, c + cmod);
    }
    if (a+amod > 0.0) {
      amod--;
    } else if (a+amod < 0.0) {
      amod++;
    }

    if (b+bmod > 0) {
      bmod--;
    } else  if (b+bmod < 0) {
      bmod++;
    }

    if (c+cmod > 0) {
      cmod--;
    } else if (c+cmod < 0) {
      cmod++;
    }

    // For debugging
    //printf("a = %f, b = %f, c = %f\n", a+amod, b+bmod, c+cmod);
  }

  return 0;
}

/* Prints roots of the quadratic equation a * x*x + b * x + c = 0 */
void solveQuadraticEquation(double a, double b, double c){
  double discriminant, root1, root2;

  discriminant = b * b - 4 * a * c;

  if (discriminant < 0)
  printf("No roots\n");
  else if (discriminant == 0){
    root1 = -b/(2*a);
    printf("One root: %f\n", root1);
  }
  else {
    root1 = (-b + sqrt(discriminant))/(2*a);
    root2 = (-b - sqrt(discriminant))/(2*a);
    printf("Two roots: %f and %f\n", root1, root2);
  }
}

double findDiscriminant(double a, double b, double c) {
  double discriminant;
  discriminant = b * b - 4 * a * c;
  return discriminant;
}

double findRoot1(double a, double b, double c) {
  double root1;

  if (findDiscriminant(a, b, c) == 0) {
    root1 = - b / (2 * a);
  } else {
    root1 = (-b + sqrt(findDiscriminant(a, b, c)))/(2*a);
  }

  return root1;
}

double findRoot2(double a, double b, double c) {
  double root2;
  root2 = (-b - sqrt(findDiscriminant(a, b, c)))/(2*a);
  return root2;
}

void results(double a, double b, double c) {
  printf("Results from the quadratic equation '%fx^2 + %fx + %f = 0' by 'solveQuadraticEquation':\n", a, b, c);
  solveQuadraticEquation(a, b, c);
  printf("Results by custom functions:\n"
         "The discriminant is: %f\n"
         "The first root is: %f\n"
         "The second root is: %f\n"
         "\n",
         findDiscriminant(a, b, c), findRoot1(a, b, c), findRoot2(a, b, c));
}
