## Daftar Isi
1. [Traversal of Singly Linked List](#traversal-of-singly-linked-list)
2. [Searching in Singly Linked List](#searching-in-singly-linked-list)
3. [Length of Singly Linked List](#length-of-singly-linked-list)
4. [Insertion in Singly Linked List](#insertion-in-singly-linked-list)
5. [Deletion (front, back, spec pos)](#deletion)
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
**time complexity = O(n),Auxiliary Space O(1)**


![gambar_traversel_inked_list](img/traversal.png)


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
**time complexity = O(n),Auxiliary Space O(1)**


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
**time complexity = O(n),Auxiliary Space O(1)**


<!-- konten bab 3 -->

## Insertion in Singly Linked List
`Insert`(memasukkan) adalah operasi untuk menyisipkan atau menambahkan nilai dalam sebuah linked list,dalam praktiknya kita mengenai 3 insertion yaitu `InsertionAtFront`(insertion didepan),`InsertionAtEnd`(Insertion diakhir),dan `InsertionSpecPosition`(insertion di posisi tertentu),nah kita akan membahas ketiganya
### 1.InsertionAtFront
`Insertion At front` berarti kita menyisipkan nilai dari depan,dengan kata lain nilai yang kita insert akan menjadi element paling pertama,pada array kita melakukan operasi ini dengan menggeser nilai lainnya kekanan,di linked list alih-alih melakukan itu kita justru membuat node baru dan menghubungkannya dengan node head.(lihat gambar)


![gambar_insertiom](img/InsertionAtFront.png)


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
**time complexity = O(1),Auxiliary Space O(1)**


### 2.InsertionAtEnd
`Insertion At End` berarti kita menyisipkan nilai dari belakang,dengan menyisipkan dari belakang maka nilai yang kita sisipkan akan menjadi tail(element terakhir),karena penunjuk saat diloop tidak tereset saat iterasi berakhir maka kita dapat memanfaatkan ini untuk menyisipkan nilai dari belakang


![gambar_insertiom](img/InsertionAtEnd.png)


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
**time complexity = O(n),Auxiliary Space O(1)**


nah,jika kita melihat metode insertion sebelumnya,pada `inserrt at front` kita mengembalikan new_node sementara pada saat `insert at end` kita malah mengembalikan head,nah itu dikarenakan semua operasi yang kita selanjutnya kita wajib mengembalikan pointer `head`,pada operasi At Front kita menyisipkan nilai yang nantinya akan menjadi head,makanya kita mengembalikan new_node
### 3.Insertion at a Specific Position(Soon)


Ide utama untuk melakukan Insertion di posisi tertentu
1.buat node baru sebagai pointer penunjuk(misal `curr`)
2.Buat node baru untuk menampung nilai(misal `new_node`)
3.Traverse(looping) linked list sampai `node` posisi - 1
4.Simpan sementara node setelah curr ke new_node->next → new_node->next = curr->next.
5.Sambungkan `curr->next` ke `new_node` → `curr->next = new_node`.  
6.return `head`

anda dapat melihat visualisasinya dibawah ![dibawah](img/Insertion-at-a-Specific-Position-o.jpg)



```cpp
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
```
**time complexity = O(n),Auxiliary Space O(1)**


jika pos < 1,kita dapat mengatakan bahwa pos invalid,maka dari itu kita mengembalikan
head,jika pos = 1,kita tau yg mengisi pos 1 adalah head,jika kita ingin mengisi di pos 1 maka
konsep nya sama dengan kita melakukan InsertionAtFront,setelah semua exception diatas,kita melakukan
traverse(loop) sampai pos node -1,itu untuk tujuannya agar mengerakkan Node Poiner Penunjuk(`curr`)
sampai pada posisi node sebelum diinsert.

jika curr(pointer penunjuk) saat ini adalah nullpointer maka kita dapat menyatakan bahwa pos
berada diluar list,tp tidak seperti ketika pos == 1 kita dapat melakukan insertion at front,untuk kondisi ini
kita tidak dapat langsung menganggap ini sebagai insert at end
karena:


-  kita tidak mengetahui apa `pos` tepat **setelah node terakhir**(pos = panjang list + 1)
misal kita punya 3 posisi node
- atau pos melebihi batas list misal (misal `pos == 10` untuk list dengan 3 node)

dalam kondisi ini,kita tidak dapat menjamin keamanan insert,ketika melakukan InsertAtEnd ketika `curr = nullptr`
akan menyebabkan segmentation fault,maka kembalikan head dan abaikan operasi.
```cpp
1->2->3->null
```
Jika pos == 5, kita tidak tahu apakah harus insert setelah 3, atau apakah ini hanya kesalahan input. Maka lebih baik menghindari insert dan mengembalikan list seperti semula.


nah lanjut sudah dipastikan **pos valid**,maka kita buat node baru misal `new_node` untuk menampung data yang ingin di insert lalu,new_node-> next = curr->next atau dengan kArtinya, node setelah new_node adalah node yang sebelumnya berada setelah `curr`.sekarang tinggal hubungkan node sebelum (`curr`) ke new_node dengan `curr->next = new_node`,Dengan ini, node baru telah berhasil disisipkan di antara `curr` dan `curr->next`.
<!-- konten bab 4 -->
## Deletion
sama seperti Insertion,Deletion(menhapus Node) juga memiliki 3 metode yaitu:
### 1.DeletionAtFront
DeletionAtFront atau menghapus Node dari depan(head),memiliki beberapa ide utama antara lain:

1.Buat `Node` baru untuk menyimpan nilai head(misal `temp`)
2.Buat `head` menunjuk node selanjutnya (`head = head->next`)
3.Hapus temp(head sebelumnya) dengan `delete temp`
4.kembalikan `head` yang baru
```cpp
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
```
**time complexity = O(1),Auxiliary Space O(1)**


pertama cek apakah head adalah nullptr,dengan `head == null` ptr dapat dipastikan
bahwa list ini kosong maka kembalikan nullptr,jika list bukan null ptr kita buat
node baru misal `temp` untuk menyimpan nilai head lama(Head yang akan dihapus),lalu
pindahkan head ke node selanjutnya dengan `head = head->next`,setelah itu hapus Node
temp berisi nilai Node `head yag lama` untuk menghindari **memory leak**,dan yang terakhir kembalikan head yang baru.

### 2.DeletionAtEnd
<p align="justify">
Deletion at End, atau penghapusan node dari belakang, berarti kita akan menghapus node terakhir dalam linked list, yaitu node tepat sebelum penunjuk <code>nullptr</code>. Untuk melakukannya, terdapat beberapa langkah utama:
<ol>
<li>Buat pointer penunjuk, misalnya <code>second_last</code>, yang akan digunakan untuk melacak node kedua terakhir.</li>
<li>Lakukan traversal hingga mencapai node kedua terakhir.</li>
<li>Hapus node terakhir menggunakan <code>delete second_last-&gt;next</code>.</li>
</ol>
</p>


```cpp
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
```
**time complexity = O(n),Auxiliary Space O(1)**


langkah pertama yang kita lakukan adalah mengecek apakah `list kosong`,jika iya kembalikan `nullptr`
lalu cek juga apakah list hanya memiliki 1 `Node` jika iya kembalikan nullptr,jika semua exception diatas
tidak memenuhi baru kita dapat melakukan `deletionAtEnd`,langkah pertama yang dilakukan membuat Node baru
misal `second_last` sebagai pointer penunjuk dan untuk mentrack Node kedua terakhir ,lalu lakukan loop dengan while sampai pada element kedua terakhir,hapus Node setelah kedua terakhir dengan second_last->next.Lalu Buat Node
Second_last menunjuk `Node` berikutnya yaitu `Nullptr`
