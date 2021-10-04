// Contoh penggunan variabel dengan tipe data integer dan float
#include <iostream>

using namespace std;
int main() {
  // Metode 1
  // Melakukan deklarasi variabel dengan menetapkan nilainya pada baris terpisah
  // Deklasari tipe data integer pada variabel (a, b dan c)
  int a;
  int b;
  int c;

  // Inisialisai nilai untuk setiap variabel
  a = 2;
  b = 3;
  c = a + b; 

  // Menampilkan hasil penjumlahan a + b
  cout << a << " + " << b << " = " << c << '\n';

  // Metode 2
  // Melakukan deklarasi variabel dengan menetapkan nilainya pada baris yang sama
  // Deklarasi variabel (d, e dan f) dan menetapkan nilainya dengan tipe data float (bilangan pecahan)
  float d = 2.5f;
  float e = 3.14f;
  float f = d + e;

  // Menampilkan hasil penjumlahan d + e
  cout << d << " + " << e << " = " << f << '\n';

  // Metode 3
  // Melakukan deklarasi beberapa variabel dalam 2 baris
  // Deklarasi tipe data integer pada variabel (x, y, dan z)
  int x, y, z;

  // Inisialisai nilai untuk setiap variabel
  x = 5;
  y = 3;
  z = x * y;

  // Menampilkan hasil perkalian x * z
  cout << x << " * " << y << " = " << z<< '\n';

  return 0;
}