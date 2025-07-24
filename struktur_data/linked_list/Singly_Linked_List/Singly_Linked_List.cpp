/**
 * @file singly_linked_list.cpp
 * @brief Contoh sederhana implementasi operasi dasar *singly linked list* (traversal, searching, length, dan insertion) dalam C++.
 */

 #include <iostream>

 /**
  * @brief Node struktur untuk singly linked list.
  */
 struct Node {
     int  data;   ///< Data yang disimpan pada node
     Node *next;  ///< Pointer ke node berikutnya (nullptr jika tail)
 
     /**
      * @brief Konstruktor Node.
      * @param new_data Nilai yang akan disimpan di node baru.
      */
     explicit Node(int new_data) : data(new_data), next(nullptr) {}
 };
 
 /**
  * @brief Melakukan traversal dan mencetak seluruh elemen linked list.
  * @param head Pointer ke node pertama (boleh nullptr jika list kosong).
  *
  * Kompleksitas: O(n) waktu, O(1) ruang tambahan.
  */
 void traversal_linkedList(const Node *head) {
     const Node *curr = head;
     while (curr != nullptr) {
         std::cout << curr->data << ' ';
         curr = curr->next;
     }
     std::cout << '\n';
 }
 
 /**
  * @brief Pencarian linear untuk menemukan key di linked list.
  * @param head Pointer ke node pertama.
  * @param key  Nilai yang dicari.
  * @return true jika key ditemukan, false jika tidak.
  *
  * Kompleksitas: O(n) waktu, O(1) ruang tambahan.
  */
 bool searching(const Node *head, int key) {
     const Node *curr = head;
     while (curr != nullptr) {
         if (curr->data == key) {
             return true;
         }
         curr = curr->next;
     }
     return false;
 }
 
 /**
  * @brief Menghitung dan mencetak panjang linked list.
  * @param head Pointer ke node pertama.
  *
  * Kompleksitas: O(n) waktu, O(1) ruang tambahan.
  */
 void length_LinkedList(const Node *head) {
     std::size_t length = 0;
     for (const Node *curr = head; curr != nullptr; curr = curr->next) {
         ++length;
     }
     std::cout << "Panjang linked list: " << length << '\n';
 }
 
 /**
  * @brief Menyisipkan node baru di depan (sebagai head baru).
  * @param head Pointer ke head saat ini (boleh nullptr).
  * @param data_baru Nilai yang akan disisipkan.
  * @return Pointer ke head baru.
  *
  * Kompleksitas: O(1) waktu, O(1) ruang tambahan.
  */
 Node *InsertionAtFront(Node *head, int data_baru) {
     Node *new_node = new Node(data_baru);
     new_node->next = head;
     return new_node;  // new node menjadi head baru
 }
 
 /**
  * @brief Menyisipkan node baru di akhir (sebagai tail baru).
  * @param head Pointer ke head saat ini (boleh nullptr).
  * @param data_baru Nilai yang akan disisipkan.
  * @return Pointer ke head (sama seperti input) atau node baru jika sebelumnya kosong.
  * 
  * Kompleksitas: O(n) waktu (tanpa pointer tail), O(1) ruang tambahan.
  */
 Node *InsertionAtEnd(Node *head, int data_baru) {
     Node *new_node = new Node(data_baru);
 
     // Jika list kosong, node baru menjadi head & tail
     if (head == nullptr) {
         return new_node;
     }
 
     Node *last = head;
     while (last->next != nullptr) {
         last = last->next;
     }
     last->next = new_node;
     return head;
 }
 /**
  * @brief Menyisipkan node baru di pos tertentu
  * @param head Pointer ke head saat ini
  * @param data nilai yang akan disisipkan
  * @return pointer head
  */
 Node* InsertionSpecPos(Node* head,int pos,int data){
    if(pos < 1){
        return head;
    }
    //jika pos  = head,maka ubah data menjadi head = insertAtFront
    if(pos == 1){
        Node* curr = new Node(data);    
        curr->next = head;
        return curr;
    }

    Node* curr = head;

    //traverse sampai pos - 1
    for(int i = 0;i < pos - 1 && curr != nullptr;i++){
        curr = curr->next;
    }
    //jika posisi curr melebihi jumlah element node
    if(curr == nullptr){
        return head;
    }

    Node* new_node = new Node(data); 
    new_node->next = curr->next;
    curr->next = new_node;
    return head;   
 }
/**
 * @brief Deletion Node di pos Front atau head
 * @param temp untk menyimpn nilai head sementara
 * @param delete untuk menghapus node temp(head sebelumnya)
 * @return kembalian head yang baru
 */
Node* DeletionAtFront(Node* head){
    //jika list kosong
    if(head == nullptr){
        return nullptr;
    }
    //untuk track head,
    Node* temp = head;
    //head menunjuk ke node berikutnya
    head = head->next;
    //hapus temp(head sebelumnya)
    delete temp;
    //return head
    return head;
}
/**
 * @brief deletian Node di dari belakang
 * @param second_last unruk menyimpan node terakhir kedua
 * @return head
 */
Node* DeletionAtEnd(Node* head){
    //cek jika list kosong
    if(head == nullptr){
        return nullptr;
    }
    //cek jika list hanya memiliki 1 elemnt saja
    if(head->next == nullptr){
        delete head;
        return nullptr;
    }
    //buat Node baru untuk track dua node terakhir
    Node* second_last = head;
    while(second_last->next->next != nullptr){
        second_last = second_last->next;
    }
    //hapus dua node terakhir
    delete second_last->next;
    //node terakhir adalah nullptr
    second_last->next = nullptr;
    //kembalikan head
    return head;
}
 int main() {
     // Manual: 2 -> 3 -> 4
     Node *head = new Node(2);
     head->next = new Node(3);
     head->next->next = new Node(4);
 
     //std::cout << std::boolalpha << "Cari 3? " << searching(head, 3) << '\n';
     //insertionAtFront
     head = InsertionAtFront(head, 1); // 1 -> 2 -> 3 -> 4
     //insertionAtEnd
     head = InsertionAtEnd(head, 5);   // 1 -> 2 -> 3 -> 4 -> 5
     //traversal_linkedList(head);
     int data = 6,pos = 2;
     //insertionAtSpecPos
     head = InsertionSpecPos(head,pos,data); // 1 -> 6 -> 2 -> 3 -> 4 -> 5
     length_LinkedList(head);
     traversal_linkedList(head);
     std::cout << "deletion at front!" << std::endl;
     head = DeletionAtFront(head);
     length_LinkedList(head);
     traversal_linkedList(head);
     std::cout << "deletion at end!" << std::endl;
     head = DeletionAtEnd(head);
     length_LinkedList(head);
     traversal_linkedList(head);
    //  std::cout << "deletion at front!" << std::endl;
    //  head = DeletionAtFront(head);
    //  length_LinkedList(head);
    //  traversal_linkedList(head);
     std::cin.get();
     return 0;
 }
 