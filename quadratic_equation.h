#ifndef QUADRATIC_EQUATION_H
#define QUADRATIC_EQUATION_H
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Структура для хранения корней и количества корней
 */
typedef struct {
  double roots[2];
  int size;
} Discriment;

int solve_equation(double a, double b, double c);
double discriminant(double a, double b, double c);
Discriment* createStruct();
Discriment* inputCoefficients(double a, double b, double c);

#endif  // QUADRATIC_EQUATION_H