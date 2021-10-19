#include <iostream>

int main(){
    // mendeklarasikan array dengan panjang element 5
    int nilai_siswa[5] = {12, 100, 50, 90, 80};

    // menampilkan nilai array
    std::cout << nilai_siswa[2] << std::endl;

    // menampilkan semua array
    // dengan menggunakan for loop
    for (int i = 0; i < 5; i++){
        // menampilkan semua array
        std::cout << nilai_siswa[i] << std::endl;
    }
    return 0;
}