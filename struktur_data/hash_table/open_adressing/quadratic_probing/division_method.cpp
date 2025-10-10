#include <cstddef>
#include <iostream>
class HashTable {
private:
  enum Status { EMPTY, OCCUPIED, DELETED };

private:
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