# Struktur Data
Struktur data adalah format khusus untuk mengatur, memproses, mengambil, dan menyimpan data. Struktur data memudahkan programmer untuk menyimpan dan memproses data untuk sebuah aktivitas tertentu. Secara general, penggunaan struktur data yang tepat adalah kunci dari mendesain algoritma yang efisien.

## Implementasi Struktur Data
Struktur data sering kali diimplementasi menggunakan tiga komponen, yaitu tipe data, pointer, dan sekumpulan operasi. 

- Tipe data: mendefinisikan tipe data atau nilai yang dapat disimpan dalam sebuah struktur data.
- Pointer: membantu programmer dalam mendesain struktur data yang lebih kompleks dan terlepas dari heap memory seperti array.
- Operasi: merupakan kumpulan operasi yang digunakan untuk berinteraksi dengan struktur data tersebut. Contohnya seperti `insert`, `delete`, `find`, dst.

Kemudian, ketiga komponen ini dikemas dengan struktur [Struct](./struct_ds).

## Tipe Struktur Data
Ada banyak struktur data yang dapat kita gunakan, masing-masing memiliki aturan pengaplikasian yang berbeda-beda. Berikut adalah contoh struktur data elementer yang sering dipelajari beserta deskripsinya:

- Linked-list: adalah struktur data linear dimana data-data yang disimpan dihubungkan menggunakan pointer.
- Stack: adalah linked-list yang memiliki aturan tertentu yakni `LIFO` (last-in fist-out), dimana elemen yang dihapus dari set adalah yang paling terakhir dimasukkan.
- Queue: adalah linked-list yang memiliki aturan tertentu yakni `FIFO` (first-in fist-out), dimana elemen yang dihapus dari set adalah yang paling pertama dimasukkan.
- Binary Search Tree: adalah struktur data yang menyerupai pohon dengan dua cabang, biasanya digunakan pada algoritma _searching_.

Berikut adalah materi yang dapat anda baca lebih lanjut mengenai struktur data diatas:

- [Linked-list](./linked_list)
- [Binary-Search-Tree](./binary_search_tree)

