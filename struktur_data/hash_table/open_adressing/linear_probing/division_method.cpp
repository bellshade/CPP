/**
 * @brief program untuk mensimulasikan penanganan tabrakan
 * pada hash table menggunakan open adressing metode linear
 * probing
 *
 * @authors yusuf
 *
 * @date 4 oktober 2025
 *
 * @details dibawah adalah salah satu implementasi dengan static
 * array,tetapi saya sudah menambahkan salah satu method dynamic
 * array jika anda ingin mengimplementasikan menggunakan dynamic
 * array anda dapat melanjutkan code dibawah
 */
#include <cstddef>
#include <iostream>
class HashTable {
private:
  std::size_t capacity;
  int size;
  int *table;
  const int Empty = -1;
  const int Deleted = -2;

public:
  // default constructor
  HashTable() {
    this->capacity = 8;
    this->size = 0;
    this->table = new int[capacity];
  }
  // constructor
  HashTable(std::size_t cap) {
    this->capacity = cap;
    this->size = 0;
    this->table = new int[capacity];
    // assign(capacity,empty)
    for (std::size_t i = 0; i < capacity; i++) {
      table[i] = Empty;
    }
  }
  // destructor
  ~HashTable() { delete[] table; }

private:
  int hash(int key) const { return key % capacity; }

public:
  bool insert(int key) {
    if (std::size_t(size) == capacity) {
      std::cout << "hash table penuh" << std::endl;
      return false;
    }
    int index = hash(key);
    int start_index = index;
    // linear probing
    // cek apakah index kosong dan index tidak pernah dihapus
    // cari slot kosong
    while (table[index] != Empty && table[index] != Deleted) {
      if (table[index] == key) {
        std::cout << "key sudah ada: " << key << std::endl;
        return false;
      }
      // circular array
      index = (index + 1) % capacity;
      if (index == start_index) {
        std::cout << "tidak bisa insert,table penuh" << std::endl;
        return false;
      }
    }
    table[index] = key;
    size++;
    return true;
  }

  bool search(int key) {
    int index = hash(key);
    int start_index = index;
    // jika hash index tidak kosong,cari slot kosong
    while (table[index] != Empty) {
      if (table[index] == key) {
        return true;
      }
      // majukan index
      index = (index + 1) % capacity;
      if (index == start_index) {
        break;
      }
    }
    return false;
  }

  bool remove(int key) {
    int index = hash(key);
    int start_index = index;
    while (table[index] != Empty) {
      if (table[index] == key) {
        table[index] = Deleted;
        size--;
        return true;
      }
      index = (index + 1) % capacity;
      if (index == start_index) {
        return false;
      }
    }
    return false;
  }

public: // property dynamic array
  void grow() {
    int *copy = new int[capacity * 2];
    capacity *= 2;
    for (std::size_t i = 0; i < capacity; i++) {
      copy[i] = table[i];
    }
    delete[] table;
    table = copy;
  }

public:
  void print() const noexcept {
    for (std::size_t i = 0; i < capacity; i++) {
      if (table[i] == Empty) {
        std::cout << i << ": " << "[]" << std::endl;
      } else if (table[i] == Deleted) {
        std::cout << i << ": " << "[x]" << std::endl;
      } else {
        std::cout << i << ": " << table[i] << std::endl;
      }
    }
  }

public:
  void clear() {
    for (std::size_t i = 0; i < capacity; i++) {
      table[i] = 0;
    }
    size = 0;
  }
};
int main() {
  HashTable hash(10);
  hash.insert(5); // 5 % 10 = 5
  hash.insert(6);
  hash.insert(15); // cari key lain karena index 5 sudah ke isi
  hash.insert(1);
  hash.insert(2);
  hash.print();
  std::cin.get();
  return 0;
}