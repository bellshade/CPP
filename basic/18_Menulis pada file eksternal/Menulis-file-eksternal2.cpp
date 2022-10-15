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

void tulis(std::string kata){
    std::ofstream tulis; 

    tulis.open("file.txt");

    tulis << kata;
    
    tulis.close();
}

int main()
{
    /*
    Disini saya akan mendemonstrasikan cara penggunaan fstream untuk pemula
    Materi: 
        1. Cara menulis ke file.txt
    */

    // 1a. Menulis ke file.txt dasar
    /*
        std::ofstream tulis; 
        tulis.open("file.txt");
        tulis << "Hai";
        tulis.close();
    */

    // 2b. Menulis ke file.txt menggunakan function
    tulis("Hai yang kedua kalinya"); 
    /*
        cara ini sama saja seperti yang dasar, 
        hanya saja lebih fleksibel penggunaannya
    */

    return 0;
}
