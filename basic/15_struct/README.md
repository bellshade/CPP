# struct

Dalam C++ struct dan kelas pada dasarnya sama. tetapi ada beberapa perbedaan kecil. 
- anggota kelas bersifat pribadi secara default, tetapi anggota struktur bersifat publik. contoh program
```cpp
#include <iostream>

class Kelas_saya{
    int angka = 10;
};

int main(){
    Kelas_saya objek_saya;
    std::cout<<objek_saya.angka;
}
```