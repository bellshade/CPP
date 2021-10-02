// Contoh pengkondisian menggunakan ternaty
// Alternatif dari penggunaan if-else dengan menuliskan program hanya 1 baris saja
// digunakan pada perhitungan/logika sederhana

// logika dituliskan sebelum simbol "?"
// simbol ":" digunakan sebagai else.
// value sebelum ":" untuk hasil "True", value setelah ":" untuk hasil "False"

#include <iostream>

using namespace std;
int main() {
  int a = 5;
  int b = 10;

  // Contok penggunaan ternary untuk menentukan nilai c
  // cek apakah "a > b" (hasilnya false)
  //  jika hasilnya "True" nilai c = a.
  //  Jika hasilnya "False" nilai c = b.
  int c = a > b ? a : b;

  // Tampilkan Hasilnya
  cout << "Nilai dari variabel c adalah: " << c << '\n';

  return 0;
}
