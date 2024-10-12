/**
 * @file subarray_sum.cpp
 * @brief [subset-sum](https://en.wikipedia.org/wiki/Subset_sum_problem)
 * @date 2021-12-07
 * @details kita berikan array dan nilai jumlah. algoritma menemukan semua
 * sibarray dari array dengan jumlah yang sama dengan jumlah yang diberikan
 * dan mengembalikan jumlahnya.
 * catatan dalam masaslah ini hanya mengacu pada himpunan bagian kontinu sebagai
 * di mana.subarray dapat dibuat menggunakan operasi penghapusan di ujung depan
 * array saja.
 */

#include <cassert>
#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>

/**
 * @brief algoritma backtracking
 * @namespace backtracking
 *
 */
namespace backtracking {
namespace subarray_sum {
/**
 * @brief fungsi utama untuk implementasi dari subarray sum
 * @param sum adalah yang diperlukan dari setiap subarray
 * @param in_arr adalh input dari array
 * @return jumlah dari angka set
 */
uint64_t subarray_sum(int64_t sum, const std::vector<int64_t> &in_arr) {
  int64_t nelement = in_arr.size();
  int64_t count_of_subset = 0;
  int64_t current_sum = 0;
  std::unordered_map<int64_t, int64_t> sumarray;

  for (int64_t i = 0; i < nelement; i++) {
    current_sum += in_arr[i];
    if (current_sum == sum) {
      count_of_subset++;
    }

    // jika seandainya current_sum lebih besar
    // dari jumlah yang dibutuhkan
    if (sumarray.find(current_sum - sum) != sumarray.end()) {
      count_of_subset += (sumarray[current_sum - sum]);
    }
    sumarray[current_sum]++;
  }
  return count_of_subset;
}
} // namespace subarray_sum
} // namespace backtracking

static void testing() {
  std::cout << "test pertama ";
  std::vector<int64_t> array1 = {-7, -3, -2, 5, 8};
  assert(backtracking::subarray_sum::subarray_sum(0, array1) == 1);

  std::cout << "berhasil!" << std::endl;
}

int main() {
  testing();

  return 0;
}
