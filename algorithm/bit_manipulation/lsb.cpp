#include <iostream>
/**
 * @brief fungsi untuk mendapatkan nilai least significant bit
 * @param n nilai unsigned int yang ingin dicari nilai lsb
 * @return mengembalikan nilai least significant bit
 */
int lsb(int n){
    return n & 1;
    /*
    contoh untuk n = 10
    1 0 1 0
    0 0 0 1
    ---------- &
    0 0 0 0 -> nilai biner paling kanan adalah nilai lsb
    */
}
int main(){
    int n;
    std::cin >> n;
    int hasil = lsb(n);
    std::cout << "nilai lsb: "  << hasil << std::endl;
    /*
    salah satu implementasi paling umum least significant bit adalah menentukan
    suatu bilangan:
    *bilangan genap atau;
    *bilangan ganjil
    */
    if(hasil == 1){
        std::cout << "n adalah bilangan ganjil" << std::endl;
    }else{
        std::cout << "n adalah bilangan genap" << std::endl;
    }
    return 0;
}