#include "quadratic_equation.h"
/**
 * @brief Функция возвращает дискриминант квадратного уравнения
 *
 * @param a первый коэффициент
 * @param b второй коэффициент
 * @param c свободный член
 *
 * @return
 *      меньше 0 - нет корней
 *      равно 0 - уравнение имеет один корень
 *      больше 0 - уравнение имеет два корня
 */
double discriminant(double a, double b, double c) { return b * b - 4 * a * c; }

/**
 * @brief Функция возвращает количество корней в квадратном уравнении
 *
 * @param a первый коэффициент
 * @param b второй коэффициент
 * @param c свободный член
 *
 * @return
 *      0 - уравнение не имеет корней
 *      1 - уравнение имеет один корень
 *      2 - уравнение имеет два корня
 */
int solve_equation(double a, double b, double c) {
  if (a == 0.0) {
    return 0;  // не квадратное уравнение
  } else {
    double d = discriminant(a, b, c);
    if (d < 0.0) {
      return 0;  //нет корней
    } else if (d == 0.0) {
      return 1;  // один корень
    } else {
      return 2;  // два корня
    }
  }
}

/**
 * @brief Функция создает структуру для хранения корней и количества корней
 */
Discriment* createStruct() {
  Discriment* newStruct = (Discriment*)malloc(sizeof(Discriment));
  newStruct->size = 0;
  newStruct->roots[0] = 0;
  newStruct->roots[1] = 0;
  return newStruct;
}

Discriment* inputCoefficients(double a, double b, double c) {
  Discriment* myDiscriment = createStruct();
  if (a == 0) {
    printf(
        "Уравнение %.2f*x^2 + %.2f*x + %.2f = 0 не квадратное, так как первый "
        "коэффициент = 0\n",
        a, b, c);
  } else {
    printf("Квадратное уравнение: %.2f*x^2 + %.2f*x + %.2f = 0\n", a, b, c);
    // Discriment* myDiscriment = createStruct();
    myDiscriment->size = solve_equation(a, b, c);
    if (myDiscriment->size == 0) {
      printf("не имеет корней\n");
    } else if (myDiscriment->size == 1) {
      myDiscriment->roots[0] = -b / (2 * a);
      printf("имеет один корень: x = %.2f\n", myDiscriment->roots[0]);
    } else {
      myDiscriment->roots[0] = (-b + sqrt(discriminant(a, b, c))) / (2 * a);
      myDiscriment->roots[1] = (-b - sqrt(discriminant(a, b, c))) / (2 * a);
      printf("имеет два корня: x1 = %.2f, x2 = %.2f\n", myDiscriment->roots[0],
             myDiscriment->roots[1]);
    }
  }
  return myDiscriment;
}