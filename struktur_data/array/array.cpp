#include <iostream>

/**
 * @brief Struktur yang menyimpan informasi detail tentang array.
 * 
 * Struktur ini menyimpan kapasitas maksimum array dan jumlah elemen aktif (size)
 * yang saat ini digunakan.
 */
struct DetailArray {
    int capacity = 10;  ///< Kapasitas maksimum array (jumlah slot)
    int size = 0;       ///< Jumlah elemen yang telah diisi dalam array
};

/**
 * @brief Menyisipkan sejumlah elemen ke dalam array statis.
 * 
 * Fungsi ini akan membaca input sebanyak `n` elemen dan menyimpannya ke dalam array
 * selama belum melebihi kapasitas maksimum. Jika kapasitas sudah penuh,
 * proses insert akan dihentikan.
 * 
 * @param arr Referensi ke array statis berukuran tetap (10 elemen).
 * @param da Referensi ke struktur yang menyimpan kapasitas dan ukuran saat ini.
 */
void insert(int (&arr)[10], DetailArray& da) {
    int n = 5; // jumlah elemen yang ingin di-insert

    for (int i = 0; i < n; i++) {
        if (da.size >= da.capacity) {
            std::cout << "Kapasitas Array Penuh!" << std::endl;
            break;
        }
        int data;
        std::cin >> data;
        arr[da.size++] = data;
    }
}

/**
 * @brief Mencetak isi array hingga jumlah elemen yang telah diisi.
 * 
 * Fungsi ini akan mencetak elemen dari indeks 0 hingga `size - 1`.
 * 
 * @param arr Referensi ke array statis.
 * @param da Referensi ke struktur DetailArray untuk mengambil size.
 */
void PrintArray(int (&arr)[10], DetailArray& da) {
    for (size_t i = 0; i < da.size; i++) {
        std::cout << arr[i] << " ";
    }
}

/**
 * @brief Fungsi utama program.
 * 
 * Membuat array statis, kemudian menyisipkan data melalui fungsi `insert`,
 * dan mencetaknya melalui fungsi `PrintArray`.
 * 
 * @return int Status keluar program.
 */
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    DetailArray da;
    int arr[10];

    da.capacity = 10;

    insert(arr, da);
    PrintArray(arr, da);

    return 0;
}
