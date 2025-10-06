# Hash Table - Open Addressing

## Daftar Isi
1. [Definisi Open Addressing](#definisi-open-addressing)  
2. [Requirements](#requirements)  
3. [Jenis Open Addressing](#jenis-open-addressing)  
   - [Linear Probing](#linear-probing)  
   - [Quadratic Probing](#quadratic-probing)  
   - [Double Hashing](#double-hashing)  

---

## 1. Definisi Open Addressing
Open Addressing adalah metode dimana semua elemen disimpan langsung di dalam hash table itu sendiri, tanpa menggunakan struktur data eksternal seperti linked list.  
Jika terjadi **collision (tabrakan)**, maka algoritma akan mencari slot kosong lain di dalam array berdasarkan aturan pencarian (*probing*).  

---

## 2. Requirements
Dibutuhkan prasyarat untuk melangkah ke linear probing, di antaranya:

- Memahami implementasi **Array**  
- Memahami implementasi **Circular Array**  
- Memahami implementasi **Dynamic Array**, misalnya *doubling method* untuk memperbesar ukuran hash table  
- Memahami **Hash Function**, misalnya *Division Method*  

Jika belum terlalu memahami requirements di atas, Anda dapat belajar pada:

- [Hash Function](struktur_data/hash_table/hash_function)  
- [Dynamic Array](https://www.geeksforgeeks.org/dsa/how-do-dynamic-arrays-work/)  
- [Circular Array](https://www.geeksforgeeks.org/dsa/circular-array/)  
- [Array](https://www.geeksforgeeks.org/dsa/array-data-structure-guide/)  

---

## 3. Jenis Open Addressing
Jenis *open addressing* dibedakan dari metode mencari slot kosong pada array.  
Ada 3 jenis *open addressing* yaitu:  

---

### Linear Probing
**Linear Probing** adalah salah satu teknik *open addressing* pada hash table untuk menangani **collision (tabrakan)**.  
Jika sebuah slot index hash penuh, maka algoritma akan mencari slot kosong secara **linear** di dalam array hash table.  

Rumus probing:
```math
h(k) = (h(k) + 1) \bmod \text{Capacity}
```
Dimana:
- `h(k)` = hash index
- `Capacity` = kapasitas hash table

**Contoh langkah:**
1. Hitung index awal: `idx = h(k) % m`
2. Jika `table[idx]` kosong → simpan di `table[idx]`
3. Jika penuh → coba `idx = (idx + 1) % m`
4. Ulangi langkah 3 sampai menemukan slot kosong atau tabel penuh

Salah satu implementasi Linear Probing dapat digunakan pada hash function: [division_method.cpp](struktur_data/hash_table/hash_table.cpp)
