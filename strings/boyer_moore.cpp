#include <cassert>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#define UKURAN_ALFABET

/**
 * @namespace
 * @brief Algoritma string
 */
namespace strings {
/**
 * @namespace
 * @brief fungsi untuk implementasi algoritma booyer-moore
 */
namespace boyer_moore {
struct pola {
  // pola yang akan dicari
  std::string pola_teks;
  // tabel karaketer yang buruk yang digunakan heuristik karakter
  // buruk pada algoritma
  std::vector<size_t> karakter_buruk;
  // tabel awalan baik yang digunakan dalama heuristik awalan baik
  // pada algoritma boyer moore
  std::vector<size_t> awalan_baik;
};

/**
 * @brief fungsi untuk memproses tabel awaln baik
 *
 * @param teks string yang akan diproses
 * @param arg tabel awalan baik yang akan diisi
 * @return void
 */
void inisialisasi_awalan_baik(const std::string &teks,
                              std::vector<size_t> &arg) {
  // resize tabel awalan baik sesuasi ukuran string
  arg.resize(teks.size() + 1, 0);

  std::vector<size_t> posisi_perbatasan(teks.size() + 1, 0);
  // inisialisasi karakter saat ini dengan panjang string
  size_t karaketer_saat_ini = teks.length();
  // inisialisasi indeks perbatasan
  size_t indeks_perbatasan = teks.length() + 1;
  // set perbatasan terakhir
  posisi_perbatasan[karaketer_saat_ini] = indeks_perbatasan;

  // prosesa perbatasan untuk menemukan awalan baik
  while (karaketer_saat_ini > 0) {
    while (indeks_perbatasan <= teks.length() &&
           teks[karaketer_saat_ini - 1] != teks[indeks_perbatasan - 1]) {
      if (arg[indeks_perbatasan] == 0) {
        arg[indeks_perbatasan] = indeks_perbatasan - karaketer_saat_ini;
      }
      indeks_perbatasan = posisi_perbatasan[indeks_perbatasan];
    }

    // kurangi karaketer yang sedang diperiksa
    karaketer_saat_ini--;
    indeks_perbatasan--;
    posisi_perbatasan[karaketer_saat_ini] = indeks_perbatasan;
  }

  // mementukan perbatasan terbesar
  size_t indeks_perbatasan_terbesar = posisi_perbatasan[0];

  // isi tabel awalan baik untuk seluruh karakter
  for (size_t i = 0; i < teks.size(); i++) {
    if (arg[i] == 0) {
      // set nilai ke perbatasan
      arg[i] = indeks_perbatasan_terbesar;
    }
    // jika melewati perbatasan terbesar, cari perbatasan selanjutnya
    if (i == indeks_perbatasan_terbesar) {
      indeks_perbatasan_terbesar =
          posisi_perbatasan[indeks_perbatasan_terbesar];
    }
  }
}

/**
 * @brief fungsi untuk memproses tabel karakter buruk
 *
 * @param teks string yang akan diproses
 * @param arg tabel karakter buruk yang akan diisi
 * @return void
 */
void inisialisasi_karakter_buruk(const std::string &teks,
                                 std::vector<size_t> &arg) {
  arg.resize(teks.length());

  // isi table karakter buruk dengan jarak pergeseran berdasarkan karakter
  for (size_t i = 0; i < teks.length(); i++) {
    // hitung jarak pergeseran untuk karakter tertentu
    arg[teks[i]] = teks.length() - i - 1;
  }
}

/**
 * @brief fungsi untuk menginisialisasi pola
 *
 * @param teks yang digunakan untuk inisialisasi
 * @param arg struktur pola yang diinisialisasi
 * @return void
 */
void inisialisasi_pola(const std::string &teks, pola &arg) {
  arg.pola_teks = teks;
  inisialisasi_karakter_buruk(teks, arg.karakter_buruk);
  inisialisasi_awalan_baik(teks, arg.awalan_baik);
}

/**
 * @brief fungsi implementasi algoritma boyer moore
 *
 * @param teks teks yang akan dicari data pola
 * @param arg struktur pola yang mengandung pola yang sudah di proses
 * @return vektor indeks yang menyimpan kemunculan pola dalam teks
 */
std::vector<size_t> cari(const std::string &teks, const pola &arg) {
  // inisialisasi posisi indeks pencarian
  size_t posisi_indeks = arg.pola_teks.size() - 1;
  // vektor untuk menyimpan hasil pencarian
  std::vector<size_t> penyimpanan_indeks;

  // lakukan pencarian
  while (posisi_indeks < teks.length()) {
    size_t indeks_teks = posisi_indeks;
    int indeks_pola = static_cast<int>(arg.pola_teks.size()) - 1;

    // badingkan pola dengan teks dari belakang
    while (indeks_pola >= 0 &&
           teks[indeks_teks] == arg.pola_teks[indeks_pola]) {
      --indeks_pola;
      --indeks_teks;
    }

    // jika pola cocok, save result indeks
    if (indeks_pola < 0) {
      penyimpanan_indeks.push_back(posisi_indeks - arg.pola_teks.length() + 1);
      posisi_indeks += arg.awalan_baik[0];
    } else {
      posisi_indeks += std::max(arg.karakter_buruk[teks[indeks_teks]],
                                arg.awalan_baik[indeks_pola + 1]);
    }
  }

  // return hasil pencarian
  return penyimpanan_indeks;
}

/**
 * @brief fungsi untuk memeriksa apakah pola adalah prefix dari string
 *
 * @param teks pointer ke beberapa bagia teks input
 * @param pola pola yang sedang dicari
 * @return `true` jika pola adalah prefiks dari teks
 * @return `false` jika pola bukan prefiks dari teks
 */
bool adalah_prefix(const char *teks, const char *pola, size_t panjang) {
  if (strlen(teks) < panjang) {
    // pola tidak mungkin menjadi prefiks jika teks lebih pendek
    return false;
  }

  // bandingkan karakter satu per satu
  for (size_t i = 0; i < panjang; i++) {
    if (teks[i] != pola[i]) {
      // jika ada perbedaan, maka bukan prefik
      return false;
    }
  }

  // jika semua karakter cocok, pola adalah prefik
  return true;
}
} // namespace boyer_moore
} // namespace strings

/**
 * @brief test case untuk mencari kemunculan kata `and`
 * @param teks teks yang digunakan untuk pencarian kata `and`
 * @return void
 */
void uji_and(const char *teks) {
  strings::boyer_moore::pola ands;
  strings::boyer_moore::inisialisasi_pola("and", ands);
  std::vector<size_t> indeks = strings::boyer_moore::cari(teks, ands);

  assert(indeks.size() == 2);
  assert(strings::boyer_moore::adalah_prefix(teks + indeks[0], "and", 3));

  std::cout << "Kata 'and' ditemukan pada indeks: ";
  for (size_t i : indeks) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

/**
 * @brief fungsi utama untuk menjalankan test case
 * @returns int nilai pengembalian dari status program
 */
int main() {
  const char *teks_uji = "and here and there";
  uji_and(teks_uji);
  return 0;
  return 0;
}
