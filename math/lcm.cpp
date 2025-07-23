/**
 * @file lcm.cpp
 * @brief source code untuk mencari nilai least common divisor dua bilangan
 * 
 * @authors Yusuf
 * 
 * @date juli 2025
 */
#include <iostream>
/**
 * @brief fungsi untuk mendapatkan nilai gcd(greates common divisor)
 * @param a bilangan pertama
 * @param b bilangan kedua
 * @return bilangan yang merepresentasikan gcd/fpb
 */
int gcd(int a,int b){
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
    if(a > b){
        return gcd(a - b,b);
    }else{
        return gcd(a,b - a);
    }
}
/**
 * @brief fungsi untuk mencari nilai least common divisor(lcm) 
 * atau biasa dikenal kelipatan persekutuan terbesar
 * dengan rumus:
 * lcm = (a * b) / gcd(a,b)
 * kita dapat mencari nilai gcd dengan menggunakan 
 * euclid algorithm dengan metode substraction pendekatan rekursif
 * @param a bilangan pertama
 * @param b bilangan kedua
 * @return nilai yang merepresentasikan nilai lcm/kpk
 */
void lcm(int a,int b){
    int fpb = gcd(a,b);

    int kpk = (a * b) / fpb;
    std::cout << "lcm (" << a << "," << b << ") = " << kpk << std::endl;
}
int main(){
    int a,b;
    std::cout << "Masukkan bilangan pertama: ";
    std::cin >> a;
    std::cout << "Masukkan bilangan kedua: ";
    std::cin >> b;
    lcm(a,b);
    return 0;
}