#include <iostream>

int main() {
    // menampilkan address dari sebuah string
    std::string benda = "meja";
    std::cout << &benda; // 0x7ffe137a25f0

    // menyimpan address kedalam pointer dan menampilkan
    std::string hewan = "kelinci";
    std::string* ptr = &hewan; // ptr = 0x7ffe137a25f0
    std::cout << ptr; // 0x7ffe137a25f0

    /* 
        Penempatan operator * bebas seperti:
        string* ptr;
        string * ptr;
        string *ptr;
    */

    // menampilkan value atau isi dari alamat yang di sudah dia ambil
    std::string hewan2 = "gajah";
    std::string* ptr2 = &hewan2; // ptr = 0x7ffe137a25f0
    std::cout << *ptr2; // "gajah"
    return 0;
}