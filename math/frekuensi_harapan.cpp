/**
 * @brief program untuk menghitung expected frequency
 * dari sebuah percobaan.expected frequency dapat dihitung
 * dengan rumus:
 * expected_preq = Pa * Iteration
 * dimana:
 * Pa = peluang kemunculan
 * Iteration = berapa kali percobaan dilakukan
 *
 * @authors yusuf
 * @date 8 oktober 2025
 */
#include <concepts>
#include <initializer_list>
#include <iostream>
#include <numeric>
namespace expected_frequency {
namespace koin {
/**
 * @brief Menghitung frekuensi harapan untuk lemparan koin (1 sisi).
 *
 * Rumus: E = n × 1/2
 *
 * @param iteration Jumlah percobaan (n)
 * @return Expected frequency kemunculan HEAD atau TAIL
 *
 * @note Digunakan jika hanya satu sisi yang ingin dihitung (misal HEAD).
 */
double frequency(int iteration) {
  return iteration * 0.5; // P = 1/2
}
/**
 * @brief Menghitung frekuensi harapan jika ingin menghitung
 *        lebih dari 1 sisi pada lemparan koin.
 *
 * Rumus: E = n × (number × 1/2)
 *
 * @param iteration Jumlah percobaan (n)
 * @param number Jumlah sisi yang dianggap sukses (0–2)
 * @return Expected frequency
 *
 * @example frequency(100, 2) = 100 × (2 × 1/2) = 100
 */
double frequency(int iteration, int number) {
  double Pa = 0.5 * number;
  return iteration * Pa;
}
} // namespace koin
namespace kartu_remi {
/**
 * @brief Menghitung frekuensi harapan munculnya 1 kartu tertentu dari dek remi
 * (52 kartu).
 *
 * Rumus: E = n × 1/52
 *
 * @param iteration Jumlah percobaan (n)
 * @return Expected frequency kemunculan 1 kartu spesifik
 */
double frequency(int iteration) {
  return iteration * (1.0 / 52.0); // P = 1/52
}
/**
 * @brief Menghitung frekuensi harapan jika terdapat beberapa kartu sukses dalam
 * 1 dek.
 *
 * Rumus: E = n × (number × 1/52)
 *
 * @param iteration Jumlah percobaan (n)
 * @param number Banyaknya kartu yang dihitung sukses
 * @return Expected frequency
 *
 * @example frequency(52, 4) → peluang dapat salah satu AS dalam 52 kali
 * percobaan
 */
double frequency(int iteration, int number) {
  double Pa = (1.0 / 52.0) * number;
  return iteration * Pa;
}
} // namespace kartu_remi
namespace dadu {
/**
 * @brief Menghitung frekuensi harapan munculnya satu angka pada 1 dadu.
 *
 * Rumus: E = n × 1/6
 *
 * @param iteration Jumlah percobaan (n)
 * @return Expected frequency kemunculan 1 angka spesifik
 */
double frequency(int iteration) { return iteration * (1.0 / 6.0); }
/**
 * @brief Menghitung frekuensi harapan jika ingin menghitung beberapa angka pada
 * dadu.
 *
 * Rumus: E = n × (number × 1/6)
 *
 * @param iteration Jumlah percobaan (n)
 * @param number Banyaknya angka yang dianggap sukses (misalnya angka 1 atau 2 →
 * number=2)
 * @return Expected frequency
 *
 * @example frequency(60, 2) = 60 × (2/6) = 20
 */

double frequency(int iteration, int number) {
  double Pa = (1.0 / 6.0) * number;
  return iteration * Pa;
}
} // namespace dadu
namespace dadu_custom {
/**
 * @brief Menghitung frekuensi harapan untuk dadu/custom set angka dengan syarat
 * tertentu.
 *
 * Rumus: E = n × (jumlah angka yang memenuhi syarat / total angka)
 *
 * @tparam UnaryPred Predicate (callable) yang menerima int dan mengembalikan
 * bool
 * @param arr Daftar nilai (misalnya {1,2,3,4,5,6})
 * @param p Predicate untuk mengecek kriteria (misalnya cek genap)
 * @param iteration Jumlah percobaan (n)
 * @return Expected frequency sesuai syarat predicate
 *
 * @example
 * auto is_even = [](int x){ return x%2==0; };
 * frequency({1,2,3,4,5,6}, is_even, 60) = 30
 */
template <std::predicate<int> UnaryPred>
double frequency(std::initializer_list<int> arr, UnaryPred p, int iteration) {
  int kriteria = 0;
  for (auto x : arr) {
    if (p(x))
      kriteria++;
  }
  double Pa = static_cast<double>(kriteria) / arr.size();
  return iteration * Pa;
}
} // namespace dadu_custom
namespace others {
/**
 * @brief Menghitung frekuensi harapan berdasarkan distribusi bobot custom.
 *
 * Rumus: E = n × (a / total_bobot)
 *
 * @param arr Daftar bobot distribusi
 * @param iteration Jumlah percobaan (n)
 * @param a Bobot event yang diinginkan
 * @return Expected frequency
 *
 * @example frequency({2,3,5}, 60, 3) = 18
 */
double frequency(std::initializer_list<int> arr, int iteration, int a) {
  double total = std::accumulate(arr.begin(), arr.end(), 0);
  double Pa = static_cast<double>(a) / total;
  return iteration * Pa;
}
/**
 * @brief Menghitung frekuensi harapan dari negasi peluang (peristiwa
 * komplementer).
 *
 * Rumus: E = n × (1 - peluang)
 *
 * @param peluang Peluang suatu peristiwa
 * @param iteration Jumlah percobaan (n)
 * @return Expected frequency dari peristiwa komplemen
 *
 * @example negasi_frequency(0.4, 60) = 36
 */

double negasi_frequency(double peluang, int iteration) {
  return (1 - peluang) * iteration;
}
} // namespace others
} // namespace expected_frequency
int main() {
  using namespace expected_frequency;

  int n = 60;

  // 1. Koin: expected frekuensi muncul HEAD (1/2)
  std::cout << "Koin (HEAD 1/2) dari " << n
            << " kali lempar: " << koin::frequency(n) << "\n";

  // 2. Kartu remi: expected frekuensi muncul AS (1/52)
  std::cout << "Kartu Remi (AS) dari " << n
            << " kali ambil: " << kartu_remi::frequency(n) << "\n";

  // 3. Dadu: expected frekuensi muncul angka 6 (1/6)
  std::cout << "Dadu (angka 6) dari " << n
            << " kali lempar: " << dadu::frequency(n) << "\n";

  // 4. Dadu: expected frekuensi muncul angka 1 atau 2 (2/6)
  std::cout << "Dadu (angka 1 atau 2) dari " << n
            << " kali lempar: " << dadu::frequency(n, 2) << "\n";

  // 5. Dadu custom: peluang bilangan genap dari {1,2,3,4,5,6}
  auto is_even = [](int x) { return x % 2 == 0; };
  std::cout << "Dadu custom (genap) dari " << n << " kali lempar: "
            << dadu_custom::frequency({1, 2, 3, 4, 5, 6}, is_even, n) << "\n";

  // 6. Others: misal bobot distribusi {2,3,5}, cari frekuensi event dengan
  // bobot 3
  std::cout << "Distribusi {2,3,5}, peluang event bobot=3 dari " << n
            << " kali percobaan: " << others::frequency({2, 3, 5}, n, 3)
            << "\n";

  // 7. Negasi frequency: peluang gagal jika peluang sukses 0.4
  std::cout << "Negasi frequency (peluang gagal, p=0.4) dari " << n
            << " kali percobaan: " << others::negasi_frequency(0.4, n) << "\n";

  return 0;
}