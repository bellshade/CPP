# CPP Array
Array digunakan untuk menyimpan dan menghasilkan beberapa atau banyak value dalam satu variabel, untuk mendeklarasikan array, deklarasikan berupa tipe data dari array, nama variabel dari array, dan jumlah value yang diinginkan yang dimasukkan di dalam tutup kurung kotak ``[]``, contoh kode:

```cpp
std::string nama_siswa[5];
```
contoh deklarasi value dari array
```cpp
std::string nama_siswa[3] = {"erik", "mark", "spencer"};
```
kita bisa mengakses element pada array seperti pada contoh dibawah ini
```cpp
std::string nama_siswa[3] = {"erik", "mark", "spencer"};
std::cout << nama_siswa[0];
```
pada penjelasan diatas kita mengakses element pertama dari siswa yaitu ``erik``, array dimulai dari index 0 dan kemudian berlanjut ``0 1 2...n``

kita juga bisa mengubah value dari element tersebut dengan cara memilih element yang ingin kita ubah dan menggantinya dengan yang sesuai
```cpp
std::string nama_siswa[3] = {"erik", "mark", "spencer"};
nama_siswa[1] = "james";
std::cout << nama_siswa[1];
```
contoh pada value integer
```cpp
int nilai_siswa[3] = {90, 50, 70};
std::cout << nilai_siswa[2];
```

## Memanggil Array
Kita bisa memanggil semua value dari array dengan cara menggunakan looping sebagai contoh
```cpp
std::string nama_siswa[3] = {"erik", "mark", "spencer"};
for (int i = 0; i < 3; i++){
    std::cout << nama_siswa[i] << std::endl;
}
```
pada penjelasan diatas, perulangan diulang sebanyak 3 kali dimana sesuai dengan jumlah element dari array, kemudian menampilkan output dari nama siswa pada perulangan tersebut sehingga mengeluarkan output
```
erik
mark
spencer
```

contoh lain
```cpp
std::string nama_siswa[3] = {"erik", "mark", "spencer"};
for (int i = 0; i < 3; i++){
    std::cout << i[nama_siswa] << std::endl;
}
```

## Reference
- [Arrays in CPP](https://www.w3schools.com/cpp/cpp_arrays.asp)

contoh lebih lanjut dari array

- [pendahuluan array](https://www.youtube.com/watch?v=8WhUADLI4RQ&list=PLZS-MHyEIRo4Ze0bbGB1WKBSNMPzi-eWI&index=47)
- [array || standard library](https://www.youtube.com/watch?v=o1DegduG140&list=PLZS-MHyEIRo4Ze0bbGB1WKBSNMPzi-eWI&index=48)
- [latihan array](https://www.youtube.com/watch?v=PGV8VigBVcg&list=PLZS-MHyEIRo4Ze0bbGB1WKBSNMPzi-eWI&index=49)
- [looping array](https://www.youtube.com/watch?v=5jTGrD55Ws4&list=PLZS-MHyEIRo4Ze0bbGB1WKBSNMPzi-eWI&index=50)
- [multidimensional array](https://www.youtube.com/watch?v=-hsKUD4fVRE&list=PLZS-MHyEIRo4Ze0bbGB1WKBSNMPzi-eWI&index=51)
- [sort array | std library](https://www.youtube.com/watch?v=G0cml-wvaBc&list=PLZS-MHyEIRo4Ze0bbGB1WKBSNMPzi-eWI&index=53)
- [search array | std library](https://www.youtube.com/watch?v=QFC4DXvRu8o&list=PLZS-MHyEIRo4Ze0bbGB1WKBSNMPzi-eWI&index=54)
