/**
 * @namespace dynamic_programming
 * @brief algoritma dp
 */
#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>
namespace dynamic_programming {
/**
 * @namespace subset_sum
 * @brief fungsi untuk algoritma subset
 */
namespace subset_sum {
/**
 * @brief fungsi rekursif menggunakan dynamic programming untuk
 *        menentukan apakah terdapat subset yang jumlahnya sesuai
 *        dengan target atau tidak
 * @param arr array input
 * @param jumlahTarget jumlah target dari subset
 * @param dp peta yang menyimpan hasil perhitungan
 * @return true/false jika apakah suset dengan jumlah target
 *                    ada atau tidak
 */
bool rekursi_subset_sum(const std::vector<int> &arr, int jumlahTarget,
                        std::vector<std::unordered_map<int, bool>> *dp,
                        int indeks = 0) {
  // ditemukan subset valid dengan jumlah yang sesuai
  if (jumlahTarget == 0) {
    return true;
  }
  // akhir dari array
  if (indeks == arr.size()) {
    return false;
  }

  // jika sudah di mapping
  if ((*dp)[indeks].count(jumlahTarget)) {
    return (*dp)[indeks][jumlahTarget];
  }

  // cek jawaban
  bool jawaban =
      rekursi_subset_sum(arr, jumlahTarget - arr[indeks], dp, indeks + 1) ||
      rekursi_subset_sum(arr, jumlahTarget, dp, indeks + 1);
  // save hasil bool ke di peta
  (*dp)[indeks][jumlahTarget] = jawaban;
  return jawaban;
}

/**
 * @brief fungsi yang implementasi algoritma subset sum menggunakan pendekatan
 *        top-down
 * @param arr array input
 * @param jumlahTarget jumlah dari target subset
 * @return true/false jika subset dengan jumlah target ada atau tidak
 */
bool problem_subset_sum(const std::vector<int> &arr, const int jumlahTarget) {
  // ukuran array
  size_t n = arr.size();
  std::vector<std::unordered_map<int, bool>> dp(n);
  return rekursi_subset_sum(arr, jumlahTarget, &dp);
}
} // namespace subset_sum
} // namespace dynamic_programming

/**
 * @brief fungsi untuk menguji
 * @return void
 */
static void uji() {
  std::vector<std::vector<int>> input_kustom_arr(3);
  input_kustom_arr[0] = std::vector<int>{1, -10, 2, 31, -6};
  input_kustom_arr[1] = std::vector<int>{2, 3, 4};
  input_kustom_arr[2] = std::vector<int>{0, 1, 0, 1, 0};

  // jumlah target custom
  std::vector<int> jumlah_target_kustom(3);
  jumlah_target_kustom[0] = -14;
  jumlah_target_kustom[1] = 10;
  jumlah_target_kustom[2] = 2;

  // output yang dihitung oleh fungsi problem_subset_sum
  std::vector<int> output_dihitung(3);

  // loop dengan tujuan melakukan perhitungan untuk tiap
  // kasus uji
  for (int i = 0; i < 3; i++) {
    output_dihitung[i] = dynamic_programming::subset_sum::problem_subset_sum(
        input_kustom_arr[i], jumlah_target_kustom[i]);
  }

  // output yang diharapkan
  std::vector<bool> output_diharapkan{true, false, true};

  for (int i = 0; i < 3; i++) {
    assert(output_diharapkan[i] == output_dihitung[i]);
  }

  std::cout << "semua testing pass!";
}

int main() {
  uji();
  return 0;
}
