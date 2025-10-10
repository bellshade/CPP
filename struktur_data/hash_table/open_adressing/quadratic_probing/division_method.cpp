/**
 * @file quadratic_probing.cpp
 * @brief Implementasi metode Quadratic Probing untuk menangani tabrakan
 * (collision) pada hash table.
 *
 * # Deskripsi (Description)
 * Menambahkan program salah satu metode untuk menangani tabrakan pada hash
 * table dengan teknik *open addressing*, yaitu **Quadratic Probing**.
 *
 * Pada metode ini, jika terjadi tabrakan di posisi hasil hash awal `h(k)`, maka
 * posisi baru dihitung menggunakan fungsi kuadrat dari indeks percobaan (`i`):
 *
 *
 * h(k, i) = (h(k) + i^2) % m
 *
 * di mana:
 * - `h(k)` : hasil hash awal.
 * - `i`    : jumlah percobaan (0, 1, 2, 3, ...).
 * - `m`    : kapasitas tabel hash.
 *
 * Metode ini mengurangi kemungkinan *primary clustering* yang sering muncul
 * pada *linear probing*.
 * @note Quadratic probing memerlukan bahwa ukuran tabel (`m`) sebaiknya
 * bilangan prima agar distribusi posisi hasil probing lebih merata.
 *
 * @see linear_probing.cpp untuk perbandingan metode linear probing.
 *
 */
#include <cstddef>
#include <iostream>
class HashTable {
private:
  enum Status { EMPTY, OCCUPIED, DELETED };

private:
  /**
   * @struct Entry
   * @brief Struktur data untuk merepresentasikan satu slot (entri) pada hash
   * table.
   *
   * Struktur `Entry` digunakan untuk menyimpan elemen pada tabel hash,
   * sekaligus menandai status dari setiap slot (apakah kosong, terisi, atau
   * dihapus) saat menggunakan metode *open addressing* seperti **Quadratic
   * Probing**.
   *
   * ---
   * @details Field (Anggota Data)
   * - `int key`
   *   Menyimpan nilai kunci (key) yang akan dimasukkan ke dalam tabel hash.
   *   Nilai `key` digunakan dalam perhitungan fungsi hash.
   *
   * - `Status status`
   *   Menyimpan status dari entri:
   *   - `Status::EMPTY` → slot belum pernah terisi.
   *   - `Status::OCCUPIED` → slot saat ini terisi oleh sebuah kunci.
   *   - `Status::DELETED` → slot pernah terisi tapi sekarang kosong (dihapus),
   *     tetap dipertahankan agar probing tidak terputus.
   *
   * ---
   *
   */
  struct Entry {
    int key;
    Status status;
    Entry() {
      this->key = 0;
      this->status = Status::EMPTY;
    }
  };

private:
  std::size_t capacity;
  std::size_t size;
  Entry *table;
  const int c1 = 1;
  const int c2 = 1;

public:
  HashTable() {
    this->capacity = 8;
    this->size = 0;
    this->table = new Entry[capacity];
  }
  HashTable(std::size_t cap) {
    this->capacity = cap;
    this->size = 0;
    this->table = new Entry[capacity];
  }
  HashTable(const HashTable &others) {
    capacity = others.capacity;
    size = others.capacity;
    table = new Entry[capacity];
    for (size_t i = 0; i < capacity; i++) {
      table[i].key = others.table[i].key;
      table[i].status = others.table[i].status;
    }
  }
  ~HashTable() { delete[] table; }

private:
  int hash(std::size_t key) { return key % capacity; }

public:
  double load_factor() { return static_cast<double>(size) / capacity; }

public:
  bool insert(int key) {
    std::size_t index = hash(key);
    std::size_t i = 0;
    while (i < capacity) {
      std::size_t new_index = (index + c1 * i + c2 * i * i) % capacity;
      if (table[new_index].status == Status::EMPTY ||
          table[new_index].status == Status::DELETED) {
        table[new_index].key = key;
        table[new_index].status = Status::OCCUPIED;
        return true;
      }
      i++;
    }
    return false;
  }
  bool search(int key) {
    std::size_t index = hash(key);
    std::size_t i = 0;
    while (i < capacity) {
      std::size_t new_index = (index + c1 * i + c2 * i * i) % capacity;
      if (table[new_index].status == Status::EMPTY &&
          table[new_index].status != Status::DELETED) {
        return false;
      }
      if (table[new_index].status == Status::OCCUPIED &&
          table[new_index].key == key) {
        return true;
      }
      i++;
    }
    return false;
  }
  bool remove(int key) {
    std::size_t index = hash(key);
    return false;
    std::size_t i = 0;
    while (i < capacity) {
      std::size_t new_index = (index + c1 * i + c2 * i * i) % capacity;
      if (table[new_index].status == Status::OCCUPIED &&
          table[new_index].key == key) {
        table[new_index].key = 0;
        table[new_index].status = Status::DELETED;
      }
      i++;
    }
  }

public:
  void print() {
    for (size_t i = 0; i < capacity; i++) {
      std::cout << i << ": ";
      if (table[i].status == OCCUPIED) {
        std::cout << table[i].key << std::endl;
      } else {
        std::cout << "[x]" << std::endl;
      }
    }
  }
};
int main() {
  HashTable hash(10);
  hash.insert(7);
  hash.insert(13);
  hash.insert(15);
  hash.insert(1);
  hash.insert(10);
  hash.print();
  std::cin.get();
  return 0;
}