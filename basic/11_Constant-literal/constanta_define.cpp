#include <iostream>

// deklarasi preprosesor dengan #define
#define PANJANG 20
#define LEBAR 2

int main(){
    
    // deklarasi variabel hasil
    int hasil;
    // kalkulasi
    hasil = PANJANG * LEBAR;
    // menampilkan hasil
    std::cout << "Hasil perhitungan adalah " << hasil;

    return 0;
}