/*
Hai teman-teman! Mari kita belajar tentang cara kerja operator bitwise dengan contoh sederhana!

Sebelumnya, mari kita pahami dulu tipe data char. Char (character) adalah tipe data yang digunakan untuk menyimpan satu karakter seperti huruf, angka, atau simbol.
Setiap karakter char sebenarnya disimpan dalam bentuk biner 8-bit berdasarkan kode ASCII.
*/
#include <iostream>

int main(){
    char a = 'F';
    char b = 'C';
    char c = a & b;
    std::cout << c << std::endl;
}

/*
Program di atas akan menghasilkan output: B

Kenapa bisa begitu? Yuk kita pahami bersama-sama!

Di sini kita membandingkan 2 variabel bertipe char:
- Variabel a berisi huruf 'F'
- Variabel b berisi huruf 'C'

Dalam tabel ASCII, setiap karakter memiliki nilai biner masing-masing:
'F' = 01000110
'C' = 01000011

Kemudian kita menggunakan operator bitwise AND ('&'). Operator ini akan membandingkan setiap digit biner dari kedua karakter tersebut.
Jika kedua digit sama-sama bernilai 1, hasilnya 1. Jika tidak, hasilnya 0.

Mari kita bandingkan:
01000110 (F)
01000011 (C)
-------- AND
01000010

Nah, hasil operasi bitwise AND tersebut adalah 01000010, yang dalam tabel ASCII merupakan representasi dari huruf 'B'!

Bagaimana? Menarik kan cara kerjanya? 😊

kalau penasaran, teman-teman bisa ber-eksperiment dengan melihat tabel ASCII ini sebagai referensi >> https://www.ascii-code.com/
*/
