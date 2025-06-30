#include <iostream>
#include <vector>
#include <cmath>
#include <stdlib.h>
#define ITERASI_MAX 1000000
#define EPSILON 1e-6 //Epsilon dipakai untuk membatasi toleransi error
//sumber 1 : https://www.geeksforgeeks.org/regula-falsi-method/
//sumber 2:https://byjus.com/maths/false-position-method/

/**
 * @brief Fungsi untuk menghitung nilai dari suatu polinomial
 *        berdasarkan koefisien yang diberikan.
 *
 * @param x Nilai variabel independen dalam polinomial.
 * @param Koefisien Vektor yang berisi koefisien polinomial,
 *                 dimulai dari derajat tertinggi hingga 0.
 * @return Hasil evaluasi polinomial pada x.
 */
double FungsiPolynomial(double x, const std::vector<double>& Koefisien){
    double result = 0;
    int pangkat = Koefisien.size() - 1;
    for(int i = 0; i <= pangkat; i++){
        result += Koefisien[i] * pow(x,pangkat - i);
    }
    return result;
}

/**
 * @brief Implementasi metode Regula Falsi untuk mencari akar fungsi.
 *
 * @param a Batas bawah interval pencarian akar.
 * @param b Batas atas interval pencarian akar.
 * @param Koefisien Vektor koefisien polinomial.
 */
void RegulaFalsi(double a, double b, const std::vector<double>& Koefisien){
    if(FungsiPolynomial(a,Koefisien) * FungsiPolynomial(b,Koefisien) >= 0){
        std::cout << "Asumsi interval [a, b] salah, harus f(a) dan f(b) memiliki tanda berbeda.\n";
        return;
    }
    std::cout << "Interval awal: [" << a << ", " << b << "]\n";
    double c = a;
    for(int i = 0; i < ITERASI_MAX; i++){
        double fa = FungsiPolynomial(a,Koefisien);
        double fb = FungsiPolynomial(b,Koefisien);
        // Temukan titik yang menyentuh sumbu x
        c = (a * fb - b * fa) / (fb - fa);
        // Periksa apakah titik yang ditemukan di atas adalah akar/root
        if(fabs(FungsiPolynomial(c,Koefisien)) < EPSILON){
            break;
        }else if(FungsiPolynomial(c,Koefisien) * fa < 0){
            /* 
            Jika f(c) * f(a) < 0, berarti akar terletak di antara a dan c
            Maka kita perbarui batas atas b menjadi c
            */
            b = c;
        }else{
            /*
            Jika f(c) * f(a) >= 0, maka akar terletak di antara c dan b
            Maka kita perbarui batas bawah a menjadi c
            */
            a = c;
        }
    }
    std::cout << "\n" << "Nilai akar adalah: " << c;
}

int main(){
    std::vector<double> Koefisien;
    double a = -2, b = 2;  //nilai a dan b harus berbeda tanda
    int pilihan,koef;
    std::cout << "Pilihan " << "\n";
    std::cout << "1. Fungsi derajat 3 " << "\n";
    std::cout << "2. Fungsi Derajat 4 " << "\n";
    std::cout << "Masukkan pilihan: ";
    std::cin >> pilihan;
    system("clear");
    
    while(pilihan < 1 || pilihan > 2){
        std::cout << "Anda memasukkan input yang salah! Masukkan kembali: ";
        std::cin >> pilihan;
        system("clear");
    }
    
    int step = 3;
    if(pilihan == 1){
        for(int i = 0; i < 4; i++){
            std::cout << "Masukkan koefisien derajat " << step << ": ";
            std::cin >> koef;
            Koefisien.push_back(koef);
            step--;
        }
    }else if(pilihan == 2){
        for(int i = 0; i < 5; i++){
            std::cout << "Masukkan koefisien derajat " << step + 1 << ": ";
            std::cin >> koef;
            Koefisien.push_back(koef);
            step--;
        }
    }else{
        std::cerr << "Pilihan tidak valid! Harap masukkan 1 atau 2.\n";
    }
    
    RegulaFalsi(a, b, Koefisien);
    std::cin.get();
    return 0;
}
