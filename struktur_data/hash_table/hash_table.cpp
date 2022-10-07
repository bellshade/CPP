#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

// besar array tabel hash
template <int TABLE_SIZE>
class HashTable {
    private:
        // inisialisasi linked list untuk setiap index array
        list<int> tableList[TABLE_SIZE];
        // fungsi hash tabel hash
        int getHash(int value) {
            return value % TABLE_SIZE;
        }
    public:
        // fungsi untuk menyimpan nilai
        void insert(int value) {
            int hash = getHash(value);
            tableList[hash].push_back(value);
        }
        // fungsi untuk menghapus nilai
        void destroy(int value) {
            int hash = getHash(value);
            tableList[hash].erase(remove(tableList[hash].begin(), tableList[hash].end(), value), tableList[hash].end());
        }
        // fungsi untuk mencari nilai
        void search(int value) {
            int hash = getHash(value);
            list<int>::iterator result = find(tableList[hash].begin(), tableList[hash].end(), value);
            if(result != tableList[hash].end()) {
                printf("nilai %d ditemukan\n", value);
            } else {
                printf("nilai %d tidak ditemukan\n", value);
            }
        }
        // fungsi untuk meng-print tabel
        void printTable() {
            for(int i = 0; i < TABLE_SIZE; i++) {
                printf("%d --> ", i);
                for (auto const &value : tableList[i]) {
                    cout << value << ' ';
                }
                printf("\n");
            }
        }
};

int main() {
    // inisialisasi tabel
    HashTable<5> tabelHash;

    // demo insert
    tabelHash.insert(21);
    tabelHash.insert(32);
    tabelHash.insert(19);
    printf("Tabel Hash Sebelum Kolisi\n");
    tabelHash.printTable();
    printf("\n");

    // demo collision
    tabelHash.insert(37);
    printf("Tabel Hash Sesudah Kolisi\n");
    tabelHash.printTable();
    printf("\n");

    // demo search
    printf("Hasil Pencarian Sebelum Penghapusan\n");
    tabelHash.search(37);
    printf("\n");
    
    // demo destroy
    tabelHash.destroy(37);
    printf("Hasil Pencarian Sesudah Penghapusan\n");
    tabelHash.search(37);
    tabelHash.printTable();
    printf("\n");
    
    return 0;
}