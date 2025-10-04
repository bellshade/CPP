/**
 * @brief Salah satu hash function klasik adalah Multiplication Method.
 *
 * Metode ini jarang dipakai langsung pada implementasi hash table modern,
 * tetapi diperkenalkan dalam textbook (Knuth, Cormen) untuk memberikan
 * distribusi yang lebih stabil dibanding division method.
 *
 * Rumus dasar:
 *     h(k) = floor( m * ((k * A) mod 1) )
 *
 * dengan:
 * - h(k) : nilai hash (index bucket)
 * - m    : jumlah bucket
 * - A    : konstanta real, 0 < A < 1
 * - (k * A mod 1) : bagian pecahan dari k * A
 *
 * Catatan:
 * - floor ditulis dengan tanda [ ] dalam literatur.
 * - Nilai A yang disarankan Knuth adalah konstanta golden ratio:
 *       A = (sqrt(5) - 1) / 2 ≈ 0.6180339887
 *
 * @details
 * Multiplication method lebih jarang dipakai di library modern
 * (misalnya C++ STL atau Java Collections) karena mereka memakai
 * hash function lain (FNV, Murmur, CityHash, SipHash).
 * Namun ide "bit mixing dengan perkalian konstanta" masih banyak
 * dipakai dalam hash modern untuk penyebaran nilai yang lebih merata.
 */

#include <cmath>
#include <cstddef>
#include <iostream>
class HashTable {
private:
  struct Node {
    int x;
    Node *next;
    explicit Node(int x) {
      this->x = x;
      this->next = nullptr;
    }
  };

private:
  int m;         // ukuran bucket
  std::size_t n; // banyak element
  Node **table;

private:
  int hash(int key) {
    const double A = (std::sqrt(5.0) - 1) / 2.0; // knuth's constant
    /*
    diberikan a sebagai bilangan real,sisa bagi di definisikan
    a = qb + r
    dimana:
    a = bilangan real
    q = quotient(hasi bagi)
    b = divisor
    r = reminder (sisa bagi)
    untuk mendapatkan sisa bagi dirumuskan:
    r = a - qb dengan {r | 0  <= r <= |b|}
    dengan defini diatas kita dapat mencari key * A mod 1 dengan:
    r = a - qb
    r = key * A - qb..............(1)
    diketahui divisor 1,maka:
    r = key * A - (q x b)...........(2.a)
    dapat dicari q(hasil bagi) dengan:
    q = (key * A / 1(b).............(2.b)
    karena q pada multiplication method berupa desimal maka:
    q = floor(key * A / 1(b));
    dengan begitu key * A mod 1 dapat dirmuskan
    q = key * A - (floor(key * A)).........(2)
    dimana:
    a = key * A
    q = key * A / 1(b)
    b = 1
    r = reminder (sisa bagi)
     */
    double frac = key * A - (std::floor(key * A));
    // harus di cast ke int agar index valid
    return int(std::floor(m * frac));
  }

public:
  // default constructor
  explicit HashTable() {
    this->m = 0;
    this->n = 0;
    this->table = new Node *[m];
    table[m] = nullptr;
  }
  explicit HashTable(int size) {
    this->m = size;
    this->n = 0;
    this->table = new Node *[m];
    for (int i = 0; i < m; i++) {
      table[i] = nullptr;
    }
  }
  // copy constructor
  explicit HashTable(const HashTable &others) {
    m = others.m;
    n = others.n;
    table = new Node *[m];
    for (int i = 0; i < m; i++) {
      table[i] = others.table[i];
      Node *curr = others.table[i];
      Node **tail = &table[i]; // store memory addres ke tail
      while (curr != nullptr) {
        *tail = new Node(curr->x);
        tail = &((*tail)->next);
        curr = curr->next;
      }
    }
  }
  ~HashTable() { clear(); }

public:
  double load_factor() { return static_cast<double>(n) / m; }

public:
  void insert(int key) {
    int index = hash(key);
    Node *new_node = new Node(key);
    new_node->next = table[index];
    table[index] = new_node;
    n++;
  }
  bool deletion(int value) {
    int index = hash(value);
    Node *curr = table[index];
    Node *prev = nullptr;
    while (curr != nullptr) {
      if (curr->x == value) {
        if (prev == nullptr) {
          // head menunjuk node setelah curr
          table[index] = curr->next;
        } else {
          // linking prev ke node setelah curr
          prev->next = curr->next;
        }
        delete curr;
        n--;
        return true;
      }
      prev = curr;
      curr = curr->next;
    }
    return false;
  }
  bool search(int value) {
    int index = hash(value);
    Node *curr = table[index];
    while (curr != nullptr) {
      if (curr->x == value) {
        return true;
      }
    }
    return false;
  }

public:
  void print() {
    for (int i = 0; i < m; i++) {
      std::cout << i << ":";
      Node *curr = table[i];
      while (curr != nullptr) {
        std::cout << curr->x << " -> ";
        curr = curr->next;
      }
      std::cout << "nullptr \n";
    }
  }

public:
  void clear() {
    for (int i = 0; i < m; i++) {
      Node *curr = table[i];
      while (curr != nullptr) {
        Node *temp = curr;
        curr = curr->next;
        delete temp;
      }
    }
  }
};
int main() {
  HashTable hash(8); // pakai power of two
  hash.insert(7);    // index 1
  std::cout << "load factor saat ini: " << hash.load_factor() << std::endl;
  hash.insert(5);
  std::cout << "load factor saat ini: " << hash.load_factor() << std::endl;
  hash.insert(19);
  std::cout << "load factor saat ini: " << hash.load_factor() << std::endl;
  hash.insert(6);
  std::cout << "load factor saat ini: " << hash.load_factor() << std::endl;
  hash.insert(2);
  std::cout << "load factor saat ini: " << hash.load_factor() << std::endl;
  hash.print();
  std::cin.get();
  return 0;
}