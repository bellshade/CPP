/*
Bubble Sort adalah Sorting algorithm yang cara kerjanya adalah dengan
membandingkan 2 elemen array lalu menggeser kedua elemen tersebut sesuai dengan
urutan terus-menerus sampai akhir array Berikut gambaran cara kerja dari Bubble
Sort
=============================================
Inisialisasi [5, 3, 8, 4, 6] Inisialisasi array acak
      Elemen  1  2  3  4  5
Langkah 1    [5, 3, 8, 4, 6] Membandingkan elemen ke 1 dengan elemen ke 2.
Dikarenakan nilai dari ^  ^           elemen ke 1 lebih besar maka posisi kedua
elemen tersebut ditukar Langkah 2    [3, 5, 8, 4, 6] Membandingkan elemen ke 2
dengan elemen ke 3. Dikarenakan nilai dari ^  ^        elemen ke 2 lebih kecil
maka posisi kedua elemen tidak ditukar Langkah 3    [3, 5, 8, 4, 6]
Membandingkan elemen ke 3 dengan elemen ke 4. Dikarenakan nilai dari ^  ^ elemen
ke 3 lebih besar maka posisi kedua elemen tersebut ditukar Langkah 4    [3, 5,
4, 8, 6] Membandingkan elemen ke 4 dengan elemen ke 5. Dikarenakan nilai dari ^
^  elemen ke 4 lebih besar maka posisi kedua elemen tersebut ditukar Langkah 5
Mengulangi pengecekan dari awal sampai akhir array sampai tidak ada lagi yang
dapat ditukar posisi Final        [3, 4, 5, 6, 8] Array selesai diurutkan
=============================================
*/

#include <cassert>
#include <iostream>
#include <vector>

namespace sorting {
void bubbleSort(std::vector<int> &numbers) {
  int n = numbers.size();
  for (int i = 0; i < n; i++) {
    bool swapping = false;
    for (int x = 0; x < (n - i - 1); x++) {
      // jika current number yang direprsentasikan oleh numbers[x] lebih besar
      // dari nextNumber numbers[x+1] maka tukarkan posisi 2 angka tersebut
      if (numbers[x] > numbers[x + 1]) {
        // std::cout << "Menukar: " << numbers[x] << " Dengan " << numbers[x+1]
        // << std::endl;
        std::swap(numbers[x], numbers[x + 1]);
        swapping = true;
      }
    }
    if (!swapping) {
      break;
    }
  }
}

void tampilkanUrutan(const std::vector<int> &numbers) {
  for (const auto &x : numbers) {
    std::cout << x << " ";
  }
  std::cout << "\n";
}
} // namespace sorting

/**
 * @brief test
 * @return void
 */
static void test() {
  std::vector<int> numbers = {5, 3, 8, 4, 6};
  std::vector<int> expectationSortResult = {3, 4, 5, 6, 8};
  std::cout << "Sebelum diurut\n";
  sorting::tampilkanUrutan(numbers);
  sorting::bubbleSort(numbers);
  std::cout << "Sesudah diurut\n";
  sorting::tampilkanUrutan(numbers);
  assert(numbers == expectationSortResult);
}
int main() {
  test();
  return 0;
}
