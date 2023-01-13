/**
 * @file
 * @brief buat urutan fibonacci
 * Hitung nilai pada deret fibonacci yang diberikan
 * bilangan bulat sebagai masukan
 * \f[\text{fib}(n) = \text{fib}(n-1) + \text{fib}(n-2)\f]
 */

#include <cassert>
#include <iostream>

/**
 * Hitung urutan dengan metode
 * rekusif
 * @param n input
 * @return elemen ke-n dari barisan fibonacci
 */
uint64_t fibonacci(uint64_t n) {
  // Jika inputnya 0 atau 1 maka return n
  // ini akan mengatur 2 nilai pertama dari urutan
  if (n == 0 || n == 1 ) {
    return n;
  }

  // Tambahkan 2 nilai terakhir dari urutan untuk mendapatkan
  // yang berikutnya
  return fibonacci(n - 1) + fibonacci(n - 2);
}

/**
 * Fungsi ini untuk menguji dari fungsi fibonacci
 * diatas dengan beberapa contoh kasus
 * @return void
 */
static void test() {
  uint64_t test_case_1 = fibonacci(0);
  assert(test_case_1 == 0);
  std::cout << "Test 1 : berhasil !" << std::endl;
  
  uint64_t test_case_2 = fibonacci(1);
  assert(test_case_2 == 1);
  std::cout << "Test 2 : berhasil !" << std::endl;

  uint64_t test_case_3 = fibonacci(2);
  assert(test_case_3 == 1);
  std::cout << "Test 2 : berhasil !" << std::endl;
}

// Fungsi utama
int main() {
  test();
  int n = 0;
  std::cin >> n;
  assert(n >= 0);
  std::cout << "F(" << n << ") = " << fibonacci(n) << std::endl;
}