# cpp address & pointer
Address dan Pointer ini ekslusif untuk bahasa pemrograman C dan C++, address dan pointer ini memiliki tiga fungsi utama yaitu, untuk melokasikan object baru, untuk _melemparkan_ atau _mengoper_ function ke function yang lainnya, dan untuk mengulangi atau _loop_ elemen yang terdapat dalam array atau data struktur lain.

## Mengapa memakai pointer?
- Mengurangi penggunaan memori 

## Address
**Apa itu address?**
Dalam bahasa inggris Address berarti alamat atau lokasi dan kali ini kita akan mengambil lokasi dari sebuah variable dalam C++,  setiap variable pasti memiliki sebuah address dimana address itu adalah letak variable tersebut di dalam memori.

**Cara menampilkan address**
```cpp
std::string benda = "kursi"; // "kursi"
std::cout << &benda; // output: 0x7ffe137a25f0 (value ini merupakan address untuk variable benda)
```
Operator "&" merupakan _kunci_ yang akan mengembalikan address dari sebuah variable, _perlu diingat_ bahwa address ini akan terus berganti

## Pointer
**Apa itu pointer dalam C++?**
Pointer merupakan variable khusus untuk menyimpan address sebagai value-nya.

**Cara mendeklarasikan Pointer**
```cpp
std::string benda = "kursi";
std::string* ptr = &benda; // ptr = 0x7ffe137a25f0
std::cout << ptr; // 0x7ffe137a25f0
```
Untuk pointer, Operator "*" merupakan _kunci_ untuk menangkap address tersebut, sama seperti variable yang lainnya, nama variable dari pointer ini tidak boleh sama

**Null Pointer**
```cpp
std::string* ptr = nullptr; // ptr = 0x0
```
null pointer merupakan method untuk mengosongkan address dari pointer atau tidak beralamat

**Mengambil value melalui pointer (dereferencing)**
```cpp
std::string benda = "kursi";
std::string* ptr = &benda; // ptr = 0x7ffe137a25f0
std::cout << *ptr; // "kursi"
```
Untuk mengambil value dengan address ini, kita harus mendeklarasikan operator "*" sebelum memanggil pointer.

## Contoh penggunaan: Mengkuadratkan angka
```cpp
#include <iostream>

int kuadratkan(int* ptr){
    /* 
    variable ptr kini menggunakan address dan value dari variable angka, bisa di cek menggunakan:
    std::cout << ptr;

    maka dengan ini kita telah mengurangi penggunaan memori pada program
    */ 

    return (*ptr) * (*ptr); // 3 * 3
}

int main(){
    int angka = 3;
    std::cout << kuadratkan(&angka); // mengirim alamat angka ke pointer ptr dan menampilkan hasil kuadrat
}
```