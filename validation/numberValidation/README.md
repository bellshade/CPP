# Number input validation
File ini berisi penjelasan mengenai fungsi untuk menginput **Hanya nomor saja**, jika input selain nomor maka akan mendapatkan error atau masuk ke fungsi lain, berikut penjelasannya :

Tentu saja pertama yang akan kita lakukan adalah meminta user untuk menginput
```cpp
std::cout << "Masukkan angka : ";  // "Masukkan angka : "
```

Kemudian disini fungsi utama yang akan jalan
```cpp
if(!(std::cin >> num)){
  // (Jika input tidak sama dengan(not) tipe data dari variable num maka...)
}
```
Kita bisa mengganti `if` menjadi `while` jika ingin inputnya berulang hingga yang di input adalah angka

Lalu jelaskan kesalahan
```cpp
std::cout << "Yang anda masukkan bukan angka";  // "Yang anda masukkan bukan angka"
```

Bersihkan error-error yang ada dalam `cin`-nya agar operasi berikutnya bekerja dengan baik
```cpp
std::cin.clear(); // membersihkan cin
```

Skip atau abaikan hal lain yang ada dalam baris(line) yang sama dengan _non-number_ hasil input sebelumnya agar tidak terjadi kegagalan lagi
```cpp
std::cin.ignore(1000, '\n');
// skip sebanyak 1000 huruf/character agar code-nya menganggap kalau user tidak akan menginput lebih panjang dalam baris yang valid
```

## Contoh penggunaan: untuk memilih opsi

```cpp
#include <iostream>

int main(){
  int num;
  
  std::cout << "Masukkan angka : ";
  while(!(std::cin >> num)){ // selama yang di input bukan angka, jalankan :
    std::cout << "Mohon masukkan angka : ";
    std::cin.clear();
    std::cin.ignore(123, '\n');
  }
  
  switch(num){
    case 1: // jika angka variable num adalah 1 maka :
      std::cout << "Opsi pertama";
      break;
      
    case 2: // jika angka variable num adalah 2 maka :
      std::cout << "Opsi kedua";
      break;
      
    case 3: // jika angka variable num adalah 3 maka :
      std::cout << "Opsi ketiga";
      break;
  }
}
```
