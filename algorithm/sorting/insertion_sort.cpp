/**
 * @file insertion_sort.cpp
 * 
 * @author Muh Yusuf
 * 
 * @date July 2025
 * 
 * @brief Program untuk mengurutkan data menggunakan algoritma Insertion Sort (naik dan turun).
 * 
 * Program ini meminta pengguna memasukkan sejumlah bilangan bulat, lalu mengurutkan data
 * tersebut dua kali: pertama secara menaik (ascending), lalu secara menurun (descending).
 * Hasilnya akan ditampilkan di terminal.
 */
#include <iostream>
#include <vector>
/**
 * @brief Menampilkan elemen-elemen vector.
 * 
 * @param value Vector integer yang sudah di sort.
 * 
 * Menggunakan range-based loop dan `const reference` agar efisien.
 */
void tampilkan(const std::vector<int>& value){
    for(const auto x: value){
        std::cout << x << " ";
    }
}
/**
 * @brief Mengurutkan elemen vector secara menaik (terkecil ke terbesar).
 * 
 * @param value Vector integer yang akan diurutkan.
 * 
 * Menggunakan algoritma Insertion Sort. Setiap iterasi menyisipkan `key` ke posisi yang tepat
 * dengan mesnggeser elemen-elemen yang lebih besar ke kanan.
 */
void InsertionSortAscending(std::vector<int>& value){  //insertion sort menaik
    for(int i = 1;i < value.size(); i++){
        int key = value[i]; //inialisasi bilangan kedua merupakan key(kunci)
        int j = i - 1;  //inialisasi j adalah bilangan pertama
        while(j >= 0 && value[j] > key){ //operator logika AND akan true jika kedua input true
            /*jka bilangan lebih besar dari 0 dan bilangan lebih besar dari key maka while akan berjalan*/
            value[j + 1] = value[j];  // Geser elemen
            j = j - 1;    //Pindah ke elemen berikutnya di kiri
        }
        value[j + 1] = key; // Masukkan key pada posisi yang benar
    }
}
/**
 * @brief Mengurutkan elemen vector secara menurun (terbesar ke terkecil).
 * 
 * @param value Vector integer yang akan diurutkan.
 * 
 * Insertion Sort dalam urutan descending: menyisipkan `key` di posisi yang benar
 * dengan menggeser elemen yang lebih kecil ke kanan.
 */
void InsertionSortDescending(std::vector<int>& value) { //insertion sort menurun
    for(int i = 1; i < value.size(); i++) {
        int key = value[i]; // key adalah elemen yang akan disisipkan
        int j = i - 1;
        // Geser elemen-elemen yang lebih kecil dari key ke kanan
        while(j >= 0 && value[j] < key) {
            value[j + 1] = value[j]; // Geser elemen
            j = j - 1; // Pindah ke elemen berikutnya di kiri
        }
        value[j + 1] = key; // Masukkan key pada posisi yang benar
    }
}
/**
 * @brief Fungsi utama program.
 * 
 * @return int Status keluar dari program.
 * 
 * Alur program:
 * - Meminta input jumlah elemen
 * - Input data elemen
 * - Melakukan sorting ascending dan menampilkan hasilnya
 * - Melakukan sorting descending dan menampilkan hasilnya
 */
int main(){
    int count;
    //meminta user untuk memasukkan panjang data(vector)
    std::cout << "Masukkan panjang data: ";
    std::cin >> count;
    std::vector<int> value(count);
    for(int i = 0;i < count; i++){
        std::cout << "Masukkan data ke " << i + 1 << ": ";
        std::cin >> value[i];
    }
    //menampilkan vector setelah sorting
    InsertionSortAscending(value);
    std::cout << "Data setelah di urut mulai dari terkecil ";
    tampilkan(value);
    std::cout<<std::endl;
    InsertionSortDescending(value);
    std::cout << "\ndata setelah di urut mulai terbesar ";
    tampilkan(value);
    std::cout<<std::endl;
    // cin.get();
    return 0;
}