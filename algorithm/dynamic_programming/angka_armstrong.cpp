#include <cassert>
#include <cmath>
#include <iostream>
namespace dynamic_programming {

/**
 * @brief cek apakah angka yang diberikan adalah angka armstrong
 * @param angka angka yang akan di cek
 * @return false jika angka yang diberikan bukan angka armstrong
 * @return true jika benar
 */
template <typename T> bool cek_armstrong(const T &angka) {
  // inisialisasi variabel
  int jumlah_digit = 0, sementara = angka, hasil = 0;

  // hitung jumlah digit dari angka yang diberikan
  // contoh: 153 memiliki 3 digit
  while (sementara != 0) {
    // hapus digit terakhir
    sementara /= 10;
    // tambah jumlah digit
    jumlah_digit++;
  }

  // hitung untuk memeriksa apakah adalah angka armstrong
  // pada angka dengan n-digit, jumlah digit yang dipangkatkan dengan n
  // harus sama dengan aslinya
  sementara = angka;
  while (sementara != 0) {
    // ambil digit terakhir
    int sisa = sementara % 10;
    // pengkatkan dengan jumlah digit
    hasil += static_cast<T>(std::pow(sisa, jumlah_digit));
    // hapus digit terakhir
    sementara /= 10;
  }

  // jika hasil sama dengan angka asli, maka angka armstrong
  if (hasil == angka) {
    return true;
  } else {
    // jika tidak sama dengan parameter yang diberikan
    return false;
  }
}
} // namespace dynamic_programming

/**
 * @brief implementasi testing
 * @return void
 */
static void testing() {
  // untuk testing angka armstrong
  assert(dynamic_programming::cek_armstrong(153) == true);
  assert(dynamic_programming::cek_armstrong(370) == true);

  // untuk testing angka bukan angka armstrong
  assert(dynamic_programming::cek_armstrong(15) == false);
  assert(dynamic_programming::cek_armstrong(103) == false);

  std::cout << "testing pass!" << std::endl;
}

int main() {
  testing();
  return 0;
}
