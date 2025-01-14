#include <iostream>
#include <vector>
#include <cmath>
// Struct untuk menyimpan nilai-nilai statistik yang akan digunakan
struct Data{
    float deviasiX; // Penyimpangan X
    float DeviasiY; // Penyimpangan Y
    float meanX;    // Rata-rata X
    float meanY;    // Rata-rata Y
    float size;     // Ukuran dataset
    int SquareDeviation; // Total kuadrat penyimpangan
    float Multiple_Variance; // Varians berganda antara X dan Y
};
// Fungsi untuk menghitung rata-rata X dan Y
void mean(std::vector<float>& independent, std::vector<float>& dependent, Data &stats){
    float sumX = 0; // Variabel untuk menyimpan total X
    float sumY = 0; // Variabel untuk menyimpan total Y
    // Loop untuk menghitung total X dan Y
    for(int i = 0; i <= independent.size() - 1; i++){
        sumX += independent[i];
        sumY += dependent[i];
    }
    // Menghitung rata-rata X dan Y
    stats.meanX = sumX / stats.size;
    stats.meanY = sumY / stats.size;
    // Menampilkan hasil rata-rata ke konsol
    std::cout << "Nilai rata - rata X: " << stats.meanX << std::endl;
    std::cout << "Nilai rata - rata Y :" << stats.meanY << std::endl;
}
// Fungsi untuk menghitung deviasi (penyimpangan) dan varians berganda
void deviasi(std::vector<float>& independent, std::vector<float>& dependent, Data &stats){
    float sumDevX = 0; // Penyimpangan X total
    float sumDevY = 0; // Penyimpangan Y total
    float squareDev = 0; // Total kuadrat penyimpangan
    float SumVariance = 0; // Total varians berganda
    float DevX, DevY, MultiptleVariance; // Variabel sementara untuk deviasi dan varians
    int roundSquareDev; // Variabel sementara untuk kuadrat penyimpangan (dibulatkan)
    float SquareDeviation; // Kuadrat penyimpangan sementara
    // Loop untuk menghitung deviasi X dan kuadrat penyimpangan
    for(int i = 0; i <= independent.size() - 1; i++){
        DevX = independent[i] - stats.meanX; // Deviasi X
        sumDevX += DevX; // Menambahkan deviasi X ke total
        DevY = dependent[i] - stats.meanY; // Deviasi Y
        SquareDeviation = pow(independent[i] - stats.meanX, 2); // Kuadrat penyimpangan X
        squareDev += SquareDeviation; // Menambahkan kuadrat penyimpangan ke total
    }
    // Loop untuk menghitung varians berganda antara X dan Y
    for(int i = 0; i <= independent.size() - 1; i++){
        MultiptleVariance = (independent[i] - stats.meanX) * (dependent[i] - stats.meanY); // Varians berganda
        SumVariance += MultiptleVariance; // Menambahkan varians berganda ke total
    }
    // Menyimpan hasil varians berganda dan kuadrat penyimpangan ke struct Data
    stats.Multiple_Variance = SumVariance;
    stats.SquareDeviation = squareDev;
    // Menampilkan hasil ke konsol
    std::cout << "Hasil: " << stats.Multiple_Variance << std::endl;
    std::cout << "Total Nilai Square deviasi: " << stats.SquareDeviation << std::endl;
}
// Fungsi untuk menghitung regresi linear dan menampilkan persamaan linear
void Regression(std::vector<float>& independent, std::vector<float>& dependent, Data &stats){
    double KoefRegression,slope; 
    // Koefisien regresi (slope) slope = Intercept
    // Menghitung koefisien regresi
    KoefRegression = stats.Multiple_Variance / stats.SquareDeviation;
    // Menghitung intercept
    slope = stats.meanY - (KoefRegression * stats.meanX);
    // Menampilkan persamaan regresi linear ke konsol
    std::cout << "Maka Persamaan Linear Regression: " << KoefRegression << " + " << slope << "x" << std::endl;
}
int main(){
    Data stats; // Struct untuk menyimpan data statistik
    int count, val_in, val_den; // Variabel input (tidak digunakan karena sudah ada data statis)
    // Data statis untuk independent (X) dan dependent (Y)
    std::vector<float>independent = {48,63,36,24,24,55,25,24,46,55,20,51,41,21,49,31,31,26,43,52};
    std::vector<float>dependent = {45,46,49,56,68,62,56,58,45,36,74,53,75,57,50,39,62,73,57,50};
    // Menentukan ukuran dataset
    stats.size = independent.size();
    // Memanggil fungsi untuk menghitung rata-rata
    mean(independent, dependent, stats);
    // Memanggil fungsi untuk menghitung deviasi dan varians berganda
    deviasi(independent, dependent, stats);
    // Memanggil fungsi untuk menghitung regresi linear
    Regression(independent, dependent, stats);
    std::cin.get(); // Menahan program agar tidak langsung selesai
    return 0; // Mengembalikan nilai 0 sebagai tanda program selesai dengan sukses
}
