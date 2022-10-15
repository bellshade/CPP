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

    Seperti yang kita lihat, pada file.txt sudah terdapat kalimat yang sudah kita input sebelumnya,
    dan saya tambahkan 2 kalimat lagi sehingga, sekarang menjadi 3 kalimat.
    sekarang kita akan mencoba membaca kalimat tersebut dan menampilkannya di terminal yang kita punya.
    */

    // 2a. Mambaca file.txt dasar
    std::ifstream baca; // di deklarasikan nama variable "baca" sebagai ifstream

    baca.open("file.txt"); // "baca" di perintahkan untuk *membuka* file bernama "file.txt"

    std::string buffer; 
    /*
        buffer dapat di artikan sebagai penyangga.
        kalimat yang kita ambil dari "file.txt" 
        akan di salurkan ke penyangga/buffer sebagai penerima kalimatnya.
    */

    baca >> buffer; // proses transfer kalimat ke buffer

    std::cout << buffer; // mengeluarkan hasilnya ke cout (console out)

    baca.close(); // pastikan setelah membuka, selalu ada penutup

    /*
        (?) Pertanyaanya, kenapa hanya muncul "Hai" padahal kalimatnya: "Hai yang pertama kalinya"?
            tentu saja, ini dikarenakan kita hanya mengambil sekali dan di hentikan saat bertemu "spasi"
        (?) lalu bagaimana, jika saya ingin mengambil kata kata selanjutnya?
            sebenarnya bisa saja seperti ini:
                std::ifstream baca;
                baca.open("file.txt"); 
                std::string buffer; 
                baca >> buffer;
                std::cout << buffer << " ";
                baca >> buffer;
                std::cout << buffer << " ";
                baca >> buffer;
                std::cout << buffer << " ";
                baca.close();
            Tapi, cara ini sangat tidak efisien, terlebih lagi setelah kali cermati
        (?) Apa ada alternatif lainnya?
            tentu saja ada, kalian bisa cek ke file "Membaca-file-eksternal2".
    */
    
    return 0;
}
