# encapsulation

semua program c++ terdiri dari dua elemen dasar berikut:

- **pernyataan program(kode)**

    ini adalah bagian dari program yang melakukan tindakan dan disebut fungsi

- **program data** adalah informasi program yang dipengaruhi oleh fungsi program


Enkapsulasi adalah konsep Pemrograman Berorientasi Objek yang mengikat bersama data dan fungsi yang memanipulasi data, dan yang menjaga keduanya aman dari gangguan dan penyalahgunaan luar. Enkapsulasi data mengarah pada konsep OOP yang penting tentang **penyembunyian data**.

**Enkapsulasi data** adalah mekanisme bundling data, dan fungsi yang menggunakannya dan abstraksi data adalah mekanisme yang hanya memperlihatkan antarmuka dan menyembunyikan detail implementasi dari pengguna.

```cpp
class Kotak{
    public:
        double getVolume(void){
            return panjang * isi * tinggi;
        }
    
    private:
        double panjang;
        double isi;
        double tinggi;
};
```

## contoh enkapsulasi data

```cpp
#include <iostream>

class Tambah{
    // akses kelas
    public:
        // konstruktor
        Tambah(int i = 0){
            total = i;
        }

        // interface untuk diluar
        void tambahAngka(int angka){
            total += angka;
        }
        
        // interface untuk diluar
        int getTotal(){
            return total;
        };

    // akses kelas
    private:
        // data yang tidak bisa
        // diakses
        int total;
};

int main(){
    Tambah a;

    a.tambahAngka(10);
    a.tambahAngka(12);

    std::cout<<"total "<<a.getTotal()<<std::endl;

    return 0;
}
```