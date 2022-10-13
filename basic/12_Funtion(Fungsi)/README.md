## Fungsi

Fungsi adalah sekelompok pernyataan yang bersama-sama melakukan tugas. setiap program c++ memiliki setidaknya satu fungsi yaitu ``main()``, dan semua program yang paling  mudah dapat mendifinisikan fungsi tambahan.

kita dapat membagi kode kita menjadi fungsi-fungsi yang terpisah.deklarasi fungsi memberi tahu kompiler tentang nama fungsi, tipe pengembalian, dan parameter. definisi fungsi memberikan tubuh fungsi yang sebenarnya.

pustaka standar c++ menyediakan banyak fungsi bawaan yang dapat dipanggil oleh program kita. misalnya fungsi:
- ``strcat()`` untuk menggabungkan dua string 
- ``memcpy()`` untuk menyalin satu lokasi memori ke lokasi lain 

dan banyak lagi fungsi lainnya

## Mendifinisikan fungsi

bentuk umum dari definisi fungsi  c++ adalah sebagai berikut
```
tipe_return nama_fungsi(paraneter){
    isi_dari_fungsi
}
```

definisi fungsi c++ terdiri dari header fungsi dan badan fungsi.
- **tipe pengembalian**

    fungsi dapat mengembalikan nilai. **tipe_return** adalah tipe data dari nilai kembali fungsi. beberapa fungsi melakukan operasi yang diinginkan tanpa mengembalikan nilai. dalam hal ini, return type adalah kata kunci **void**

- **nama fungsi**

    ini adalah nama sebenarnya dari fungsi tersebut. nama fungsi dan daftar parameter bersama-sama membentuk tanda tangan fungsi.

- **parameter**

    parameter seperti placeholder. saat suatu fungsi dipanggil, kita memberikan nilai ke parameter. nilai ini desebut sebagai parameter atau argumen aktual. daftar parameter mengacu pada jenis urutan dan jumlah parameter suatu fungsi. parameter adalah opsional yaitu, suatu fungsi mungkin tidak mengandung parameter.

- **isi dari fungsi**

    fungsi berisi kumpulan pernyataan yang mendifinisikan apa yang dilakukan fungsi

contoh berikut ada fungsi yang menambahkan antara kedua parameter yaitu __angka1__ dan __angka2__

```cpp
int tambah(int angka1, int angka2){
    int hasil;
    hasil = angka1 + angka;

    return hasil;
}
```

## Mendeklarasi fungsi

Deklarasi fungsi memberi tahu kompiler tentang nama fungsi dan cara memanggil fungsi. tubuh dari fungsi dapat didefinisikan secara terpisah.

deklarasi fungsi memiliki bagian berikut
```
tipe_return nama_fungsi(parameter);
```

untuk fungsi yang sudah di definisikan dan dijadikan diatas, berikut contoh pemanggilannya
```cpp
int tambah(int angka1, int angka2);
```

nama parameter tidak penting dalam dekalari fungsi hanya tipenya yang diperlukan jadi berikut contoh deklarasi yang valid
```cpp
int tambah(int, int);
```

deklarasi fungsi diperlukan ketika mendifinisikan suatu fungsi dalam atau file sumber dan kita memanggil fungsi itu di file lain. dalam kasus seperti itu, kita harus mendeklarasikan fungsi di bagian atas file yang memanggil fungsi tersebut.

### Memanggil fungsi

Saat membuat fungsi c++, kita memberikan definisi tentang apa yang harus dilakukan fungsi tersebut. untuk menggunakan suatu fungsi, kita harus memanggil fungsi itu

ketika sebuah program memanggil fungsi, kontrol program ditransfer ke fungsi yang dipanggil. fungsi yang dipanggil melakukan tugas yang ditentukan dan ketika pernyataan pemgembaliannya dieksekusi atau ketika kurung kurawal penutup fungsi tercapai, ia mengembalikan kontrol program kembali ke program utama.

untuk memanggil suatu fungsi, anda hanya perlu meneruskan parameter yang diperlukan bersama dengan nama fungsi, dan jika fungsi mengembalikan nilai, maka anda dapat menyimpan nilai yang dikembalikan

```cpp
#include<iostream>

// mendeklarasikan fungsi
int tambah(int angka1, int angka2);

int main(){
    int a = 20;
    int b = 30;
    int hasil;

    hasil = tambah(a, b);
    std::cout << "hasilnya adalah :" << hasil;

    return 0;
}

// fungsi yang mengembalikan hasil dari operasi
// pertambahan antara angka1 dan angka2
int tambah(int angka1, int angka2){
    int hasil;
    hasil = angka1 + angka2;

    return hasil;
}
```

## Nilai default untuk parameter

Saat kita mendifinisikan suatu fungsi, kita dapat menentukan nilai default untuk setiap parameter terakhir. nilai ini akan digunakan jika argumen yang sesuai dibiarkan kosong saat memanggil fungsi.

ini dilakukan dengan menggunakan opertor penugasan dan menetapkan nilai untuk argumen dalam definisi fungsi. jika nilai untuk parameter tersebut tidak diteruskan saat fungsi dipanggil, nilai default yang diberikan akan digunakan, jika nilai ditentukan maka nilai default ini akan diabaikan.

```cpp
#include <iostream>

// membuat fungsi dengan menggunakan value
// default yaitu 3
int tambah(int angka1, int angka2 = 3){
    int hasil;
    hasil = angka1 + angka2;
    
    return hasil;
}

int main(){
    int a = 20;
    int b = 30;
    
    int hasil;
    hasil = tambah(a, b);
    std::cout << "tanpa default a = 20, b = 30 = " << hasil << std::endl;

    // memanggil kembali fungsi
    // dan hanya memasukkan satu parameter
    hasil = tambah(a);
    std::cout << "menggunakan default value = " << hasil;

    return 0;

}
```

# FYI (For Your Information) / Reference
- [Fungsi standar](https://www.youtube.com/watch?v=iTUO1DWVUv8&list=PLZS-MHyEIRo4Ze0bbGB1WKBSNMPzi-eWI&index=31)

- [fungsi dengan kembalian (return)](https://www.youtube.com/watch?v=LXZimpRJwno&list=PLZS-MHyEIRo4Ze0bbGB1WKBSNMPzi-eWI&index=33)

- [fungsi tanpa kembalian (void)](https://www.youtube.com/watch?v=4R4QZhsb8lQ&list=PLZS-MHyEIRo4Ze0bbGB1WKBSNMPzi-eWI&index=34)
