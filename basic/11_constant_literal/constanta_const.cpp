#include <iostream>

int main(){
    // deklarasi variabel dengan const
    const int PANJANG = 20;
    const int LEBAR = 2;
    int hasil;
    // kalkulasi
    hasil = PANJANG * LEBAR;
    // menampilkan hasil
    std::cout << "Hasil perhitungan adalah " << hasil;

    return 0;
}