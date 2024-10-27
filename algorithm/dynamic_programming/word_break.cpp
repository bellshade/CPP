#include <cassert>
#include <climits>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
namespace dynamic_programming {
/**
 * @brief fungsi untuk menyelesaikan masalah problem dari word break
 */
namespace word_break {

/**
 * @brief fungsi untuk memeriksa apakah string yang diberikan ada di dalam
 *        unordered_set yang diberikan
 *
 * @param kata string yang akan dicari
 * @param himpunan_kata unordered_set yang menjadi referensi searching
 * @return `true` jika kata ditemukan
 * @return `false` jika tidak ditemukan
 */
bool ada(const std::string &kata,
         const std::unordered_set<std::string> &himpunan_kata) {
  // cek apakah kata ditemukan dalam himpunan_kata
  return himpunan_kata.find(kata) != himpunan_kata.end();
}

/**
 * @brief fungsi untuk memeriksa apakah string yang diberikan dapat dipecah dari
 * posisi `pos`, dan apakah bagian sisanya juga dapat dipecah secara benar untuk
 * mencapai solusi
 *
 * @param s string lengkap yang akan dipecah
 * @param himpunan_kata unordered set yang menjadi referensi dictonary
 * @param pos indeks posisi saat ini untuk memulai pemisahan
 * @param dp vektor untuk menyimpan hasil memoisasi pada tiap posisi
 * @return `true` jika solusi pemisahan valid bisa dilakukan dalm posisi `pos`
 * @return `false` jik tidak ada solusi
 */
bool periksa(const std::string &s,
             const std::unordered_set<std::string> &himpunan_kata, int pos,
             std::vector<int> *dp) {
  if (pos == s.length()) {
    // jika sudah mencapai akhir string, artinya string telah berhasil dipecah
    return true;
  }

  if (dp->at(pos) != INT_MAX) {
    // jika dp[pos] bukan INT_MAX, berarti kita sudah menyimpan solusi untuk
    // posisi `pos`. return solusi yang disimpan
    return dp->at(pos) == 1;
  }

  // string untk menyimpan potongan kata
  std::string kata_sementara = "";

  // lakukan looping iterasi dari `pos` hingga akhir string
  for (int i = pos; i < s.length(); i++) {
    // tambahin karakter ke kata_sementara
    kata_sementara += std::string(1, s[i]);

    // jika kata_sementara ditemukan dalam himpunan_kata dan sisa string
    // juga bisa dipecah, simpan solusi di dp dan kembalikan true
    if (ada(kata_sementara, himpunan_kata) &&
        periksa(s, himpunan_kata, i + 1, dp)) {
      // simpan solusi di dp
      dp->at(pos) = 1;
      return true;
    }
  }

  // jika tidak ditemukan pisah yang valid simpan 0 di dp untuk posisi ini
  dp->at(pos) = 0;
  return false;
}

/**
 * @brief fungsi untuk memeriksa apakah string dapat dipecah menjadi string yang
 *        ada di vektor, fungsi ini memeriksa apakah kombinasi kata dalam vektor
 * bisa membentuk string lengkap `s`
 *
 * @param s string lengkap yang akan dipecah
 * @param kamus vektor kata yang menjadi referensi dictonary
 * @return `true` jika string `s` bisa dibentuk dari kombinasi kata dalam kamus
 * @return `false` jika tidak
 */
bool pecah_kata(const std::string &s, const std::vector<std::string> &kamus) {
  std::unordered_set<std::string> himpunan_kata;
  for (const auto &kata : kamus) {
    himpunan_kata.insert(kata);
  }

  // buat vektor dp untuk menyimpan solusi pada tiap posisi
  std::vector<int> dp(s.length(), INT_MAX);
  // panggil fungsi `periksa` mulai dari posisi 0 untuk cek apakah string
  // bisa dipecah
  return periksa(s, himpunan_kata, 0, &dp);
}

} // namespace word_break
} // namespace dynamic_programming

/**
 * @brief fungsi untuk menguji implementasi
 * @return void
 */
static void testing_fungsi() {
  // string yang akan dipecah
  const std::string s = "applepenapple";
  // dictionary yang di pakai
  const std::vector<std::string> dict = {"apple", "pen"};

  // memastikan bahwasanya implementasi berhasil pecah string
  assert(dynamic_programming::word_break::pecah_kata(s, dict));
  std::cout << dynamic_programming::word_break::pecah_kata(s, dict)
            << std::endl;
  std::cout << "testing berhasil";
}

int main() {
  testing_fungsi();
  const std::string s = "applepenapple";
  const std::vector<std::string> dict = {"apple", "pen"};
  std::cout << dynamic_programming::word_break::pecah_kata(s, dict)
            << std::endl;
}
