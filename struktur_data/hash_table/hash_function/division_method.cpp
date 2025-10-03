/**
 * @brief division method adalah salah satu hash_function yang digunakan
 * untuk memetakan value ke key tertentu pada hash table.
 * Division method dirumuskan dengan:
 * h(k) = k % m
 * dimana:
 * h(k) = nilai hash(index bucket)
 * k = key(nilai yang akan di hash)
 * m = besar hash table(jumlah bucket)
 *
 * @details pemilihan nilai m
 * disarankan agar memilih nilai m prima agar distribusi nilai hash merata
 * tidak terfokus pada nilai tertentu.
 */

#include <iostream>

class HashTable {
private:
    struct Node {
        int val;
        Node* next;
        // constructor list
        explicit Node(int val) {
            this->val = val;
            this->next = nullptr;
        }
    };

private:
    int m;
    Node** table;

public:
    // default constructor
    HashTable() : m(0) {
        table = new Node*[m];
        table[m] = nullptr;
    }

    explicit HashTable(int size) : m(size) {
        table = new Node*[m];
        // isi index
        for (int i = 0; i < m; i++) {
            table[i] = nullptr;
        }
    }

    HashTable(const HashTable& others) {
        m = others.m;
        table = new Node*[m];
        for (int i = 0; i < m; i++) {
            table[i] = nullptr;
            Node* curr = others.table[i];
            Node** tail = &table[i];  // store memory address to tail
            while (curr != nullptr) {
                *tail = new Node(curr->val);
                tail = &((*tail)->next);
                curr = curr->next;
            }
        }
    }

    ~HashTable() { clear(); }

public:
    int hash(int key) { return key % m; }

    /**
     * @brief method untuk insert value pada hash table
     * cara kerja:
     * - hash key untuk menentukan index hash
     * - insert value pada key dengan menggunakan konsep
     *   insert at head linked list
     * - update head
     * @param key nilai yang akan di insert
     * @details Complexity
     * Time Complexity O(1),Space Complexity O(1)
     */
    void insert(int key) {
        // ambil index key
        int idx = hash(key);
        // buat node baru
        Node* new_node = new Node(key);
        // lakukan chaining pada index hash key
        new_node->next = table[idx];
        // update head baru
        table[idx] = new_node;
    }

    /**
     * @brief method untuk searching value
     * cara kerja
     * - hash value untuk menemukan index hash
     * - cari value pada index hash dengan loop linked list
     * - kembalikan true jika ditemukan,sebaliknya return false
     * @param value nilai yang akan dicari
     * @details complexity method
     * time complexity O(1),space complexity O(1)
     */
    bool search(int value) {
        int index = hash(value);
        Node* curr = table[index];
        while (curr != nullptr) {
            if (curr->val == value) {
                return true;
            }
            curr = curr->next;  // <== perbaikan bug, harus majuin curr
        }
        return false;
    }

    /**
     * @brief method untuk hapus value
     * karena menggunakan separate chaining maka memakai eager deletion
     * cara kerja
     * - hash value untuk menemukan index hash
     * - cari value pada index hash dengan loop linked list
     * - hapus value dan kembalikan true jika ditemukan,sebaliknya return false
     * @param value nilai yang akan dicari
     * @details complexity method
     * time complexity O(1),space complexity O(1)
     */
    bool deletion(int value) {
        int index = hash(value);
        Node* curr = table[index];
        Node* prev = nullptr;
        while (curr != nullptr) {
            if (curr->val == value) {
                if (prev == nullptr) {
                    table[index] = curr->next;  // handle head deletion
                } else {
                    prev->next = curr->next;
                }
                delete curr;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
        return false;
    }

public:
    void print_table() const noexcept {
        for (int i = 0; i < m; i++) {
            std::cout << i << "->";
            Node* curr = table[i];
            while (curr != nullptr) {
                std::cout << curr->val << " ->";
                curr = curr->next;
            }
            std::cout << " nullptr" << std::endl;
        }
    }

    void clear() const noexcept {
        for (int i = 0; i < m; i++) {
            Node* curr = table[i];
            while (curr != nullptr) {
                Node* temp = curr;
                curr = curr->next;
                delete temp;
            }
        }
        delete[] table;
    }
};

int main() {
    // pilih m prima agar distribusi merata
    HashTable hashMap(11);
    std::cout << "demo insert" << std::endl;
    hashMap.insert(10);
    hashMap.insert(5);
    hashMap.insert(1);
    hashMap.insert(3);
    hashMap.print_table();

    std::cout << "demo search" << std::endl;
    bool s = hashMap.search(10);
    if (s) {
        std::cout << "ditemukan" << std::endl;
    } else {
        std::cout << "tidak ditemukan" << std::endl;
    }

    // demo copy constructor
    HashTable hash = hashMap;
    hash.print_table();
    return 0;
}
