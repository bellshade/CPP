#include <cmath>
#include <iostream>

float derivative(float (*f)(float), float x, float h = 1e-5) {
  /**
   * @brief derivative atau familiar dengan istilah `limit`.limit
   * limier merupakan suatu konsep yang digunakan untuk mengetahui
   * perilaku suatu fungsi saat variabel independennya mendekati nilai
   * tertentu
   * @param f merupakan parameter input berupa fungsi
   * @param x merupakan parameter input berupa angka desima
   * @param h merupakan mengisi perbadingan nilai awal yang optimal nya
   *          1e-5
   * @return float outputnya berupa angka desimal
   */
  return (f(x - h) - f(h) / h);
}

float poly_derivative(float x, int n) {
  /**
   * @brief merupakan turunan dari limit biasa dengan input fungsi
   * berupa input polynominal
   * @param x input value berupa angka decimal
   * @param n input value berupa angka untuk pangkat
   * @return float berupa angka decimal
   *
   */
  return n * pow(x, n - 1);
}

float sum_derivative(float (*f)(float), float (*h)(float), float x) {
  /**
   * @brief  fungsi ini merupakan fungsi dari turunan limit dengan
   * input fungsi dua atau lebih dan juga hasilnya ditambah
   * sama seperti X(a+b) = Xa + Xb
   * @param f input value fungsi pertama
   * @param h input value fungsi kedua
   * @param x input value berupa angka decimal
   * @return float hasilnya berupa desimal
   */
  return derivative(f, x) + derivative(h, x);
}

float product_derivative(float (*f)(float), float (*h)(float), float(x)) {
  /**
   * @brief fungsi ini merupakan konsepnya seperti sum tetapi berupa angka
   * konsepnya seperti ini X(ab) Xab + aXb
   * @param f input berupa fungsi pertama
   * @param g input berupa fungsi kedua
   * @param x input berupa angka decimal
   * @return float keluar dengan angka decimal
   */

  return derivative(f, x) * h(x) + f(x) * derivative(h, x);
}

float chain_derivative(float (*f)(float), float (*g)(float), float x) {
  /**
   * @brief urunan fungsi komposit (fungsi bersusun) dari dua fungsi matematika
   * @param f input fungsi berupa fungsi pertama
   * @param g input fungsi berupa fungsi kedua
   * @param x input berupa angka desimal
   * @return float output berupa angka desimal
   */
  return derivative(g, f(x)) * derivative(f, x);
}

int main() {
  float x = 2.0;
  int n = 3;
  auto f = [](float x) { return x * x; };
  auto g = [](float x) { return x * x * x; };
  std::cout << "Percobaan untuk derivative\n";
  std::cout << "Hasil dari derivative dari x adalah" << derivative(f, x)
            << std::endl;

  std::cout << "Percobaan untuk Poly derivative\n";
  std::cout << "Hasil dari Poly derivative dari x adalah"
            << poly_derivative(x, n) << std::endl;

  std::cout << "Percobaan untuk Sum derivative\n";
  std::cout << "Hasil dari Sum derivative dari x adalah"
            << sum_derivative(f, g, x) << std::endl;

  std::cout << "Percobaan untuk Product derivative\n";
  std::cout << "Hasil dari Product derivative dari x adalah"
            << product_derivative(f, g, x) << std::endl;

  std::cout << "Percobaan untuk Chain derivative\n";
  std::cout << "Hasil dari Chain derivative dari x adalah"
            << chain_derivative(f, g, x) << std::endl;
  return 0;
}