# **Pengenalan**
 **Vector** adalah suatu class template yang merupakan bagian dari STL (Standard Template Library) dan dapat digunakan untuk menggantikan array. Sama dengan array, vector juga menyimpan elemen-elemen secara bersebelahan dan elemen tesebut dapat diakses sesuai subscript/index.

 Vektor dalam C++ juga adalah wadah urutan yang mewakili array yang dapat mengubah ukurannya selama runtime. Mereka menggunakan lokasi penyimpanan yang berdekatan untuk elemen mereka sama efisiennya seperti dalam array, yang berarti bahwa elemen mereka juga dapat diakses menggunakan offset pada pointer biasa ke elemennya.

mari kita sama-sama mempelajari cara menggunakan:
```cpp
#include <vector>
```

### Keuntungan dari Vector
- Ukuran vektor dapat diubah
- Beberapa objek dapat disimpan
- Elemen dapat dihapus dari vektor

### Kekurangan Vector
- Vektor adalah objek, konsumsi memori lebih banyak.

## Terdapat Member Function Vector, seperti:
1. Iterators
    - begin
    - cbegin (c++11)
    - end
    - cend (c++11)
    - rbegin
    - crbegin (c++11)
    - rend
    - crend (c++11)

2. Capacity
    - Empty
    - Size
    - reserve
    - max_size
    - capacity
    - shrink_to_fit

3. [Element Acces](vector-access.cpp)
    - at
    - front
    - back
    - data
    - operator[]

4. [Modifiers](vector-modifiers.cpp)
    - emplace (c++11) 
    - insert
    - push_back
    - pop_back
    - clear
    - eraser
    - resize
    - swap

[Contoh penggunaan lainnya](https://www.geeksforgeeks.org/vector-in-cpp-stl/)
> Tidak perlu pusing karena terlalu banyak member fungsi yang ada pada vector, cukup perlu tau cara penggunaan dasarnya saja.

Macam-macam pendeklarasian Vector:
1. `vector <tipe_data> nama_variabel [jumlah_elemen];` 
    > jumlah elemen bersifat opsional, atau
2. `vector <tipe_data> nama_variabel;`
3. `vector <tipe_data> nama_variabel {element};`

# **Demo Code**

### Header
```cpp
#include <iostream> 
#include <vector>
```
kita masukan header `vector` disana dan kita akan menggunakan beberapa syntax dari header `vector` ini nantinya

### Function
```cpp
void loop(std::vector <std::string> para){
    std::cout << "Berikut berisikan data yang berupa: " << std::endl;
    for(int i = 0; i < para.size(); i++){
        if(i < 9){
            std::cout << "0";
        }
        std::cout << i+1 << ". " << para[i] << std::endl;
    }
    std::cout << std::endl;
}
```
Fungsi ini akan kita pakai untuk melooping nilai-nilai yang ada pada vector dari nilai awal hingga akhir

# FYI (For Your Information) / Reference
[en.cppreference.com](https://en.cppreference.com/w/cpp/container/vector)
[geeksforgeeks.org](https://www.geeksforgeeks.org/vector-insert-function-in-c-stl/)