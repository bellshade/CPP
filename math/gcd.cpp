/**
 * @file gcd.cpp 
 * source code untuk mencari faktor persekutuan terbesar 2 bilangan
 * dengan 2 metode yaitu:
 * - iterative approach dan 
 * - euclidean algorithm dengan pendekatan recursive
 * 
 * @authors Yusuf
 * 
 * @date juli 2025
 * 
 */
#include <iostream>
#include <algorithm>
/**
 * @brief fungsi untuk mendapatkan nilai Faktor Persekutuan terbesar(GCD)
 * dengan metode loop atau iterative approach
 * cara kerja adalah tentukan nilai minimum a dan b
 * lakukan backward iter untuk mencari nilai yang dapat membagi a dan b 
 * cari bilangan pertama yang membagi habis a dan b dengan nilai minimum
 * @param a bilangan pertama
 * @param b bilangan kedua
 * @details time complexity O(min(a,b)) Space Compelixity O(1)
 */
void Gcd(int a,int b){
    int hasil = std::min(a,b);
    while(hasil > 0){
        if(a % hasil == 0 && b % hasil == 0){
            break;
        }
        hasil--;
    }
    std::cout << "gcd(" << a << "," << b << ")" << " = " << hasil << std::endl;
}
/**
 * @brief fungsi untuk mendapatkan nilai Faktor Persekutuan terbesar(GCD)
 * Mencari nilai FPB (GCD) menggunakan algoritma Euclidean 
 * dengan metode pengurangan dan pendekatan recursive
 * @param a bilangan pertama
 * @param b bilangan kedua
 * @details time complexity O(min(a,b)), Space Compelixity O(min(a,b))
 */
int EuclideanAlgorithm(int a,int b){
    //base case
    if(a == 0){
        return b;
    }
    //base case
    if(b == 0){
        return a;
    }
    //base case
    if(a == b){
        return a;
    }
    //jika lebih besar dari b,kurangi sampai b = 0
    if(a > b){
        return EuclideanAlgorithm(a - b,b);
    }
    //jika b lebih besar dari a kurangi sampai a = 0
    return EuclideanAlgorithm(a,b - a);
}
/**
 * @brief fungsi utama untuk menginput bilangan pertama(a) dan bilangan kedua(b)
 * lalu memanggil fungsi yang digunakan untuk mencari nilai fpb(gcd)
 */
int main(){
    int a,b;
    std::cout << "masukkan bilangan pertama: ";
    std::cin >> a; 
    std::cout << "Masukkan bilangan kedua: ";
    std::cin >> b;
    Gcd(a,b);
    int gcd = EuclideanAlgorithm(a,b);
    std::cout << "gcd(" << a << "," << b << ")" << " = " << gcd << std::endl;
    /*
    test case disarankan
    a = 20 b = 28
    visualisasi
    - pemanggilan pertama
    tidak ada base case memenuhi 
    karena a < b
    eksekusi return (a,b - a)
    maka:
    a = 20 b = 8
    - pemanggilan kedua
    belum ada base case memenuhi
    karena a > b
    eksekusi return (a - b,b);
    maka:
    a = 12,b = 8
    - pemanggilan ketida
    belum ada base case yang memenuhi
    karena a > b
    eksekusi return(a - b,b):
    maka:
    a = 4,b = 8
    - pemanggilan ke-empat
    belum ada base case memenuhi
    karena a < b
    eksekusi return(a,b - a)
    maka:
    a = 4,b = 4
    - pemanggiilan kelima
    ada base case memenuhi yaitu a == b
    maka kembalikan a;
    */
    return 0;
}