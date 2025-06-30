# PENGENALAN CONSTRUCTOR DAN DESTRUCTOR

## Constructor

Constructor adalah fungsi khusus dalam sebuah class di C++ yang **otomatis dipanggil saat objek dibuat**. Fungsinya untuk **menginisialisasi nilai awal dari data member** (variabel di dalam class).

```cpp
class Mahasiswa {
public:
    int data;
    Mahasiswa(int InputData) {
        this->data = InputData;  // inisialisasi data member
    }
};
```

Pada contoh di atas, constructor pada class `Mahasiswa` digunakan untuk memberikan nilai awal pada data member `data`.

---

## Cara Memberi Nilai Awal pada Data Member

Nilai awal data member bisa diberikan saat membuat objek di fungsi `main`:

```cpp
int main() {
    Mahasiswa siswa1(2);               // Membuat objek dengan data = 2
    std::cout << siswa1.data << '\n';   // Menampilkan data
    std::cin.get();
    return 0;
}
```

---

## Class dengan Data Dinamis

Pada contoh sebelumnya, data disimpan **langsung di dalam objek** dan memori otomatis dialokasikan saat objek dibuat.
Namun, ada juga class dengan **data dinamis**, yaitu data yang dialokasikan di *heap* menggunakan pointer dan operator `new`.
[Class Dinamis](Constructor_Destructor.cpp);
Contohnya adalah class `Node`, yang biasa digunakan untuk implementasi **linked list**:

```cpp
class Node {
public:
    int data;
    Node* next;          // pointer ke Node berikutnya

    // Constructor
    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};
```

Untuk menginisialisasi node secara dinamis:

```cpp
int main() {
    Node* head = new Node(3);      // node pertama dengan data = 3

    // Menambah node berikutnya (contoh):
    head->next = new Node(4);
    head->next->next = new Node(5);

    // Menghapus seluruh node (cukup delete head jika destructor rekursif)
    delete head;
    return 0;
}
```

---

## Destructor

Karena data dinamis (menggunakan pointer dan operator `new`) **tidak dihapus otomatis oleh C++**, kita perlu membuat **destructor** agar memori dibersihkan saat objek dihapus.

* Destructor adalah fungsi khusus pada class, dengan nama diawali tanda `~` (tilde).
* Destructor **selalu tanpa parameter** dan tidak bisa di-*overload*.

```cpp
class Node {
public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }

    ~Node() {
        delete next;  // Menghapus seluruh node setelahnya secara rekursif
    }
};
```

Dengan destructor seperti di atas, saat `delete head;` dipanggil, semua node berikutnya akan dihapus dari memori secara otomatis.

---

## Kesimpulan

* **Constructor** menginisialisasi nilai awal data member ketika objek dibuat.
* **Destructor** membersihkan resource/memori saat objek dihapus, sangat penting untuk class dengan data dinamis (pointer & `new`).
* Data yang disimpan langsung di objek akan otomatis dibersihkan oleh C++.
* Data dinamis wajib dibersihkan dengan destructor untuk mencegah *memory leak*.

---

> **Catatan Singkat:** Destructor tidak memiliki parameter, sedangkan constructor dapat memiliki parameter untuk memudahkan inisialisasi data member.
