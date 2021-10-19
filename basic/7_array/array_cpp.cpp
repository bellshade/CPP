#include <iostream>

int main(){
    // mendklarasikan array dengan panjang element 5
    int nilai_siswa[5] = {12, 100, 50, 90, 80};

    // menampilkan nilai array
    std::cout<<nilai_siswa[2]<<"\n";
    // menampilkan semua array
    // dengan menggunakan looping for
    for (int i = 0 ; i < 5 ; i++){
        // menampilkan semua array
        std::cout<<nilai_siswa[i]<<"\n";
    }
    return 0;
}