#include <iostream> // I/O
#include <fstream>

/*
Header <fstream>
- ifstream // untuk membaca
- ofstream // untuk menulis
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

    Pertama-tama pastikan kalian telah menyiapkan file bernama "file.txt" terlebih dahulu
    */

    // 1a. Menulis ke file.txt
    std::ofstream tulis; // di deklarasikan nama variable "tulis" sebagai ofstream
    
    tulis.open("file.txt"); // tulis di perintahkan untuk *membuka* file bernama "file.txt"
    
    tulis << "Hai"; // Katakan/masukan apapun ke dalam tulis yang sudah terhubung ke file.txt
    
    tulis.close(); // jika ada pembuka maka akan ada penutup

    return 0;
}
