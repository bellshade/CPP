# constant / literal

constant mengacu pada nilai tetap yang tidak dapat diubah oleh program dan disebut dengan literal. constant dapat berupa salah satu tipe data dasar dan dapat dibagi menjadi angka integer, angka floating atau float, char, string atau boolean.

sekali lagi, constant diperlakukan seperti variabel biasa kecualli bahaw nilainya tidak dapat diubah setelah definisinya.

## literal bilangan bulat

literal integer dapat berupa konstant desimal, oktal, atau heksadesimal. awalan menetukan basis atau radix: 0x atau 0X untuk hekasdesimal, 0 untuk oktal dan tidak ada untuk desimal.

literal integer juga dapat memiliki sufix ynag merupakan kombinasi dari U dan L. masing-masing untuk usigned dan long. akhiran dapat berupa huruf besar atau kecil dan dapat di dalam urutan apapun

berikut contoh dari literal integer
```
212     // legal
215u    // legal
0xFeeL  // legal
078     // illegal: angka 8 tidak termasuk dalam angka oktal
032UU   // illegal: karena tidak dapat mengulang suffix
```

contoh lain dari berbagai jenis literal integer
```
85      // desimal
0123    // oktal
0x4b    // heksadesimal
30      // int
30U     // unsigned int
30l     // long
30ul    // unsigned long
```


## literal floating point

literal float memiliki bagian bilangan bulat, titiak desimal, bagian pecahan, dan bagian eskponen. kita dapat mewakili float point baik dalam bentuk desimal atau bentuk eskponensial.

saat mewakili menggunakan bentuk desimal, kita harus menyertakan titik desimal, eksponen, atau keduanya dan saat meawkili menggunakan bentuk eksponensial, anda harus menyertakan bagian bilangan bulat, bagian pecahan atau keduanya. eksponen bertanda diperkenalkan oleh e atau E

```
3.14521     // legal
314251-5l   // legal
510E        // illegal: tidak eksponen
210f        // illegal: tidak desimal atau eksponen
.e55        // illegal: tidak ada angka integer sebelum koma
```

## literal boolean

ada dua literal boolean dan mereka adalah bagian dari keyword c++ standar

- nilai **true** mewakili true
- nilai **false** mewakili false

kita tidak bisa menganggap nilai true sama dengan 1 dan false sama dengan 0

## literasi karakter

Literal karakter diapit oleh tanda kutip tunggal. Jika literal dimulai dengan L (hanya huruf besar), itu adalah literal karakter lebar (misalnya, L'x') dan harus disimpan dalam jenis variabel wchar_t . Jika tidak, itu adalah literal karakter yang sempit (misalnya, 'x') dan dapat disimpan dalam variabel sederhana dari tipe karakter .

Karakter literal dapat berupa karakter biasa (misalnya, 'x'), urutan escape (misalnya, '\t'), atau karakter universal (misalnya, '\u02C0').

contoh penggunaan escape karakter

```cpp
#include <iostream>

int main(){
    std::cout<<"selamat\tdatang\n\n";
    return 0;
}
```
ketika kode diatas  dikompilasi dan dijalankan, menghasilkan berupa
```
selamat  datang
```

## string literal

Literal string diapit dalam tanda kutip ganda. Sebuah string berisi karakter yang mirip dengan karakter literal: karakter polos, escape sequence, dan karakter universal.

Anda dapat memecah garis panjang menjadi beberapa baris menggunakan literal string dan memisahkannya menggunakan spasi putih.

## mendifinisikan konstanta

ada dua cara sederhana dalam c++ untuk mendifinisikan konstanta
- menggunakan preprosesor #define
- menggunakan keyword const

## menggunakan define

berikut adalah form untuk menggunakan ``#define`` preposesor untuk mendifinsikan sebuah konstanta
```
#define indentifier value
```

contoh
```cpp
#include <iostream>

#define PANJANG 10
#define LEBAR 5
#define NEWLINE '\n'

int main(){
    int hasil;
    hasil = PANJANG * LEBAR;
    std::cout<<hasil;
    std::cout<<NEWLINE;

    return 0;
}
```

## menggunakan const

kita dapat menggunakan awalan const untuk mendeklarasikan konstanta dengan tipe tertentu sebagai berikut

```
const type variabel = value;
```

contoh
```cpp
#include <iostream>

int main(){
    const int PANJANG = 10;
    const int LEBAR = 5;
    const char NEWLINE = '\n';
    int hasil;

    hasil = PANJANG * LEBAR;
    std::cout<<hasil;
    std::cout<<NEWLINE;

    return 0; 
}
```
