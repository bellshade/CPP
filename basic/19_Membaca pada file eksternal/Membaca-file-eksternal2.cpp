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

    // 2b. Membaca file.txt dengan getline (getline dapat digunakaan dengan menggunakan header <string>)
    std::ifstream baca;

    baca.open("file.txt"); 

    std::string buffer; 

    /*
        Ini yang akan kita rubah
            baca >> buffer;
        menjadi:
    */
    getline(baca,buffer); // ini sama saja seperti "baca >> buffer" (transfer)

    std::cout << buffer;

    baca.close();

    /*
        Dan, selesai.
        Kita berhasil mengeluarkan semua kata dalam 1 kalimat ke console, selamat!
        (?) Apa ini efisien untuk kedepannya, jika kita memiliki banyak kalimat dalam file.txt?
            Tidak
        (?) Kenapa?
            Dikarenakan ini hanya untuk membaca 1 baris saja,
            setelah ada "enter" pada akhir kalimat, maka hanya itu saja yang dapat terbaca
            selebihnya untuk baris 1,2,3 dan seterusnya tidak terbaca.
        (?) Solusinya bagaimana?
            Kalian bisa cek selebihnya di "Membaca-file-eksternal3"
    */
    
    return 0;
}
