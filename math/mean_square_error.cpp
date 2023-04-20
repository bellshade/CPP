/**
 * @file mean_square_error.cpp
 * @brief Program untuk menghitung
 * Mean Squared Error (MSE) dari 2 array
 * dengan panjang yang sama.
 */

#include <iostream>
#include <vector>
#include <exception>
#include <cmath>
#include <cassert>  // assert()

/**
 * @brief Fungsi untuk menghitung Mean Squared Error (MSE)
 * dari dua array dengan panjang yang sama. Jika panjang kedua array
 * tidak sama maka throw invalid_argument exception
 * @param arr1 predicted values
 * @param arr2 actual values
 * @throw invalid_argument The length of both arrays must be the same
 * @return Mean Squared Error dari kedua array
 */
double mse(const std::vector<double>& arr1, const std::vector<double>& arr2) {
  if (arr1.size() != arr2.size()) {
    // throw Error jika panjang kedua array tidak sama.
    throw std::invalid_argument("The length of both arrays must be the same.");
  }

  // variable untuk menampung jumlah squared error
  double error_sum = 0.0;

  // traverse semua element di kedua array
  // dan hitung error nya
  for (size_t i = 0UL; i < arr1.size(); i++) {
    double error = (arr1.at(i) - arr2.at(i));
    double squared_error = (error * error);
    error_sum += squared_error;
  }

  // cast panjang array menjadi double
  double n = static_cast<double>(arr1.size());
  // hitung mean dari squared error sum dan return hasil nya
  double mean_squared_error = error_sum / n;
  return mean_squared_error;
}

int main() {
  std::vector<double> predict{};
  std::vector<double> actual{};

  predict = {1.5, 5.1, 7.3, 7.7, 8.0, 3.9};
  actual = {2.5, 3.4, 7.0, 7.4, 7.8, 3.9};
  std::cout << "MSE: " << mse(predict, actual) << '\n';

  // test to throw an exception
  try {
    predict = {7.5, 4.5, 3.2};
    actual = {7.1, 5.5};

    std::cout << "MSE: " << mse(predict, actual) << '\n';
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}
