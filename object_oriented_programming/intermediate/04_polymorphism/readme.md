# polimorfisme

kata polimorfisme berarti memliki banyak bentuk. biasanya, polimorfisme terjadi ketika ada hirarki kelas dan mereka terkait dengan pewarisan (inheritance). polimorfisme c++ berarti bahwa panggilan ke fungsi anggota akan menyebabkan fungsi yang berbeda dieksekusi tergantun pad jenis objek uyang memanggil fungsi tersebut.

```cpp
#include <iostream>

class Bentuk{
    protected:
        int lebar, tinggi;
    
    public:
        Bentuk(int a = 0, int b = 0){
            lebar = a;
            tinggi = b;
        }
        
        int area(){
            std::cout<<"parent class area :"<<std::endl;

            return 0;
        }
};

class Persegi: public Shape{
    public:
        Persegi(int a = 0, int b = 0): Bentuk(a, b){}

        int area(){
            std::cout<<"Persegi dari kelas persegi:"<<std::endl;

            return (lebar * tinggi);
        }
};

class Segitiga: public Shape{
    public:
        Segitiga(int a = 0, int b = 0): Bentuk(a, b){}

        int area(){
            std::cout<<"Segitiga dari kelas segitiga:"<<std::endl;

            return (lebar * tinggi / 2);
        }
};

int main(){
    Bentuk *bentuk;
    Persegi persegi(10, 4);
    Segitiga segitiga(12, 6);

    // menyimpan address dari persegi
    bentuk = &persegi

    // memanggil persegi
    bentuk -> area();

    // menyimpan address dari segitiga
    bentuk = &segitiga;

    //memanggil segitiga
    bentuk -> segitiga();

    return 0;
}
```
ketika kode diatas di kompilasi maka menghasilkan output
```
parent class area:
parent class area:
```
Alasan untuk keluaran yang salah adalah bahwa panggilan fungsi ``area()`` sedang disetel sekali oleh kompilator sebagai versi yang didefinisikan di kelas dasar. Ini disebut resolusi statis dari panggilan fungsi, atau hubungan statis - panggilan fungsi diperbaiki sebelum program dijalankan. Ini juga terkadang disebut pengikatan awal karena fungsi ``area()`` disetel selama kompilasi program.

tapi sekarang, mari kita buat sedikit modifikasi pada program kita dan mendahului deklarasi ``area()`` di kelas ``bentuk`` dengan kata kunci **virtual** sebgai contoh

```cpp
class Bentuk{
    protected:
        int lebar, tinggi;
    
    public:
        Bentuk(int a = 0, int b = 0){
            lebar = a;
            tinggi = b;
        }
        
        virtual int area(){
            std::cout<<"parent class area :"<<std::endl;

            return 0;
        }
};
```

Kali ini, kompilator melihat isi dari pointer, bukan tipenya. Oleh karena itu, karena alamat objek dari kelas tri dan rec disimpan dalam bentuk ``*``, masing-masing fungsi ``area()`` dipanggil.

## fungsi virtual

sebuah fungsi **virtual** adalah fungsi di kelas dasar yang dinyatakan menggunakan kata kunci **virtual**, dengan versi lain di kelas turunan, memberi sinyal kepada kompiler bahwa kita tidak menginginkan hubungan statis untuk fungsi ini.

Apa yang kita inginkan adalah pemilihan fungsi yang akan dipanggil pada setiap titik tertentu dalam program yang didasarkan pada jenis objek yang dipanggil. Operasi semacam ini disebut sebagai **dynamic linkage** , atau **late binding** .

## fungsi pure virtual

ada kemungkinan bahwa kita ingin mnyertakan fungsi virutal di kelas dasar sehingga dapat didefinisikan ulang di kelas turunan agar sesuia dengan objek kelas itu, tetapi tidak ada defiinisi bermakna yang dapat kita berika untuk fungsi di kelas dasar

kita dapat mengubah area fungsi ``virtual()`` di kelas dasar menjadi
```cpp
class Bentuk{
    protected:
        int lebar, tinggi;

    public:
        Bentuk(int a = 0, int b = 0){
            lebar = a;
            tinggi = b;
        }
        
        virtual int area() = 0;
};
```
``=0`` memberitahu kompiler bahwa fungsi tidak memiliki tubuh dan fungsi virtual di atas akan disebut dengan **fungsi virtual murni**.