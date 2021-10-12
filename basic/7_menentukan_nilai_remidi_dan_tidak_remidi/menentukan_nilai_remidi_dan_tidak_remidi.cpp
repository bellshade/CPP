#include <iostream>

// Using Namespace Std adalah sebuah intruksi terhadap compiler untuk menggunakan semua fungsi yang terkait untuk kerangka yang sama, bisa berupa berkas, class, dan sejenisnya yang berkaitan dengan std.
using namespace std;

int main() // Judul fungsi
{
    int i;
    // cout (character out) digunakan untuk mengarahkan data ke dalam standar output (cetak pada layar)
    // Fungsi cin (c input) adalah fungsi untuk mengambil input dari keyboard.
    cout<<"Program Menentukan Remidi Atau Tidak"<<endl; 
    cout<<"Inputkan Nilainya: ";
    cin>>i;

    // If adalah kondisi yang bernilai benar(true)
    // Else If merupakan percabangan yang mana jika kondisi tersebut bernilai benar(true) maka Else If akan menjalankan perintah tersebut
    if (i>=70&&i<=100) // jika i lebih dari sama dengan 70 DAN i kurang dari sama dengan 100
        cout<<"Anda Tidak Remidi"<<endl; // maka menampilkan output "Anda Tidak Remidi"
    else if (i<70) //jika nilai (i) kurang dari 70
        cout<<"Anda Remidi"<<endl; // maka menampilkan output "Anda Remidi"
    if (i>0&&i<50) // jika i lebih dari 0 DAN i kurang dari 50
            cout<<"Remidi Anda Mengerjakan 10 soal"<<endl; // maka menampilkan output "Remidi Anda Mengerjakan 10 soal"
    else if (i>50&&i<70) // jika nilai (i) lebih dari 50 DAN i kurang dari 70
        cout<<"Remidi Anda Mengerjakan 5 soal"<<endl; // maka menampilkan "Remidi Anda Mengerjakan 5 soal"

    //  sendiri memiliki arti untuk komputer kita. Setelah program kita selesai di kompilasi, dan saat CPU memulai mengeksekusi program kita, CPU akan selalu memulai pada function utama dan berakhir pada function utama, yaitu int main();
    return 0;
}
