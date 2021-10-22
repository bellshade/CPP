// '#' adalah indikator perintah pre-prosesor
// include adalah perintah untuk memasukan library ke source code
// iostream adalah library standar bawaan C++
// yang berfungsi untuk input dan ouput data
#include <iostream>

// fungsi main() di bawah adalah entry point yang
// merupakan tempat dimana kode akan pertama kali 
// dieksekusi dan dijalankan oleh compiler
// setiap statement pada c++ wajib diakhiri dengan ; (titik koma)
int main(){
    
    // std:: merupakan namespace yang digunakan untuk
    // seluruh standard library C++ termasuk iostream
    // cout yang merupakan salah satu objek dari library iostream,
    // singkatan dari "Character OUTput" digunakan sebagai
    // perintah output dengan menggunakan operator left shift (<<)
    // Pada contoh berikut, kita akan memasukkan kata "bellshade"
    std::cout<<"bellshade!";

    // return 0 adalah perintah untuk mengeluarkan nilai integer 0
    // apabila program berhasil dijalankan tanpa error
    return 0;
}
