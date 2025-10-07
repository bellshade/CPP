/**
 * @file pigeonhole.cpp
 *
 * @author Perpuskita Ruldani
 *
 * @date Okt 2025
 *
 * @brief Program untuk mengurutkan data menggunakan algoritma Pigeonhole.
 *
 * Program ini mengurutkan sejumlah bilangan bulat direntang tertentu.
 * Algoritma ini dimulai dengan cara mencari nilai maximum dan minimum data,
 * Kemudian membuat vector kosong sejumlah ( nilai maximum data - nilai minimum data ) + 1,
 * Data kemudian ditempatkan kedalam vector kosong sesuai dengan indeks [i - min_val],
 *
 * Hasilnya akan ditampilkan di terminal.
 */

#include <iostream>
#include <vector>
#include <algorithm>

void pigeonholeSort(std::vector<int>& arr) {
    // Cari nilai minimum dan maksimum
    int min_val = *min_element(arr.begin(), arr.end());
    int max_val = *max_element(arr.begin(), arr.end());

    int range = max_val - min_val + 1;

    // Membuat pigeonholes
    std::vector<std::vector<int>> holes(range);

    // Menempatkan elemen ke pigeonhole sesuai nilainya
    for (int num : arr) {
        holes[num - min_val].push_back(num);
    }

    // Mengambil elemen dari pigeonhole secara berurutan
    int index = 0;
    for (int i = 0; i < range; i++) {
        for (int num : holes[i]) {
            arr[index++] = num;
        }
    }
}

int main() {
    std::vector<int> data = { 8, 3, 2, 7, 4, 6, 8, 5 };

    std::cout << "Sebelum sort: ";
    for (int x : data) std::cout << x << " ";
    std::cout << std::endl;

    pigeonholeSort(data);

    std::cout << "Setelah sort : ";
    for (int x : data) std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}
