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
class HashTable{
    private:
        struct Node{
            int val;
            Node* next;
            //constructor list
            Node(int val){
                this->val = val;
                this->next = nullptr;
            }
        };
    private:
        int m;
        Node** table;
    public://constructor
        //default constructor
        HashTable(): m(0){
            table = new Node*[m];
        }
        HashTable(int size): m(size){
            table = new Node*[m];
            //isi index
            for(int i = 0; i < m;i++){
                table[i] = nullptr;
            }
        }
        //range co
        //destructor
        ~HashTable(){
            clear();
        }
    public:
        int hash(int key){
            return key % m;
        }
    public:
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
        void insert(int key){
            //ambil index key
            int idx = hash(key);
            // buat node baru
            Node* new_node = new Node(key);
            //lakukan chaining pada index hash key
            new_node->next = table[idx];
            //update head baru
            table[idx] = new_node;
        }
        /**
        * @brief method untuk searching value
        * cara kerja
        * - hash value untuk menemukan index hash
        * - cari value pada index hash dengan loop linked list
        * - kembalikan true jika ditemukan,sebalik nya return false
        * @param value nilai yang akan dicari
        * @details complexity method
        * time complexity O(1),space complexity O(1)
        */
        bool search(int value){
            int index = hash(value);
            //cari key pada index hash
            Node* curr = table[index];
            //loop pada index hash
            while(curr != nullptr){
                if(curr->val == value){
                    return true;
                }
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
        bool deletion(int value){
            //deletion menggunakan eager deletion
            int index = hash(value);
            Node* curr = table[index];
            Node* prev = nullptr;
            while(curr != nullptr){
                if(curr->val == value){
                    Node* _next = curr;
                    prev->next = _next->next;
                    delete _next;
                    curr = curr->next;
                    return true;
                }
                    prev = curr;
                    curr = curr->next;
            }
            return false;
        }
    public:
        void print_table()const noexcept{
            for(int i = 0;i < m;i++){
                std::cout << i <<  "->";
                Node* curr = table[i];
                while(curr != nullptr){
                    std::cout << curr->val << " ->";
                    curr = curr->next;
                }
                std::cout << " nullptr" << std::endl;
            }
        }
    public:
        void clear()const noexcept{
            for(int i = 0;i < m;i++){
                Node* curr = table[i];
                //hapus node  chaining pada index
                while(curr != nullptr){
                    Node* temp = curr;
                    curr = curr->next;
                    delete temp;
                }
            }
            delete[] table;
        }
};
int main(){
    //pilih m prima agar distribuse merata
    HashTable hashMap(11);
    std::cout << "demo insert" << std::endl;
    hashMap.insert(10);
    hashMap.insert(5);
    hashMap.insert(1);
    hashMap.insert(3);
    hashMap.print_table();
    std::cout << "demo search" << std::endl;
    bool s = hashMap.search(10);
    if(s){
        std::cout << "ditemukan" << std::endl;
    }else{
        std::cout << "tidak ditemukan" << std::endl;
    }
    return 0;
}