#include <iostream>
using namespace std;

//Contoh perulangan menggunakan IF
int if_only() {
  // Deklarasi variabel
  int a = 1;

  // Hanya jalankan program di bawah ini saat nilai a = 1
  if (a == 1) {
    cout << "Contoh percabangan IF, Bellshade!\n";
  }

  return 0;
}

// Contoh penggunaan if-else
int if_else() {
  // Deklarasi Variabel a dengan nilai 7 (integer)
  int a = 7;
  
  if (a == 7) { // Jika a = 7 jalankan program di bawah ini
    cout << "Kondisi if terpenuhi, Bellshade!\n";
    // Jika nilai a tidak sama dengan kondisi di atas (!=) jalankan program di bawah ini
  } else {
    cout << "kondisi if tidak terpenuhi, Bellshade\n";
  }

  return 0;
}

// Contoh percabangan dengan if-else-if
int if_else_if() {
  // Deklarasi variabel
  int a = 4;

  // Else if akan menjadi alternatif jika kondisi pada if sebelumnya tidak terpenuhi
  // Akan menjalankan program dibawahnya
  if (a == 1) { // Jika a = 1 jalankan program di bawah ini
    cout << "Nilai a = 1!\n";
  } else if (a == 2) { // Jika a = 2 jalankan program di bawah ini
    cout << "Nilai a = 2!\n";
  } else if (a == 3) { // Jika a = 3 jalankan program di bawah ini
    cout << "Nilai a = 3!\n"; 
  } else {
    // Baris di bawah ini akan dijalankan apabila semua kondisi di atas tidak terpenuhi
    cout << "Nilai a bukan 1, 2 ataupun 3!\n";
  }

  return 0;
}

// Contoh penggunaan switch case
// Switch-case merupakan alternatif dari if-else, biasa digunakan pada kodisi yang sederhana
// Pada switch-case setiap kali melakukan pengecekan harus diakhiri dengan "break"
// Jika tidak menambahkan break pada akhir pengecekan, program tidak akan berhenti dan akan selalu melakukan pengecekan
int switch_case() {
  int a = 7;

  // Memindahkan kondisi ke variabel a
  switch (a) {
    // Saat a = 1 jalankan program di bawah ini
    case 1: 
      cout << "Saat case = 1!\n";
      break;

    // Saat a = 1 jalankan program di bawah ini
    case 2:
      cout << "Saat case = 2!\n";
      break;

    // Jalankan program dibawah ini saat semua kondisi di atas tidak terpenuhi
    default:
      cout << "Nilai default pada case!\n";
  }

  return 0;
}

int main()
{
  // Menjalankan fungsi di atas
  if_only();
  if_else();
  if_else_if();
  switch_case();
}