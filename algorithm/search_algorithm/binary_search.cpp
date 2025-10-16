/**
 * @file binary_search.cpp
 *
 * @author Perpuskita Ruldani
 *
 * @date Okt 2025
 *
 * @brief Program untuk mencari sebuah data dalam array yang sudah terurut menggunakan algoritma binary search
 *
 * Program ini mencari sebuah data pada array yang sudah terurut
 * Program berjalan dengan membandingkan nilai titik tengah dari sebuah array dengan data yang dicari
 * Jika data masih belum ditemukan maka pencarian dilakukan pada titik tengah tersebut
 * Jika titik tengah lebih besar daripada data yang dicari maka pencarian dimulai dari titik awal pencarian sampai index tengah
 * Jika titik tengah lebih kecil daripada data yang dicari maka pencarian dimulai dari index tengah sampai index terakhir
 * 
 * Hasilnya ditampilkan di terminal.
 */

#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& arr, int n) {
    // Inisialisasi indeks paling kiri dan kanan
    int left = 0;
    int right = arr.size() - 1;

    // Lakukan pencarian selama indeks kiri tidak melebihi indeks kanan
    while (left <= right) {
        // Step pertama
        // Hitung indeks tengah
        int mid = left + (right - left) / 2;

        // Cek jika n ada di mid
        if (arr[mid] == n) {
            return mid; // data ditemukan, kembalikan indeks
        }

        // Jika n lebih besar, abaikan bagian kiri
        else if (arr[mid] < n) {
            left = mid + 1;
        }

        // Jika n lebih kecil, abaikan bagian kanan
        else {
            right = mid - 1;
        }
    }
    return -1; // data tidak ditemukan
}

int main() {
    // inisialisasi data
    std::vector<int> data = { 1, 2, 3, 6, 8, 9, 13, 21 };

    // data yang akan dicari
    int n = 9;

    // Menampilkan data sebelum diurutkan
    std::cout << "Menampilkan data: ";
    for (int x : data) std::cout << x << " ";
    std::cout << std::endl;

    // Menampilkan data yang akan dicari
    std::cout << "Data yang dicari: " << n << std::endl;

    // Melakukan pencarian data menggunakan binary search
    int hasil = binarySearch(data, n);

    // Menampilkan hasil pencarian
    if (hasil != -1)
        std::cout << "Data yang dicari ditemukan pada urutan ke-" << hasil + 1 << std::endl;
    else
        std::cout << "Data tidak ditemukan dalam array." << std::endl;

    // Mengakhiri program
    return 0;
}
