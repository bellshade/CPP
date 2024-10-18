#include <iostream>
#include <cmath>  // Untuk fungsi exp()
using namespace std;

/**
 * @file sigmoid.cpp
 * @brief Program ini menghitung fungsi sigmoid yang digunakan
 * pada project Machine Learning dan Deep Learning. 
 * Fungsi sigmoid akan menghasilkan nilai antara 0 hingga 1 
 * berdasarkan input.
 */
double sigmoid(double x) {
/**
 * @brief Fungsi Sigmoid untuk menghitung nilai aktivasi
 * yang berada di antara 0 hingga 1.
 * @param x ini merupakan variabel input nilai.
 * Nilai yang diberikan adalah tipe double dan hasilnya
 * berupa nilai sigmoid yang juga dalam tipe double.
 * @return Mengembalikan nilai sigmoid dari input x.
 */
    return 1.0 / (1.0 + exp(-x));  // Rumus sigmoid
}

int main() {
    double x;
    cout << "Masukkan angka: ";
    cin >> x;
    
    // Memanggil fungsi sigmoid dan menampilkan hasilnya
    double result = sigmoid(x);
    cout << "Hasil Sigmoid: " << result << endl;

    return 0;
}
