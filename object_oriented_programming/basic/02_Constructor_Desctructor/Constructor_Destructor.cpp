#include <iostream>
#include <string>
/**
 * @class Node
 * @brief Node tunggal untuk singly linked-list.
 *
 * Setiap Node menyimpan satu nilai `data` dan pointer ke Node berikutnya.
 * Destructor bersifat rekursif—menghapus node setelahnya agar tidak terjadi
 * memory-leak bila head di-delete.
 */
class Node{
    public:
        int data; //data yang disimpan dalam node
        Node* next; //pointer ke Node berikutnya
        //Constructor
        Node(int data){
            this->data = data;
            this->next = nullptr; //Element teralhir linked list selalu Null
        }
        //destructor
        ~Node(){
            std::cout << "data dihapus: " << data << std::endl;
            delete next;
        }
};
int main(){
    //insertion value
    // Membuat list: 3 → 4 → 5
    Node* head = new Node(3);
    head->next = new Node(4);
    head->next->next = new Node(5);
    //agar destructor membersihkan seluruh list
    delete head;
    std::cin.get();
    return 0;
}   