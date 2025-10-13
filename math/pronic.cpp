#include <cmath>    // untuk fungsi sqrt()
#include <iostream>

/**
 * @file pronic.cpp
 * @brief Program sederhana untuk mengecek apakah sebuah input angka merupakan
 * bilangan pronic atau bukan. Bilangan pronic adalah bilangan yang merupakan
 * hasil perkalian dari suatu angka dengan angka selanjutnya. Rumus umum: n ( n
 * + 1 ) Contoh sederhana: 3 4 = 12 -> 12 merupakan bilangan pronic.
 */

/**
 * @brief Mengecek apakah sebuah angka merupakan bilangan pronic.
 *
 * Fungsi ini menghitung akar kuadrat dari angka, melakukan truncation,
 * lalu memeriksa apakah hasil perkalian angka tersebut dengan angka
 * selanjutnya sama dengan angka input
 *
 * @param n Angka yang ingin dicek
 * @return true Jika n merupakan bilangan pronic, false jika bukan
 */
bool adalah_pronic(int n) {
  int x = static_cast<int>(sqrt(n));
  return (x * (x + 1) == n); // rumus pronic
  /**
   * Aproksimasi nilai x.
   * Contoh: n = 12, aproksimasi dari sqrt(12) adalah 3.162277
   * Hasil kemudian di-cast ke int sehingga menjadi 3 (truncation)
   */
}

int main() {
  while (true) { // Supaya tidak harus menjalankan kode setiap mau mengetes angka baru.
    int n;
    std::cout << "Masukkan sebuah angka: ";
    std::cin >> n;

    // Perform fungsi adalah_pronic() dengan mengambil input n yang sudah
    // dimasukkan user sebagai parameter dan menampilkan output
    if (adalah_pronic(n)) {
      std::cout << n << " Merupakan bilangan pronic."
                << "\n";
    } else {
      std::cout << n << " Bukan merupakan bilangan pronic."
                << "\n";
    }
  }

  return 0;
}
