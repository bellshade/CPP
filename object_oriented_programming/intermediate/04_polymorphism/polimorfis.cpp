#include <iostream>

// membuat kelas bentuk
class Bentuk{
    // akses modifikasi
    protected:
        // membuat atribut
        int lebar, tinggi;
    
    // akses modfikasi
    public:
        // membuat konstruktor
        Bentuk(int a = 0, int b = 0){
            lebar = a;
            tinggi = b;
        }
        
        // membuat fungsi dinamis menggunakan kata kunci
        // virtual
        virtual int area(){
            std::cout<<"parent class area :"<<std::endl;

            return 0;
        }
};

// membuat kelas persegi
class Persegi: public Bentuk{
    public:
        Persegi(int a = 0, int b = 0): Bentuk(a, b){}

        int area(){
            std::cout<<"Persegi dari kelas persegi:"<<std::endl;

            return (lebar * tinggi);
        }
};

// membuat kelas segitiga
class Segitiga: public Bentuk{
    public:
        Segitiga(int a = 0, int b = 0): Bentuk(a, b){}

        int area(){
            std::cout<<"Segitiga dari kelas segitiga:"<<std::endl;

            return (lebar * tinggi / 2);
        }
};

int main(){
    // membuat objek
    Bentuk *bentuk;
    Persegi persegi(10, 4);
    Segitiga segitiga(12, 6);

    // menyimpan address dari persegi
    bentuk = &persegi;

    // memanggil persegi
    bentuk->area();

    // menyimpan address dari segitiga
    bentuk = &segitiga;

    //memanggil segitiga
    bentuk->area();

    return 0;
}