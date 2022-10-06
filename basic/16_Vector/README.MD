# Vector
**Pengenalan** Vector adalah suatu class template yang merupakan bagian dari STL (Standard Template Library) dan dapat digunakan untuk menggantikan array. Sama dengan array, vector juga menyimpan elemen-elemen secara bersebelahan dan elemen tesebut dapat diakses sesuai subscript/index.

mari kita sama-sama mempelajari cara menggunakan:
```cpp
#include <vector>
```

## Keuntungan dari Vektor
- Ukuran vektor dapat diubah
- Beberapa objek dapat disimpan
- Elemen dapat dihapus dari vektor

## Kekurangan Vektor
- Vektor adalah objek, konsumsi memori lebih banyak.

## Terdapat Member Function Vector, seperti:
1. Iterators
2. Capacity
3. Element Acces
4. Modifier
5. Alocator

Macam-macam pendeklarasian Vector:
1. `vector <tipe_data> nama_variabel [jumlah_elemen];` jumlah elemen bersifat opsional atau 
2. `vector <tipe_data> nama_variabel;`
3. `vector <tipe_data> nama_variabel {element};`

kalau begitu dimulai dari pengenalan kode

### Header
```cpp
#include <iostream> 
#include <vector>
```
kita masukan header vector disana dan kita akan menggunakan beberapa syntax dari header vector ini nantinya

### Function
```cpp
void loop(std::vector <int> parameter){
    std::cout << "\nData Vector berisikan: ";
    for(int i = 0; i < parameter.size(); i++){
        std::cout << "[" << parameter[i] << "] ";
    }
}
```
Fungsi ini akan kita pakai untuk melooping nilai-nilai yang ada pada vector dari nilai awal hingga akhir

### Main
```cpp
int main(int argc, char const *argv[])
{
    // Deklarasi Vector
    std::vector <int> v;

    // 1. push_back
    // Menginisialisasikan Vector dengan angka = 1, 2, 3
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    loop(v);

    // 2. pop_back
    v.pop_back();
    loop(v);

    // 3. at
    v.at(1) = 3;
    loop(v);

    // 4. clear
    v.clear();
    loop(v);
    
    return 0;
}
```
nah disini saya menggunakan beberapa syntax dari header vector, terdapat [4] yaitu: 
- `push_back`, 
- `pop_back`, 
- `clear`, 
- `at`

dan saya akan menjelaskan kegunaan-kegunaannya sebelum nanti saya akan gunakan syntax lainnya

**1. push_back**

Singkatnya ini berguna untuk menambahkan nilai / data, pada vector yang sudah kita deklarasikan.
sebagai contoh disini saya, menambahkan nilai: 1, 2 & 3
```cpp
v.push_back(1);
v.push_back(2);
v.push_back(3);

loop(v); // memanggil fungsi loop
```
lalu saya memanggil fungsi loop untuk mencetak nilai-nilai yang sudah ada pada vector

output:
> Data Vector berisikan: [1] [2] [3]

**Perhatikan:**
bahwa nilai index vector mulai dari 0, maka penjabaran nilai vector saat ini adalah

```
nilai index : [0] [1] [2]
nilai vector: [1] [2] [3]
```

**2. pop_back**

Singkatnya ini berguna untuk menghapus nilai akhir, pada vector yang sudah kita deklarasikan.
sesuai nama syntax nya `pop_back` yang menghapus nilai dari belakang (nilai akhir vector), 
juga ada `pop_front` dimana ini kebalikannya dari `pop_back`
sebagai contoh disini saya, menghapus nilai paling akhir: 3
```cpp
v.pop_back();
loop(v);
```
lalu saya memanggil fungsi loop untuk mencetak nilai-nilai yang sudah ada pada vector

output:
> Data Vector berisikan: [1] [2] 

**3. at**

Singkatnya ini berguna untuk mencari nilai, pada vector yang sudah kita deklarasikan.
sebagai contoh disini saya, mencari nilai pada index 1
```cpp
std::cout << "\nNilai pencarian: [" << v.at(1) << "]";
```

output:
> Nilai pencarian: [2]

kenapa munculnya nilai 2?

```
nilai index : [0] [1] [2]
nilai vector: [1] [2] [3]
```

jawabannya adalah karena index ke-1 memiliki nilai 2.

disini kita dapat juga mengimplementasikan merubah nilai, pada vector yang sudah kita deklarasikan.
sebagai contoh disini saya, mencari nilai pada index 1 dan merubahnya menjadi nilai 3
```cpp
v.at(1) = 3;
loop(v);
```

lalu saya memanggil fungsi loop untuk mencetak nilai-nilai yang sudah ada pada vector

output:
> Data Vector berisikan: [1] [3] 

**4. clear**

Singkatnya ini berguna untuk menghapus / reset semua nilai yang pada vector yang sudah kita deklarasikan.
```cpp
v.clear();
loop(v);
```

output:
> Data Vector berisikan:
