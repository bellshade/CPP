//Contoh percabangan dengan if-else-if

#include <iostream>

using namespace std;
int main() {
  //Deklarasi variabel
  int a = 4;

  //else akan menjadi alternatif jika kondisi pada if sebelumnya tidak terpenuhi
  //akan menjalankan program dibawahnya
  if (a == 1) { //Jika a = 1 jalankan program di bawah ini
    cout << "Nilai a = 1!\n";
  } else if (a == 2) { //Jika a = 2 jalankan program di bawah ini
    cout << "Nilai a = 2!\n";
  } else if (a == 3) { //Jika a = 3 jalankan program di bawah ini
    cout << "Nilai a = 3!\n"; 
  } else {
    //baris di bawah ini akan dijalankan apabila semua kondisi di atas tidak terpenuhi
    cout << "Nilai a bukan 1, 2 ataupun 3!\n";
  }

  return 0;
}
