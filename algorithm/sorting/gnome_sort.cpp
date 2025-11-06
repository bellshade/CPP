#include <iostream>
#include <vector>

/**
 * @file gnome_sort.cpp
 * @brief Program sederhana untuk mengurutkan array menggunakan algoritma Gnome
 * Sort.
 *
 * Algoritma Gnome Sort bekerja mirip seperti penyortiran tukang kebun (gnome):
 * - Mulai dari elemen pertama
 * - Jika elemen saat ini lebih besar dari elemen berikutnya, tukar keduanya
 * - Jika tidak, maju ke elemen berikutnya
 * - Jika mundur ke elemen sebelumnya, ulangi proses
 * - Lanjutkan sampai akhir array
 */

/**
 * @brief Mengurutkan array menggunakan algoritma Gnome Sort.
 *
 * Fungsi ini menerima sebuah array (vector) dan mengurutkannya secara ascending
 * menggunakan logika Gnome Sort. Proses pengurutan dilakukan secara
 * **in-place**.
 *
 * @param arr Vector dari integer yang ingin diurutkan.
 */
void gnomeSort(std::vector<int> &arr) {
  int index = 0;
  int n = arr.size();

  while (index < n) {
    if (index == 0 || arr[index] >= arr[index - 1]) {
      index++;
    } else {
      std::swap(arr[index], arr[index - 1]);
      index--;
    }
  }
}

int main() {
  int size;
  std::cout << "Masukkan jumlah elemen array: ";
  std::cin >> size;

  std::vector<int> arr(size);
  std::cout << "Masukkan elemen-elemen array, dipisahkan spasi: ";
  for (int i = 0; i < size; i++) {
    std::cin >> arr[i];
  }

  gnomeSort(arr);

  std::cout << "Array setelah diurutkan: ";
  for (int num : arr) {
    std::cout << num << " ";
  }
  std::cout << "\n";

  return 0;
}
