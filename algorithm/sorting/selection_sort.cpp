/**
 * @file insertion_sort.cpp
 * 
 * @authors Muh Yusuf
 * 
 * @date July 2025
 * 
 * @brief Program untuk mengurutkan array menggunakan algoritma Selection Sort.
 * 
 * Program ini meminta pengguna untuk memasukkan sejumlah elemen integer,
 * lalu mengurutkannya dengan algoritma Selection Sort dan menampilkannya.
 * 
 * ### Detail Fitur:
 * - Input panjang array dari pengguna
 * - Input elemen-elemen array
 * - Sorting dengan algoritma Selection Sort
 * - Output array yang sudah diurutkan
 * 
 * ### Catatan:
 * - Sorting dilakukan **in-place** menggunakan referencing
 * - Penukaran elemen menggunakan fungsi `swap()`
 * - Output dilakukan lewat fungsi `PrintVec()` untuk modularitas
 */

#include <iostream>
#include <vector>
#include <algorithm>
// Fungsi untuk menukar posisi dua elemen

/**
 * @brief Menampilkan elemen-elemen dari vector.
 * 
 * @param val Vector integer yang akan ditampilkan elemennya.
 * 
 * Fungsi ini menggunakan reference agar efisien dan tidak melakukan copy data.
 */
void PrintVec(const std::vector<int>& val){ //gunakan referencing
    for(const auto x: val){
        std::cout << x << " ";
    }
}
/**
 * @brief Mengurutkan elemen-elemen dalam vector menggunakan algoritma Selection Sort.
 * 
 * @param val Vector integer yang akan diurutkan (secara ascending).
 * 
 * Selection Sort bekerja dengan mencari elemen terkecil dari sisa elemen yang belum
 * terurut, lalu menukarnya dengan elemen pada posisi saat ini.
 * 
 * Kompleksitas waktu: O(n^2)
 */
void SelectionSort(std::vector<int>& val){  //gunakan referencing untuk menghindari banyak penggunaan variabel
    /*
    Lakukan iterasi untuk setiap elemen vector dengan i sebagai indeks elemen pertama.
    Karena elemen terakhir secara otomatis sudah berada di posisi yang benar setelah semua iterasi,
    maka loop untuk i berhenti di val.size() - 1.
    */
    for(int i = 0; i < val.size(); i++){
        //asumsikan elemen minimum adalah element index pertama atau i(karena index dimulai dari 0)
        int min = i;
        for(int j = i + 1; j<val.size(); j++){
            /*jika angka kedua lebih kecil dari angka pertama maka update nilai min menjadi angka kedua(j)*/
            if(val[j] < val[min]){
                min = j;
            }
        }
        /*
        Jika elemen terkecil yang ditemukan (min) berbeda dengan elemen saat ini (i),
        maka tukar elemen pada posisi i dengan elemen terkecil yang ditemukan.
        Proses ini menempatkan elemen terkecil di posisi yang benar pada setiap iterasi.
        */
        if(min != i){
            std::swap(val[i],val[min]);
        }
    }
}
/**
 * @brief Fungsi utama program.
 * 
 * Mengatur alur eksekusi: meminta input dari user, memanggil fungsi sorting,
 * dan menampilkan hasilnya.
 * 
 * @return int Status keluar dari program (0 berarti sukses).
 */
int main(){
    int value;
    int count;
    // meminta user untuk memasukkan panjang data vector
    std::cout << "Masukkan panjang data: ";
    std::cin >> count;
    std::vector<int> val(count);
    for(int i = 0; i < count; i++){
        std::cout << "Masukkan data ke " << i + 1 << ": ";
        std::cin >> val[i]; //memasukkan nilai yg dimasukkan(value) ke vector val
    }
    SelectionSort(val);
    std::cout << "sesudah sorting " << std::endl;
    PrintVec(val);
    std::cout << std::endl;
    return 0;
}