# struct

Dalam C++ struct dan kelas pada dasarnya sama. tetapi ada beberapa perbedaan kecil. 
- anggota kelas bersifat pribadi secara default, tetapi anggota struktur bersifat publik. contoh program.
```cpp
#include <iostream>

class Kelas_saya{
    int angka = 10;
};

int main(){
    Kelas_saya objek_saya;
    std::cout << objek_saya.angka;
}
```
Ketika kita menurunkan struktur dari kelas atau struktur, penentu akses default dari kelas dasar itu adalah publik, tetapi ketika kita menurunkan kelas, penentu akses default adalah private.
```cpp
#include <iostream>

struct Struct_saya{
    int angka_saya = 10;
    int angka_saya2 = 20;
};

int main(){
    Struct_saya objek_saya;
    
    std::cout << "angka pertama " << objek_saya.angka_saya << std::endl;
    std::cout << "angka kedua " << objek_saya.angka_saya2 << std::endl;
}
```

# FYI (For Your Information) / Reference
- Informasi lebih lanjut dari struct bisa dilihat [disini](https://www.youtube.com/watch?v=ELCI_U4OF5w&list=PLZS-MHyEIRo4Ze0bbGB1WKBSNMPzi-eWI&index=61)