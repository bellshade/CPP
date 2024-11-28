#include <iostream>
#include <cmath>
#include <vector>

/*pilihan pertama buat dalam 1 void function 
pilihan kedua adalah buat dalam beberapa void
 function di ikuti dengan penggunaaan struct
*/
// sumber soal: https://mathcyber1997.com/regresi-linear-sederhana/ - > nomor 1 
struct DataStatistic{
    float SumX;
    float SumY;
    float Xsquared;
    float Ysquared;
    float multiply;
};
void Squared(std::vector<float>& independen, std::vector<float>& dependen,DataStatistic &stats){
    // bisa menggunakan pow bawaan STL cmath atau langsung dengan metode manual
    //contoh menggunakan pow
    float SumSquared = 0;
    float XSquared;
    for(int i = 0; i <= independen.size() - 1; i++){
        XSquared = pow(independen[i],2);  // variabel ,pangkat
        SumSquared += XSquared;
    }
    stats.Xsquared = SumSquared;
    std::cout << "Hasil X squared " << stats.Xsquared << std::endl;


    //contoh metode manual
    float SumYSquared = 0;
    float Ysquared;
    for(int i = 0; i <= dependen.size() - 1;i++){
        Ysquared = dependen[i] * dependen[i];
        SumYSquared = SumYSquared + Ysquared; // bisa juga dengan +=
    }
    stats.Ysquared = SumYSquared;
    std::cout << "Hasil Y squared " << stats.Ysquared << std::endl;

}
void sum(std::vector<float>& independen, std::vector<float>& dependen,DataStatistic &stats){
    float sumx = 0;
    float sumy = 0;

    for(int i = 0; i <= independen.size() - 1;i++){
        // karena panjang data sama maka cukup 1 for loop
        sumx += independen[i];
        sumy += dependen[i];
    }
    stats.SumX = sumx;
    stats.SumY = sumy;

    std::cout << "SumX: " << stats.SumX << std::endl;
    std::cout << "SumY: " << stats.SumY << std::endl;
}


void multiple(std::vector<float>& independen, std::vector<float>& dependen,DataStatistic &stats){
    float multiply;
    float SumMultiply = 0;
    for(int i = 0; i <= independen.size() - 1; i++){
        multiply = independen[i] * dependen[i];
        SumMultiply += multiply;
    }
    stats.multiply = SumMultiply;
    std::cout << "Hasil Kali: " << stats.multiply << std::endl;
}


void LinearRegression(std::vector<float>& independen, std::vector<float>& dependen,DataStatistic &stats){
    double SumSquareXX;
    double SumSquareXY;


    SumSquareXY = stats.multiply - ((stats.SumX * stats.SumY)/ independen.size());
    SumSquareXX = stats.Xsquared - (pow(stats.SumX,2)/independen.size());
    // print untuk memastikan hasil nya benar
    std::cout << "Hasil SumSquareXY: " << SumSquareXY << std::endl;
    std::cout << "Hasil SumSquareXX: " << SumSquareXX << std::endl;


    // b0 = intercept
    // b1 = gradient atau slope

    double Slope,Intercept;

    Slope = SumSquareXY / SumSquareXX;

    Intercept = (stats.SumY - (Slope * stats.SumX)) / independen.size();

    std::cout << "Model Regresi Linear = " << Intercept << " + " << Slope << "x ";
}

int main(){
    DataStatistic stats;
    std::vector<float> independen = {1,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,2};
    std::vector<float> dependen = {8.1,7.8,8.5,9.8,9.5,8.9,8.6,10.2,9.3,9.2,10.5};
    int count,IndependenValue,DependenValue;

    //karena tahap production kita akan memakai data yg sudah ada saja
    //anda dapat men uncomment code dibawah dan menghapus data pada vector dependen dan dependen



    // std::cout << "Masukkan panjang data: ";
    // std::cin >> count;
    // for(int i = 0; i <= count - 1; i++){
    //     std::cout << "Masukkan data x: ";
    //     std::cin >> IndependenValue;
    //     independen.push_back(IndependenValue);
    //     std::cout << "Masukkan data y: ";
    //     std::cin >> DependenValue;
    //     dependen.push_back(DependenValue);
    // }
    float sum_x = independen.size();
    float sum_y = dependen.size();
    sum(independen,dependen,stats);
    Squared(independen,dependen,stats);
    multiple(independen,dependen,stats);
    LinearRegression(independen,dependen,stats);
    std::cin.get();
}