#include<iostream>

// mendeklarasikan fungsi
int tambah(int angka1, int angka2);

int main(){
    int a = 20;
    int b = 30;
    int hasil;

    hasil  = tambah(a, b);
    std::cout << "hasilnya adalah :" << hasil;

    return 0;
}

// fungsi yang mengembalikan hasil dari operasi
// pertambahan antara angka1 dan angka2
int tambah(int angka1, int angka2){
    int hasil;
    hasil = angka1 + angka2;

    return hasil;
}
