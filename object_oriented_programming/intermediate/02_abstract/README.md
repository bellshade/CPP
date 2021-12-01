# abstract

abstarct data mengacu pada penyediaan hanya informasi penting ke dunia luar dan menyembunyikan detaillatar belakang mereka, yaitu, untuk mewakili informasi yang dibutuhkan dalam program tanpa menyajikan detailnya.

abstraksi data adalah tkenik pemograman (dan desain) yang bergantung pada pemisahan antarmuka dan implementasi

dalam c++, kelas menyediakan tingkat **abstracksi data yang luar biasa**.mereka menyediakan metode publik yang cukup untuk dunia luar untuk bermain dengan fungsionalitas objekdan untuk memanipulasi dua objek, yaitu, menyatakan tanpa benar-benar mengetahui bagaimana kelas telah diimplementasi secara internal.

misalnya program kita  membuat panggilan ke fungsi **sort()** tanpa mengetahui algoritma apa yang sebenarnya digunakan fungsi tersebut untuk mengurutkan nilai yang diberikan.  faktanya, implementasi yang mendasari fungsi pentortiran dapat berubah di antara rilis perpustakaan, dan selama antarmuka tetap sama, panggilan fungsi kita akan tetap berfungsi

dalam c++kita menggunakan kelas untuke mendifinisikan tipe data abstrak kita sendiri. kita dapat menggunakan objek **cout** dari class **ostream** untuk mengalirkan data ke output standar seperti ini

```cpp
#include <iostream>

int main(){
    std::cout<<"bellshade cpp";

    return 0;
}
```

## manfaat dari abstraksi
abstraksi data memberikan dua keuntungan penting
- internalkelasdilindungi dari kesalahan tingkat pengguna yang  tidakd isengaja yangmungkin merusak status objek.

- implementasikelas  dapat berkembangdari waktuke waktu sebagai tanggapan terhadap perubahan persyaratan atau laporan bug tanpa memerlukan perubahan kode tingkat pengguna

dengan mendifinisikananggotadata hanya di bagian pribadi kelas, pembuat kelasbebas untuk membuat perubahan pada data. jika implementasi berubah hanya kode kelas yang perlu diperiksa untuk melihat apa yagn mempengaruhi perubahan tersebut. jika data bersifatpublik,maka fungsi apa pun yagn secara langsung mengakses anggota d ata dari representasi lama mungkin akan rusak.

setiap program c++ di mana kita mengimplementasikan kelas dengan anggota publik dan pribadi adalah contoh dari abstraksi data

```cpp
#include <iostrea>

class Tambah{
    public:
        // membuat konstruktor
        Tambah(int i = 0){
            total = i;
        }

        // interface dari luar
        void tambahAngka(int angka){
            total += angka;
        }

        int getTotal(){
            return total;
        }
    
    private:
        // membuat data yang bersifat non publik
        int total;
};

int main(){
    // memanggil kelas
    // dan membuat objek baru
    Adder a;
    
    // memanggil fungsi tambah angka
    a.tambahAngka(2);
    a.tambahAngka(3);
    a.tambahAngka(5);
    
    std::cout<<"total "<<a.getTotal()<<std::endl;

    return 0;
}
```