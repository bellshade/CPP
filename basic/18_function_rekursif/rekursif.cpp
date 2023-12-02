#include <iostream>

// Fungsi untuk menghitung pangkat a^b secara rekursif
int pangkat(int a, int b)
{
    // Jika b lebih kecil atau sama dengan 1
    if (b <= 1)
    {
        // Kembalikan nilai a saja karena a pangkat 1 itu sama saja dengan a
        return a;
    }
    // Selain dari itu
    else
    {
        // a * fungsi pangkat (fungsi dirinya sendiri) dengan b dikurangi 1
        return a * pangkat(a, (b - 1));
    }
}

int main()
{
    // Inisialisasi nilai a dan b
    int a = 5, b = 2;
    int hasil;

    // Memanggil fungsi pangkat untuk menghitung a pangkat b
    hasil = pangkat(a, b);

    // Menampilkan hasil pangkat
    std::cout << "Hasil a dipangkat b : " << hasil << std::endl;

    return 0;
}