# binary search tree

binary search tree (BST) adalah struktur data yagn mengadopsi konsep binary tree namun terdapat aturan bahwa setiap child node sebelah kiri selalu lebih kecil nilainya daripada root node. begitu pula sebaliknya setiap child node sebelah kanan selalu lebih besar nilainya daripada root node.

tujuan untuk membedakan kiri dan kanan sesuai besaran nilainya, ialah untuk memberikan efisiensi terhadap proses searching. kalau struktur data tree sudah tersusun rapi sesuai dengan aturanya, maka proses search akan lebih cepat

contoh dari binary search tree
- setiap child node sebelah kiri harus lebih kecil nilainya daripada root nodenya.
- setiap child node sebelah kanan harus lebih besar nilai daripada root nodenya

**ada 3 jenis cara untuk melakukan penulusuran data pada bst**

- preOrder: print data, telusur ke kiri, telusur ke kanan
- inOrder: telusur ke kiri, print data telusur ke kanan
- postOrder: telusur ke kiri, telusur ke kanan, print data
