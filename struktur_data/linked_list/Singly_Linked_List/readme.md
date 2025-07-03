## Daftar Isi
1. [Traversal of Singly Linked List](#traversal-of-singly-linked-list)
2. [Searching in Singly Linked List](#searching-in-singly-linked-list)
3. [Length of Singly Linked List](#length-of-singly-linked-list)
4. [Insertion in Singly Linked List](#insertion-in-singly-linked-list)
5. Deletion (front, back, spec pos) — *coming soon*
6. Modify Linked List — *coming soon*
7. Reversing Linked List — *coming soon*

---

## Traversal of Singly Linked List
<!-- konten bab 1 -->
`Traversal`, atau iterasi, adalah operasi yang menjelajahi setiap elemen dalam suatu struktur data. Pada linked list, traversal berarti mengunjungi setiap node satu per satu dari head(node pertama) hingga tail(node terakhir).


ide utama untuk melakukan traversal di linked list
1. Inisialisasi pointer salinan `curr` yang menunjuk `head`.
2. Ulangi dengan `while` selama `curr != nullptr`.
3. Proses data di node saat ini (mis. `print`, hitung, ubah, dsb.).
4. Geser pointer: `curr = curr->next`.
```cpp


void traversal_linkedList(Node* head){
    //membuat salinan pointer,agar head asli tidak bergeser saat iterasi
    Node* curr = head;
    while(curr != nullptr){ 
        std::cout << curr->data << " ";
        //pointer penunjut bergerak ke node selanjutnya

        curr = curr->next;
    }
    std::cout<<std::endl;
}
```
time complexity = O(n),Auxiliary Space O(1)


![gambar_traversel_inked_list](struktur_data/linked_list/Singly_Linked_List/img/traversal.png)
Iterasi pada linked-list dilakukan dengan menggerakkan pointer kerja (misalnya. `curr`) dari head hingga elemen terakhir; sepanjang proses, pointer head sendiri tidak pernah bergeser, sehingga setelah loop selesai (ketika curr sudah nullptr) Anda tetap memiliki pegangan utuh ke daftar—dan, jika sebelumnya menyimpan pointer ke node terakhir (tail), Anda bisa langsung menambah simpul baru di ujung (insert-at-end) tanpa perlu menelusuri ulang dari awal.
## Searching in Singly Linked List
`Searching (pencarian)` adalah operasi untuk menemukan nilai tertentu dalam struktur data. Pada singly linked list, metode yang lazim dipakai adalah linear search: kita menelusuri node dari head ke tail sampai data cocok atau daftar habis. Algoritmanya O(n) waktu dan O(1) ruang. Binary search tidak praktis di linked list karena tidak ada akses acak ke elemen tengah.


ide utama searching pada linked list
1.  inisialisasi node pointer(misal `curr`)
2.  lakukan traversal     
    - jika element sekarang sama dengan key(`curr->data = key`) maka return `true`
    - jika tidak gerakkan node pointer ke element selanjutnya(`curr = curr->next`)
3.  jika key tidak ditemukan maka return `false`
```cpp
bool searching(Node *head,int cari){
    Node* curr = head;
    while(curr != nullptr){
        if(curr->data == cari){
            return true;
        }   
        curr = curr->next;
    }
    return false;
}
```
time complexity = O(n),Auxiliary Space O(1)


<!-- konten bab 2 -->

## Length of Singly Linked List
`length(panjang)` dari sebuah linked list adalah banyaknya Node atau element dalam struktur data linked list,ini penting agar kita dapat mengolah data dengan efisien.


ide utama untuk mendapatkan panjang dari linked list
1. inisialisasi sebuah counter untuk menampung nilai(misal `length = 0`)
2. buat pointer penunjuk(misal `curr`)
3. lakukan iterasi sampai `tail`(node terakhir)
4. tiap iterasi increment(naikkan) counter += 1
5. gerakkan pointer ke element selanjutnya(`curr = curr->next`)
```cpp
void lenght_LinkedList(Node* head){
    Node* curr = head;
    int lenght = 0;
    while(curr != nullptr){
        lenght++;
        curr = curr->next;
    }
    std::cout << "panjang linked list: " << lenght << std::endl;
}
```
time complexity = O(n),Auxiliary Space O(1)


<!-- konten bab 3 -->

## Insertion in Singly Linked List
`Insert`(memasukkan) adalah operasi untuk menyisipkan atau menambahkan nilai dalam sebuah linked list,dalam praktiknya kita mengenai 3 insertion yaitu `InsertionAtFront`(insertion didepan),`InsertionAtEnd`(Insertion diakhir),dan `InsertionSpecPosition`(insertion di posisi tertentu),nah kita akan membahas ketiganya
### 1.InsertionAtFront
`Insertion At front` berarti kita menyisipkan nilai dari depan,dengan kata lain nilai yang kita insert akan menjadi element paling pertama,pada array kita melakukan operasi ini dengan menggeser nilai lainnya kekanan,di linked list alih-alih melakukan itu kita justru membuat node baru dan menghubungkannya dengan node head.(lihat gambar)
![gambar_insertiom](struktur_data/linked_list/Singly_Linked_List/img/InsertionAtFront.png)


ide utama untuk melakukan insertion dari depan
1. buatlah node baru(misal new_data) untuk dijadikan head yang baru sekaligus menyimpan nilai
2. hubungkan node(new_data->next = head) tersebut ke head
3. kembalikan pointer node yang kita buat(return new_data);
```cpp
Node* InsertionAtFront(Node* head,int data_baru){
    Node* new_node = new Node(data_baru);
    
    new_node->next = head;
    
    return new_node;
}
```
time complexity = O(1),Auxiliary Space O(1)


### 2.InsertionAtEnd
`Insertion At End` berarti kita menyisipkan nilai dari belakang,dengan menyisipkan dari belakang maka nilai yang kita sisipkan akan menjadi tail(element terakhir),karena penunjuk saat diloop tidak tereset saat iterasi berakhir maka kita dapat memanfaatkan ini untuk menyisipkan nilai dari belakang
![gambar_insertiom](struktur_data/linked_list/Singly_Linked_List/img/InsertionAtEnd.png)


ide utama untuk melakukan insertion dari belakang
1. buat Node baru(misal `new_node`) untuk menampung nilai
2. jika head bernilai nullptr berarti linked list kosong maka kembalikan new_node
3. buat pointer penunjuk(misal last)
4. traversal linked list sampai akhir Node(tail)
5. pada saat penunjuk sudah sampai pada tail(node terakhir) maka hubungkan dengan new_node
```cpp
Node* InsertionAtEnd(Node* head,int data_baru){
    Node* new_node = new Node(data_baru);
    //jika linked list kosong
    if(head == nullptr){
        return new_node;
    }
    Node* last = head;

    while(last->next != nullptr){
        last = last->next;
    }

    last->next = new_node;

    return head;
}
```
time complexity = O(n),Auxiliary Space O(1)


nah,jika kita melihat metode insertion sebelumnya,pada `inserrt at front` kita mengembalikan new_node sementara pada saat `insert at end` kita malah mengembalikan head,nah itu dikarenakan semua operasi yang kita selanjutnya kita wajib mengembalikan pointer `head`,pada operasi At Front kita menyisipkan nilai yang nantinya akan menjadi head,makanya kita mengembalikan new_node
### 3.Insertion at a Specific Position(Soon)
<!-- konten bab 4 -->
