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
1. Buat Hash Table

![step1](../asset/gift/step0.gif)

2. Hitung index awal: `idx = h(k) % m`

![step2](../asset/gift/step1.gif)

3. Jika `table[idx]` kosong → simpan di `table[idx]`

![step4](../asset/gift/step2.gif)

4. Jika penuh → coba `idx = (idx + 1) % m`

![step4](../asset/gift/step3.gif)

5. Ulangi langkah 3 sampai menemukan slot kosong atau tabel penuh

Salah satu implementasi Linear Probing dapat digunakan pada hash function: [division_method.cpp](struktur_data/hash_table/hash_table.cpp)

### Quadratic Probing
**Quadratic Probing** adalah salah satu metode penanganan collision pada `hash table` untuk menangani **collision (tabrakan)**

Jika sebuah slot index hash penuh, maka algoritma akan mencari slot kosong menggunakan **fungsi kuadrat** terhadap jumlah percobaan `probe`

Rumus **Quadratic probing**
```math
h(k) = (h(k) + c1 * i + c2 *i * i) \bmod \text{capacity}
```

dimana:

`h(k)` = index hash

`i` = jumlah percobaan(probe) ke -i

`c1,c2` = kostanta(biasanya `c1 = c2 = 1`) 

`capacity` = kapasitas hash table(banyak bucket)

**Langkah-langkah Quadratic Probing**
1.Gunakan fungsi hash untuk mendapatkan posisi awal
```math
h(k) = key \bmod \text{capacity}
```
2.periksa apakah slot kosong

- jika posisi h(k) kosong -> simpan data disitu

- jika sudah terisi lanjut ke langkah berikutnya

3.Gunakan fungsi kuadrat untuk mencari posisi baru
saat terjadi `collision` ke-i,hitung posisi baru:
```math
h(k) = (h(k) + c1 * i + c2 *i * i) \bmod \text{capacity}
```
4.cek apakah slot hasil probing kosong

- jika posisi h(k) kosong -> simpan data disitu

- jika sudah terisi ->increment i(i++)

5.berhenti jika ditemukan posisi kosong atau table penuh

Salah satu implementasi Quadratic Probing dapat digunakan pada hash function: [Quadratic Probing.cpp](struktur_data/hash_table/open_adressing/quadratic_probing/division_method.cpp)
