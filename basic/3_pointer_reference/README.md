# CPP Pointer
Address dan Pointer adalah fitur ekslusif bahasa pemrograman C dan C++, address dan pointer ini memiliki tiga fungsi utama yaitu, melokasikan objek baru, _melemparkan/mengoper_ fungsi ke fungsi yang lainnya, dan melakukan perulangan atau _loop_ elemen yang terdapat dalam array atau data struktur lain.

**References:** 
- [Apa itu pointer?](https://docs.microsoft.com/en-us/cpp/cpp/pointers-cpp?view=msvc-160)
- [Mengapa menggunakan Pointer?](https://www.geeksforgeeks.org/features-and-use-of-pointers-in-c-c/)

## Address
**Apa itu address?**
Dalam bahasa inggris Address berarti alamat atau lokasi dan kali ini kita akan mengambil lokasi dari sebuah variable dalam C++,  setiap variable pasti memiliki sebuah address dimana address itu adalah letak variable tersebut di dalam memori.


**Cara menampilkan address**
```cpp
std::string benda = "kursi"; // "kursi"
std::cout << &benda; // output: 0x7ffe137a25f0 (value ini merupakan address untuk variable benda)
```
Operator `&` merupakan _kunci_ yang akan mengembalikan address dari sebuah variable, _perlu diingat_ bahwa address ini akan terus berganti.

**Reference:** [Tentang address](https://mathbits.com/MathBits/CompSci/Pointers/Addresses.htm#:~:text=The%20location%20of%20an%20object,of%20an%20object%20in%20memory.)

## Pointer
**Apa itu pointer dalam C++?**
Pointer merupakan variable khusus untuk menyimpan address sebagai value-nya.

**Cara mendeklarasikan Pointer**
```cpp
std::string benda = "kursi";
std::string* ptr = &benda; // ptr = 0x7ffe137a25f0
std::cout << ptr; // 0x7ffe137a25f0
```
Untuk pointer, Operator `*` merupakan _kunci_ untuk mendeklarasikan sebuah variable bertipe pointer. Sama seperti variable yang lainnya, nama variable dari pointer ini tidak boleh sama.

**Null Pointer**
```cpp
std::string* ptr = nullptr; // ptr = 0x0
```
Null pointer merupakan metode untuk mengosongkan address dari sebuah variable pointer atau tidak beralamat.

**Mengambil value melalui pointer (dereferencing)**
```cpp
std::string benda = "kursi";
std::string* ptr = &benda; // ptr = 0x7ffe137a25f0
std::cout << *ptr; // "kursi"
```
Untuk mengambil value dengan address, kita harus mendeklarasikan operator `*` sebelum memanggil pointer.

**Pointer to Pointer**
```cpp
std::string benda;
std::string* ptr;
sdt::string** pptr;

benda = "kursi"

ptr = &benda; // ptr menyimpan address benda

pptr = &ptr; // pptr menyimpan address yang sama dengan ptr

std::cout << "Value yang terdapat dalam benda :" << benda << std::endl;
std::cout << "Value yang terdapat dalam *ptr :" << *ptr << std::endl;
std::cout << "Value yang terdapat dalam **ptr :" << **ptr << std::endl;
```
```
Output:
Value yang terdapat dalam benda :kursi
Value yang terdapat dalam *ptr :kursi
Value yang terdapat dalam **ptr :kursi
```
Metode Pointer to Pointer ini mengharuskan kita untuk menambah `*` lagi seperti `**ptr`, Pointer to Pointer merupakan metode untuk mengakses address dari sebuah pointer sehingga membentuk seperti sebuah rantai pointer.

**References:**
- [Pointers](https://www.w3schools.com/cpp/cpp_pointers.asp)
- [Null Pointer](https://www.tutorialspoint.com/cplusplus/cpp_null_pointers.htm)
- [Dereference](https://www.w3schools.com/cpp/cpp_pointers_dereference.asp)
- [Pointer to Pointer](https://www.tutorialspoint.com/cplusplus/cpp_pointer_to_pointer.htm)
- [Macam-macam Pointer](https://www.tutorialspoint.com/cplusplus/cpp_pointers.htm)

## Contoh penggunaan: Mengganti nilai variable
```cpp
#include <iostream>
int main(){
    // deklarasikan angka yang akan di akses oleh pointer dan variable dari angka yang akan diganti
    int num = 20;
    int val;

    // deklarasikan pointer dan simpan address num kedalamnya
    int* ptr;
    ptr = &num;

    // ganti nilai val dengan nilai num menggunakan ptr
    val = *ptr;
    std::cout << "Nilai dari val adalah :" << val; // Output: Nilai dari val adalah 20
}
```
