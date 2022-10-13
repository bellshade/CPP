# Array dinamis

Array dinamis sangat mirip dengan array biasa, tetapi ukurannya dapat dimodifikasi saat program sedang berjalan. Elemen Dynamic Array menempati blok memori yang berdekatan.

Setelah array dibuat, tidak dapat diubah ukurannya. Namun, array dinamis berbeda. Array dinamis dapat diperluas bahkan setelah diisi.

Selama pembuatan array, itu dialokasikan jumlah memori yang telah ditentukan. Ini tidak berlaku untuk array dinamis, karena akan meningkatkan ukuran memorinya dengan faktor tertentu bila diperlukan.

faktor-faktor yang mempengaruhi kinerja dari array dinamis:
- Jika array memiliki ukuran kecil dan faktor pertumbuhan kecil, array akan terus mengalokasikan memori lebih sering. Ini akan mengurangi kinerja array.

- Jika sebuah array memiliki ukuran besar dan faktor pertumbuhan yang besar, ia akan memiliki banyak memori yang tidak terpakai. Karena itu, operasi pengubahan ukuran mungkin memakan waktu lebih lama. Ini akan mengurangi kinerja array.

di c++, kita dapat membuat array dinamis menggunakan keyword baru, jumlah item yang akan dialokasikan ditentukan dalam sepasang tanda kurung siku. nama jenis harus mendhului ini, jumlah item yang diminta akan dialokasikan.

**syntax**
```
variabel_pointer = tipe_data;
```
```cpp
#include <iostream>

int main(){
    int x, n;

    std::cout << "masukkan jumlah item: ";
    std::cin >> n;

    // membuat array dinammis
    int *arr = new int(n);

    // masukkan item pada array dinamis
    std::cout << n << " item" << std::endl;
    for(x = 0; x < n; x++){
        std::cin >> arr[x];
    }
    
    // tampilkan hasil
    std::cout << "kamu memasukkan: ";
    for (x = 0; x < n; x++){
        std::cout << arr[x];
    }

    return 0;
}
```

## menghapus array secara dinamis

Array dinamis harus dihapus dari memori komputer setelah tujuannya terpenuhi. Pernyataan hapus dapat membantu Anda mencapai hal ini. Ruang memori yang dibebaskan kemudian dapat digunakan untuk menyimpan kumpulan data lainnya. Namun, bahkan jika Anda tidak menghapus larik dinamis dari memori komputer, array dinamis akan dihapus secara otomatis setelah program dihentikan.

```cpp
#include <iostream>

int main(){
    int x, n;

    std::cout << "masukkan jumlah item";
    std::cin >> n;

    int *arr = new int(n);

    // memasukkan value ke dalam array dinamis
    std::cout << "masukkan " << n << " value: " << std::endl;
    for(x = 0; x < n; x++){
        std::cin >> arr[x];
    }

    // menampilkan value yang sebelumnya
    // sudah diinput ke dalam array dinamis
    std::cout << "kamu memasukkan: ";
    for(x = 0; x < n; x++){
        std::cout << arr[x] << " ";
    }
    std::cout << std::endl;
    // membuat perintah untuk menghapus
    // array dinamis
    delete []arr;

    return 0;
}
```

# FYI (For Your Information) / Reference