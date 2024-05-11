#include "check.h"
#include "quadratic_equation.h"

START_TEST(test_solve_equation) {
  printf("TEST1:\n");
  double a1 = 1.0, b1 = -3.0, c1 = 2.0;
  Discriment* myDiscriment = inputCoefficients(a1, b1, c1);
  ck_assert_int_eq(myDiscriment->size, 2);
  ck_assert_double_eq(myDiscriment->roots[0], 2.0);
  ck_assert_double_eq(myDiscriment->roots[1], 1.0);

  // Тест для линейного уравнения
  printf("\nTEST2:\n");
  double a2 = 0.0, b2 = -3.0, c2 = 2.0;
  myDiscriment = inputCoefficients(a2, b2, c2);
  ck_assert_int_eq(myDiscriment->size, 0);
  ck_assert_double_eq(myDiscriment->roots[0], 0.0);
  ck_assert_double_eq(myDiscriment->roots[1], 0.0);

  // Тест для уравнения без корней
  printf("\nTEST3:\n");
  double a3 = 1.0, b3 = 2.0, c3 = 3.0;
  myDiscriment = inputCoefficients(a3, b3, c3);
  ck_assert_int_eq(myDiscriment->size, 0);
  ck_assert_double_eq(myDiscriment->roots[0], 0.0);
  ck_assert_double_eq(myDiscriment->roots[1], 0.0);

  // Тест для уравнения с одним корнем
  printf("\nTEST4:\n");
  double a4 = 1.0, b4 = -2.0, c4 = 1.0;
  myDiscriment = inputCoefficients(a4, b4, c4);
  ck_assert_int_eq(myDiscriment->size, 1);
  ck_assert_double_eq(myDiscriment->roots[0], 1.0);
  ck_assert_double_eq(myDiscriment->roots[1], 0.0);
}
END_TEST

Suite* make_my_suite() {
  Suite* s = suite_create("Solve Equation");
  TCase* tc = tcase_create("Core");

  tcase_add_test(tc, test_solve_equation);
  suite_add_tcase(s, tc);

  return s;
}

int main() {
  int number_failed;
  Suite* s = make_my_suite();
  SRunner* sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : CK_FAILURE;
}