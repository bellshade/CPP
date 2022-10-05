# Vector
Pengenalan: Vector adalah suatu class template yang merupakan bagian dari STL (Standard Template Library) dan dapat digunakan untuk menggantikan array. Sama dengan array, vector juga menyimpan elemen-elemen secara bersebelahan dan elemen tesebut dapat diakses sesuai subscript/index.

mari kita sama-sama mempelajari cara menggunakan:
```cpp
#include <vector>
```

### Keuntungan dari Vektor
- Ukuran vektor dapat diubah
- Beberapa objek dapat disimpan
- Elemen dapat dihapus dari vektor

### Kekurangan Vektor
- Vektor adalah objek, konsumsi memori lebih banyak.

### Terdapat Member Function Vector, seperti:
1. Iterators
2. Capacity
3. Element Acces
4. Modifier
5. Alocator

Macam-macam pendeklarasian Vector:
1. `vector <tipe_data> nama_variabel [jumlah_elemen];` jumlah elemen bersifat opsional atau 
2. `vector <tipe_data> nama_variabel;`
3. `vector <tipe_data> nama_variabel {element};`

Sebagai Permulaan kita akan menggunakan Syntax Dasar Modifier `push_back` terlebih dahulu

```cpp
#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{

    // Deklarasi Vector
    std::vector <int> v;

    // Menginisialisasikan Vector dengan angka = 1, 2, 3
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    
    std::cout << "Nilai Awal: ";
    std::cout << v[0] << v[1] << v[2] << std::endl;
    
    return 0;
}
```

maka akan menghasilkan
> Nilai Awal: 123
