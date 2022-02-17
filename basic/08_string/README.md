# string

c++ menyediakan dua jenis representasi string yaitu
- string karakter dengan gaya C
- tipe kelas string diperkenalkan dengan standard c++

## string karakter style dari C

String karakter gaya-C berasal dari bahasa C dan terus didukung dalam C++. String ini sebenarnya adalah array karakter satu dimensi yang diakhiri dengan karakter null '\0'. Jadi string yang diakhiri null berisi karakter yang membentuk string diikuti oleh null .

Deklarasi dan inisialisasi berikut membuat string yang terdiri dari kata "Halo". Untuk menahan karakter null di akhir larik, ukuran larik karakter yang berisi string adalah satu lebih banyak dari jumlah karakter dalam kata "Halo."

```cpp
char salam[6] = {'H', 'e', ​​'l', 'l', 'o', '\0'};
```

Jika Anda mengikuti aturan inisialisasi array, maka Anda dapat menulis pernyataan di atas sebagai berikut

```cpp
char salam[] = "Halo";
```

contoh sederhana
```cpp
#include <iostream>

int main(){
    char salam[6] = {'H', 'e', ​​'l', 'l', 'o', '\0'};
    std::cout<<"pesan yang keluar adalah ";
    std::cout<<salam<<std::endl;

    return 0;
}
```
contoh mengikuti inisialisasi dari array

```cpp
#include <iostream>

int maian(){
    char salam[] = "Hello boys";
    std::cout<<salam;

    return 0
}
```

contoh lebih lanjut dari string

- [pengenalan string](https://www.youtube.com/watch?v=DpVq7KUHjgY&list=PLZS-MHyEIRo4Ze0bbGB1WKBSNMPzi-eWI&index=55)
- [operasi pada string](https://www.youtube.com/watch?v=Sq3_mzqdFj0&list=PLZS-MHyEIRo4Ze0bbGB1WKBSNMPzi-eWI&index=56)
- [komparasi atau perbandingangn string](https://www.youtube.com/watch?v=iXWYWFZfP98&list=PLZS-MHyEIRo4Ze0bbGB1WKBSNMPzi-eWI&index=57)
- [akses substring](https://www.youtube.com/watch?v=OpodtuA0xyI&list=PLZS-MHyEIRo4Ze0bbGB1WKBSNMPzi-eWI&index=58)
- [substitusi string](https://www.youtube.com/watch?v=Sq-Efm6vRYA&list=PLZS-MHyEIRo4Ze0bbGB1WKBSNMPzi-eWI&index=59)
- [getline console sting](https://www.youtube.com/watch?v=FkCkMV6wjDs&list=PLZS-MHyEIRo4Ze0bbGB1WKBSNMPzi-eWI&index=60)
