#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

// Struktur untuk menyimpan hasil statistik
struct DataStatistic{
    float EvenMedian;  // Median jika jumlah data genap
    float OddMedian;   // Median jika jumlah data ganjil
    float size;        // Ukuran data
    float IQR;         //nilai InterKuartile
    float Q1;          // Kuartil pertama (25% dari data)
    float Q3;          // Kuartil ketiga (75% dari data)
};

// Fungsi untuk menukar dua nilai integer
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi untuk mencetak elemen-elemen dalam vektor
void PrintData(std::vector<float>& val){
    for(int i = 0; i < val.size(); i++){
        std::cout << val[i] << " ";
    }
}

// Fungsi untuk mengurutkan data dengan Selection Sort
void sort(std::vector<float>& val, DataStatistic &stats){
    for(int i = 0; i < val.size() - 1; i++){
        int min = i;  // Asumsi elemen minimum berada di posisi pertama dari iterasi
        for(int j = i + 1; j < val.size(); j++){
            // Update posisi minimum jika ditemukan elemen lebih kecil
            if(val[j] < val[i]){
                min = j;
            }
        }
        // Tukar elemen di posisi i dengan elemen terkecil yang ditemukan
        if(min != i){
            std::swap(val[i],val[min]);
        }
    }
}

// Fungsi untuk menghitung median dari data
void median(std::vector<float>& val, int &count, DataStatistic &stats){
    if(val.size() % 2 == 0){ // Jika jumlah data genap
        stats.EvenMedian = (val[val.size() / 2 - 1] + val[val.size() / 2]) / 2.0;
        std::cout << "Nilai Median: " << stats.EvenMedian << "\n" << std::endl;
    } else { // Jika jumlah data ganjil
        stats.OddMedian = val[val.size() / 2];
        std::cout << "Nilai Median: " << stats.OddMedian << "\n" << std::endl;
    }
}

// Fungsi untuk menghitung rata-rata (mean) dari data
void mean(std::vector<float>& val, DataStatistic &stats){
    float sum = 0;
    for(int i = 0; i < val.size(); i++){
        sum += val[i]; // Menambahkan semua elemen dalam data
    }
    float ResultMean = (sum / val.size()); // Rata-rata dari jumlah elemen
    std::cout << "\nNilai rata-rata: " << ResultMean << " \n" << std::endl;
}

// Fungsi untuk menghitung rentang (range) data
void range(std::vector<float>& val, DataStatistic &stats){
    float ResultRange = val[val.size() - 1] - val[0]; // Selisih antara elemen maksimum dan minimum
    std::cout << "Nilai Range: " << ResultRange << "\n" << std::endl;
}

// Fungsi untuk menghitung Interquartile Range (IQR) dari data
void IQR(std::vector<float>& val, DataStatistic& stats){
    stats.Q1 = val[val.size() / 4];           // Elemen pada posisi 25% dari data (Kuartil 1)
    std::cout << "Nilai Q1 " << stats.Q1 << std::endl;
    stats.Q3 = val[3 * val.size() / 4];       // Elemen pada posisi 75% dari data (Kuartil 3)
    std::cout << "Nilai Q3: " << stats.Q3 << std::endl;
    stats.IQR = stats.Q3 - stats.Q1;          // Rentang antara Q3 dan Q1
    std::cout << "Nilai IQR: " << stats.IQR << std::endl;
}

int main(){
    DataStatistic stats;  // Inisialisasi struktur DataStatistic untuk menyimpan hasil
    int count;            // Variabel untuk menampung jumlah data yang akan diinput
    float value;          // Variabel sementara untuk nilai input dari pengguna
    std::vector<float> val;    // Vektor untuk menyimpan data input

    // Mengambil input panjang data dari pengguna
    std::cout << "Masukkan panjang sample data: ";
    std::cin >> count;

    // Loop untuk mengambil input data
    for(int i = 0; i <= count -1; i++){
        std::cout << "Masukkan data ke " << i + 1 << ": ";
        std::cin >> value;
        val.push_back(value); // Menambahkan data ke vektor
    }

    std::cout << "Hasil Statistik dasar \n" << std::endl;

    // Flag untuk mengecek apakah data sudah terurut
    bool sorted = true;
    for (int i = 0; i < val.size() - 1; ++i) {
        if (val[i] > val[i + 1]) {
            sorted = false;
            break; // Keluar dari loop jika ditemukan ketidakurutan
        }
    }

    if (!sorted) {
        std::cout << "Data tidak terurut!\n";
        sort(val, stats); // Mengurutkan data jika belum terurut
        std::cout << "Data yang telah di sort: ";
        PrintData(val);
    } else {
        std::cout << "Data sudah terurut: ";
        PrintData(val);
    }

    mean(val, stats);      // Menghitung rata-rata
    median(val, count, stats); // Menghitung median
    range(val, stats);      // Menghitung rentang
    IQR(val, stats);        // Menghitung IQR
}