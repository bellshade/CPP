# Function Overload
***Function Overloading adalah membuat beberapa function dengan nama yang sama, tapi dibedakan dari jumlah dan tipe data parameter.
Walaupun Umumnya, kita tidak bisa membuat function dengan nama yang sama.***

Mirip seperti penamaan variabel, compiler C++ akan error jika menemukan terdapat 2 atau lebih function dengan nama yang sama.
Akan tetapi jika jumlah argument atau tipe data argument berbeda, maka akan dianggap sebagai fungsi yang berbeda pula.

**Contoh Kode** berikut merujuk pada kalimat:
- *Umumnya, kita tidak bisa membuat function dengan nama yang sama* 
- *Akan tetapi jika jumlah argument atau tipe data argument berbeda, maka akan dianggap sebagai fungsi yang berbeda pula.*

Berikut adalah demonstrasinya

```cpp
#include <iostream>
 
// Fungsi pertama
int dikali(int var1) {
    std::cout << var1 << " x " << var1 << " : ";
    return var1 * var1;
}
 
// Fungsi kedua
int dikali(int var1, int var2) {
    std::cout << var1 << " x " << var2 << " : ";
    return var1 * var2;
}

 
int main(int argc, char const *argv[])
{
    std::cout << dikali(2) << std::endl;
    std::cout << dikali(5, 5) << std::endl;
 
    return 0;
}
```
Kedua nama fungsi sama `dikali` dengan `dikali` namun berbeda `parameter`.

- fungsi `dikali` yang pertama memiliki `1 parameter`
- fungsi `dikali` yang kedua   memiliki `2 parameter`

> Pada function kita dimungkinkan untuk mendirikan function lebih dari satu dengan identitas yang sama, selama masing-masing function tersebut memiliki perbedaan pada function parameter. Hal tersebut disebut sebagai fitur Overloading.

> Pembuatan function overloading wajib untuk membuat function tersebut benar-benar berbeda dalam segi function parameter. Jika diidentifikasi memiliki kesamaan, maka kompilator akan mengeluh mengenai “ambiguating”.

> Kadang kompilator juga akan mengeluh saat dimana memang tidak ditemukan kecocokan function dengan argument pada pemanggilan function.

### Keuntungannya apa?
Function yang memiliki fitur overloading, memberikan kemudahan dengan kemungkinkan untuk memberikan argument secara fleksibel sesuai keadaan dan kebutuhkan.

**Contohnya** 
_Function_
```cpp
// Fungsi pertama
int dikali(int var1) {
    std::cout << var1 << " x " << var1 << " : ";
    return var1 * var1;
}
 
// Fungsi kedua
int dikali(int var1, int var2) {
    std::cout << var1 << " x " << var2 << " : ";
    return var1 * var2;
}

// Fungsi ketiga
int dikali(int var1, int var2, int var3) {
    std::cout << var1 << " x " << var2 << " x " << var3 << " : ";
    return var1 * var2 * var3;
}
```
_inputUser_
```cpp
std::cout << dikali(1,2,3) << std::endl;
std::cout << dikali(1,2) << std::endl;
std::cout << dikali(1) << std::endl;
```
Kita dapat dengan bebas menggunakan fungsi yang mana saja, mengikuti/menyesuaikan parameter dari setiap fungsinya.

1. Jika kita memiliki nilai (_inputUser_) = `1,2,3`. 
    - Maka saat kita memanggil fungsi `dikali`, secara otomatis memanggil fungsi yang ketiga (`dikali`)
    - `Hasil` 1 x 2 x 3 : 6
2. Jika kita memiliki nilai (_inputUser_) = `1,2`. 
    - Maka saat kita memanggil fungsi `dikali`, secara otomatis memanggil fungsi yang kedua (`dikali`)
    - `Hasil` 1 x 2 : 2
3. Jika kita memiliki nilai (_inputUser_) = `1`. 
    - Maka saat kita memanggil fungsi `dikali`, secara otomatis memanggil fungsi yang pertama (`dikali`)
    - `Hasil` 1 x 1 : 1
