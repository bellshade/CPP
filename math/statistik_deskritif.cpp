#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
using namespace std;

// Struktur untuk menyimpan hasil statistik
struct DataStatistic{
    float EvenMedian;  // Median jika jumlah data genap
    float OddMedian;   // Median jika jumlah data ganjil
    float size;        // Ukuran data
    float IQR;         // Interquartile Range
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
void PrintData(vector<float>& val){
    for(int i = 0; i < val.size(); i++){
        cout << val[i] << " ";
    }
}

// Fungsi untuk mencetak outlier dalam vektor (jika ada)
void PrintOutliers(vector<float>& val){
    for(float hasil: val){
        cout << hasil << " ";
    }
}

// Fungsi untuk mengurutkan data dengan Selection Sort
void sort(vector<float>& val, DataStatistic &stats){
    stats.size = val.size();  // Mengupdate ukuran data pada struktur statistik
    for(int i = 0; i < stats.size - 1; i++){
        int min = i;  // Asumsi elemen minimum berada di posisi pertama dari iterasi
        for(int j = i + 1; j < stats.size; j++){
            // Update posisi minimum jika ditemukan elemen lebih kecil
            if(val[j] < val[i]){
                min = j;
            }
        }
        // Tukar elemen di posisi i dengan elemen terkecil yang ditemukan
        if(min != i){
            swap(val[i], val[min]);
        }
    }
}

// Fungsi untuk menghitung median dari data
void median(vector<float>& val, int &count, DataStatistic &stats){
    if(val.size() % 2 == 0){ // Jika jumlah data genap
        stats.EvenMedian = (val[val.size() / 2 - 1] + val[val.size() / 2]) / 2.0;
        cout << "Nilai Median: " << stats.EvenMedian << "\n" << endl;
    } else { // Jika jumlah data ganjil
        stats.OddMedian = val[val.size() / 2];
        cout << "Nilai Median: " << stats.OddMedian << "\n" << endl;
    }
}

// Fungsi untuk menghitung rata-rata (mean) dari data
void mean(vector<float>& val, DataStatistic &stats){
    float sum = 0;
    for(int i = 0; i < val.size(); i++){
        sum += val[i]; // Menambahkan semua elemen dalam data
    }
    float ResultMean = (sum / val.size()); // Rata-rata dari jumlah elemen
    cout << "\nNilai rata-rata: " << ResultMean << " \n" << endl;
}

// Fungsi untuk menghitung rentang (range) data
void range(vector<float>& val, DataStatistic &stats){
    float ResultRange = val[val.size() - 1] - val[0]; // Selisih antara elemen maksimum dan minimum
    cout << "Nilai Range: " << ResultRange << "\n" << endl;
}

// Fungsi untuk menghitung Interquartile Range (IQR) dari data
void IQR(vector<float>& val, DataStatistic& stats){
    stats.Q1 = val[val.size() / 4];           // Elemen pada posisi 25% dari data (Kuartil 1)
    stats.Q3 = val[3 * val.size() / 4];       // Elemen pada posisi 75% dari data (Kuartil 3)
    stats.IQR = stats.Q3 - stats.Q1;          // Rentang antara Q3 dan Q1
    cout << "Nilai IQR: " << stats.IQR << endl;
}

int main(){
    DataStatistic stats;  // Inisialisasi struktur DataStatistic untuk menyimpan hasil
    int count;            // Variabel untuk menampung jumlah data yang akan diinput
    float value;          // Variabel sementara untuk nilai input dari pengguna
    vector<float> val;    // Vektor untuk menyimpan data input

    // Mengambil input panjang data dari pengguna
    cout << "Masukkan panjang sample data: ";
    cin >> count;

    // Loop untuk mengambil input data
    for(int i = 0; i <= count -1; i++){
        cout << "Masukkan data ke " << i + 1 << ": ";
        cin >> value;
        val.push_back(value); // Menambahkan data ke vektor
    }

    cout << "Hasil Statistik dasar \n" << endl;

    // Flag untuk mengecek apakah data sudah terurut
    bool sorted = true;
    for (int i = 0; i < val.size() - 1; ++i) {
        if (val[i] > val[i + 1]) {
            sorted = false;
            break; // Keluar dari loop jika ditemukan ketidakurutan
        }
    }

    if (!sorted) {
        cout << "Data tidak terurut!\n";
        sort(val, stats); // Mengurutkan data jika belum terurut
        cout << "Data yang telah di sort: ";
        PrintData(val);
    } else {
        cout << "Data sudah terurut: ";
        PrintData(val);
    }

    mean(val, stats);      // Menghitung rata-rata
    median(val, count, stats); // Menghitung median
    range(val, stats);      // Menghitung rentang
    IQR(val, stats);        // Menghitung IQR
}
