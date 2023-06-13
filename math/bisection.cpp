#include <iostream>

float equation(float x) {
  /**
   * hasil dari pengurangan dan perkalian dari
   * nilai x
   * parameter:
   *   x(float)
   * return:
   *   hasil dari 10 - x * x
   */
  return 10 - x * x;
}

float bisection(float a, float b) {
  /**
   * diberikan fungsi pada bilangan float f(x) dan dua bilangan
   * float 'a' dan 'b' sedimikian sehingga
   * f(a) * f(b) < 0 dan f(x) kontinu di [a, b]
   * disini f(x) memiliki persamaan aljabar atau transendental
   */
  // menggunakan teori bolzano
  if (equation(a) * equation(b) >= 0) {
    std::cout << "0" << std::endl;
  }

  float c = a;
  while ((b - a) >= 0.01) {
    c = (a + b) / 2;
    if (equation(c) == 0.0) {
      break;
    }
    if (equation(c) * equation(a) < 0) {
      b = c;
    } else {
      a = c;
    }
  }
  return c;
}

int main() {
  // testing hasil code
  float hasil1 = bisection(-2, 5);
  float hasil2 = bisection(0, 6);
  std::cout << "hasil pengujian 1: " << hasil1 << std::endl;
  std::cout << "hasil pengujian 2: " << hasil2 << std::endl;
  return 0;
}
