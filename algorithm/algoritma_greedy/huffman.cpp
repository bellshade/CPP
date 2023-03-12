/**
 * huffman coding adalah sebuah tipe koding yang
 * optimal yang biasanya digunakan untuk lossless
 * data compression
 * kode huffman lebih cepat 45% dibandingkan
 * kode dari ASCII.
 */
#include <iostream>
#include <queue>

// huffman pohon node
struct MinHeapNode {
    // input karakter
    char data;
    // frekuensi dari karakter
    unsigned frekuensi;
    // kiri dan kanan node child
    MinHeapNode *kanan, *kiri;

    MinHeapNode(char data, unsigned frekuensi) {
        kiri = kanan = NULL;
        this->data = data;
        this->data = frekuensi;
    }
};

// untuk membandingkan antara
// heap node
struct komparasi {
    bool operator()(MinHeapNode *kiri, MinHeapNode *kanan) {
        return (kiri->frekuensi > kanan->frekuensi);
    }
};

// menampilkan kode huffman dari
// root pohon huffman
void printKode(struct MinHeapNode *root, std::string str) {
    if (!root) {
        return;
    }

    if (root->data != '$')
        std::cout << root->data << ":" << str << "\n";

    printKode(root->kiri, str + "0");
    printKode(root->kanan, str + "1");
}

/**
 * bangun pohon huffman dan menampilkan kode dengan
 * melintasi pohon huffman yang dibagun
 */
void KodeHuffman(char data[], int frekuensi[], int ukuran) {
    struct MinHeapNode *kiri, *kanan, *atas;

    // membuat min heap dan memasukkan semua karakter ke dalam data[]
    std::priority_queue<MinHeapNode *, std::vector<MinHeapNode *>, komparasi>
        minHeap;
    for (int i = 0; i < ukuran; ++i)
        minHeap.push(new MinHeapNode(data[i], frekuensi[i]));

    // looping ketika ukuran heap tidak menjadi 1
    while (minHeap.size() != 1) {
        kiri = minHeap.top();
        minHeap.pop();

        kanan = minHeap.top();
        minHeap.pop();

        // buat simpul internal baru dengan frekuensi sama
        // dengn jumlah dua node.
        // buat juga dua simpil yang diekstrasi sebagai child kiri
        // dan kana dan node baru ini, maka ditambahkan simpul ini
        // ke min heap "$" adalah nilai khusus untuk kode internal
        atas = new MinHeapNode('$', kiri->frekuensi + kanan->frekuensi);
        atas->kiri = kiri;
        atas->kanan = kanan;
        minHeap.push(atas);
    }

    // tampilkan kode huffman
    // menggunakan pohon huffman
    // yang sebelumnya sudah dibuat
    printKode(minHeap.top(), "");
}

// jalankan semua fungsi
int main() {
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int frekuensi[] = {5, 9, 12, 13, 16, 45};

    int ukuran = sizeof(arr) / sizeof(arr[0]);

    KodeHuffman(arr, frekuensi, ukuran);
    return 0;
}
