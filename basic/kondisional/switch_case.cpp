//Contoh penggunaan switch case
// Switch-case merupakan alternatif dari if-else, biasa digunakan pada kodisi yang sederhana
// Pada switch-case setiap kali melakukan pengecekan harus diakhiri dengan "break"
// Jika tidak menambahkan break pada akhir pengecekan, program tidak akan berhenti dan akan selalu melakukan pengecekan

#include <iostream>

int main() {
  int a = 7;

  // memindahkan kondisi ke variabel a
  switch (a) {
    // Saat a = 1 jalankan program di bawah ini
    case 1: 
      std::cout << "Saat case = 1!\n";
      break;

    // Saat a = 1 jalankan program di bawah ini
    case 2:
      std::cout << "Saat case = 2!\n";
      break;

    // Jalankan program dibawah ini saat semua kondisi di atas tidak terpenuhi
    default:
      std::cout << "Nilai default pada case!\n";
  }

  return 0;
}
