#include <iostream> // I/O
#include <fstream>

/*
Header <fstream>
- ifstream // untuk membaca (In fstream)
- ofstream // untuk menulis (Out fstream)
- fstream // gabungan dari ifstream & ofstream

Parameter <fstream>
- out
- in 
- binary
- trunc
*/

int main()
{
    /*
    Disini saya akan mendemonstrasikan cara penggunaan fstream untuk pemula
    Materi: 
        1. Cara menulis ke file.txt
        2. Membaca file.txt
    */

    // 2a. Mambaca file.txt dasar
    /*
        std::ifstream baca;
        baca.open("file.txt"); 
        std::string buffer; 
        baca >> buffer;
        std::cout << buffer;
        baca.close();
    */

    // 2b. Membaca file.txt dengan getline 
    /*
        std::ifstream baca;
        baca.open("file.txt"); 
        std::string buffer; 
        getline(baca,buffer);
        std::cout << buffer;
        baca.close();
    */

    // 2c. Membaca file.txt dengan looping
    std::ifstream baca;

    std::string buffer;

    baca.open("file.txt");

    while(!baca.eof()){ 
        /*
            dapat di artikan, bahwa: jika "baca" belum menyentuh akhir dari file
            maka akan terus terjadi looping/perulangan, sehingga semua kalimat yang
            ada aakan terbaca dan siap untuk di tampilakan ke console.
        */
        getline(baca,buffer);
        std::cout << buffer << "\n";
    }

    baca.close();

    /*
        (?) Apa sudah tidak ada lagi?
            Ada lagi pastinya, kamu juga bisa menggunakan cara yang lebih efisien
        (?) Caranya?
            Menggunakan fungsi lain, seperti "class", "struct" dsb.
        (?) Bagaimana bentuknya, jika kita ambil referensi dari kode ini?
            Yang pasti bentuknya fungsinya seperti di "Membaca-file-eksternal4"

    */

    return 0;
}
