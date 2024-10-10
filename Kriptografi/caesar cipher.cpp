#include <iostream>
#include <string>
#include <stdlib.h>  
/*sumber ascii
http://sticksandstones.kstrom.com/appen.html
*/
/*
konsep caesar cipher
https://en.wikipedia.org/wiki/Caesar_cipher
*/
using namespace std;
string encrypt(string &kata, int &TargetEncrypt){
    string ResultEncrypt = ""; //isi variabel dengan string kosong yang dimana nanti akan di isi oleh engkripsi string kata
    for(int i = 0; i < kata.length(); i++){
        if(isupper(kata[i])){  //huruf besar
            ResultEncrypt += char((kata[i] - 65 + TargetEncrypt + 26) % 26 + 65); 
            // mengenkripsi huruf kapital dengan menggeser berdasarkan TargetEncrypt.
        } else { //huruf kecil
            ResultEncrypt += char((kata[i] - 97 + TargetEncrypt + 26) % 26 + 97);
            // mengenkripsi huruf kecil dengan menggeser berdasarkan TargetEncrypt.
        }
    }
    return ResultEncrypt;
    /*
Rumus (kata[i] - 65 + TargetEncrypt + 26) % 26 + 65 digunakan untuk menggeser huruf kapital dalam algoritma Caesar Cipher.
Ini mengkonversi kata[i] dari ASCII ke indeks 0–25, menambahkan TargetEncrypt, menjamin hasil positif dengan tambahan 26, 
dan akhirnya mengonversi kembali ke ASCII dengan % 26 dan ini juga berlaku untuk huruf kecil yg membedakan hanya code ascii
*/
}
string decrypt(string &kata, int &TargetDecrypt){
    string ResultDecrypt = "";
    for(int i = 0; i < kata.length(); i++){
        if(isupper(kata[i])){ //huruf kapital
            ResultDecrypt += char((kata[i] - 65 - TargetDecrypt + 26) % 26 + 65);
            // mendeskripsi huruf kapital dengan menggeser berdasarkan TargetDecrypt
        } else { //huruf kecil
            ResultDecrypt += char((kata[i] - 97 - TargetDecrypt + 26) % 26 + 97);
            // // mendeskripsi huruf kecil dengan menggeser berdasarkan TargetDecrypt
        }
    }
    return ResultDecrypt;
}
int main(){
    string kata;
    int TargetEncrypt, TargetDecrypt, pilihan;
    bool choice = true;
    while(choice){
        system("clear"); //untuk windows pakai system("cls")
        cout << "pilihan yang tersedia \n";
        cout << "1.encrypt \n";
        cout << "2.decrypt \n";
        cout << "Masukkan pilihan anda: ";
        cin >> pilihan;
        cin.ignore();
        while(pilihan < 1 || pilihan > 2){ //jika input pilihan < 1 dan > 2 maka while akan berjalan dan meminta input ulang
            cout << "anda memasukkan input yang salah ";
            cin >> pilihan;
            cin.ignore();
        }
        if(pilihan == 1){
            cout << "Masukkan kata: ";
            getline(cin,kata);
            cout << "Masukkan target: ";
            cin >> TargetEncrypt;
            string HasilEngkripsi = encrypt(kata,TargetEncrypt);
            cout << "hasil engripsi: " << HasilEngkripsi << endl;
        } else {
            cout << "Masukkan kata: ";
            getline(cin,kata);
            cout << "Masukkan target: ";
            cin >> TargetDecrypt;
            string HasilDecrypt = decrypt(kata,TargetDecrypt);
            cout << "Hasil decrypt : " << HasilDecrypt << endl;
        }
        cout << "Lanjutkan? (1 untuk ya, 0 untuk tidak): "; //meminta user untuk melanjutkan progam atau tidak
        cin >> choice;
        cin.ignore();
    }
    return 0;
}