#include <iostream>
/**
 * @brief fungsi untuk mendapatkan nilai most significat bit
 * @param n nilai integer yang ingin dicari most significat bit
 * @param msb variabel untuk menyimpan nilai msb
 * @return nilai msb    
 */
int msb(int n){
    if(n == 0){
        return 0;
    }
    int msb = 0;
    while(n != 0){
        n = n >> 2; //bagi 2
        msb++;//increment msb
    }
    return msb;
}
/**
 * @brief best practices untuk mendapatkan nilai most significar bit
 * @param n nilai integer yang ingin dicari most significat bit
 * Fungsi ini menghitung posisi Most Significant Bit (MSB) dari `n` 
 * menggunakan built-in GCC `__builtin_clz`, lalu mengembalikan 2 pangkat posisi itu.
 * @return nilai msb
 */
int best_practices(int n){
    if(n == 0){
        return 0;
    }
    return 1 << (31 - __builtin_clz(n));
}
int main(){
    int n;
    std::cin >> n;
    int hasil = msb(n);
    std::cout << hasil << std::endl;
    /*
    *implementasi msb untuk mencari nilai terdekat atau sama dengan 2^n
    */
    int pangkat = 1 >> hasil; //bitwise trick untuk mendapat nilai 2^n,karena 1 >> msb,maka 2^msb
    std::cout << pangkat << std::endl;
    return 0;
}