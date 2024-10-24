/**
 * @brief class chaining hash dengan modulus tertentu
 */
#include <cstdlib>
#include <iostream>
#include <memory>
#include <ostream>
#include <vector>
class chaining_hash {
private:
  /**
   * @brief mendifinisikan sebuah node yang terhubung
   */
  using Node = struct Node {
    // data yang akan disimpan ke dalam node
    int data{};
    // pointer ke node berikutnya
    std::shared_ptr<struct Node> next;
  };

  // array node
  std::vector<std::shared_ptr<Node>> kepala;
  // modulus dari kelas ini
  int _modulus;

public:
  /**
   * @brief membuat object chaining baru
   * @param modulus modulus chaining
   */
  explicit chaining_hash(int modulus) : _modulus(modulus) {
    // inisialisasi setiap elemen vektor `kepala` dengan nullptr
    while (modulus--) {
      kepala.push_back(nullptr);
    }
  }

  /**
   * @brief membuat dan menambahkan node baru dengan niali tertentu di indeks
   *      tertentu
   * @param nilai nilai node baru
   * @param indeks indeks dari node
   */
  void tambah(int nilai, int indeks) {
    std::shared_ptr<Node> curr;
    std::shared_ptr<Node> temp(new Node);
    temp->data = nilai;
    temp->next = nullptr;

    // jika chaining pada indeks kosong, tambahkan node baru
    if (!kepala[indeks]) {
      kepala[indeks] = temp;
      curr = kepala[indeks];
    } else {
      curr = kepala[indeks];
      while (curr->next) {
        curr = curr->next;
      }
      curr->next = temp;
    }
  }

  void tampilkan() {
    std::shared_ptr<Node> temp = nullptr;
    for (int i = 0; i < _modulus; i++) {
      if (!kepala[i]) {
        std::cout << "key " << i << " kosong!" << std::endl;
      } else {
        std::cout << "key " << i << " memiliki nilai = " << std::endl;
        temp = kepala[i];
        // tampilkan semua elemen di chaining
        while (temp->next) {
          std::cout << temp->data << " " << std::endl;
          temp = temp->next;
        }
        std::cout << temp->data << std::endl;
      }
    }
  }

  /**
   * @brief menghitung hash dari sebuah nilai
   * @param nilai nilai untuk dihitung modulusnya
   * @return modulus dari nilai tersebut
   */
  virtual int hash(int nilai) const { return nilai % _modulus; }

  /**
   * @brief mencari apakah nilai dari hashnya ada di rantai
   *
   * @param nilai nilai yang ingin dicari
   * @param indeks hash dari nilai tersebut
   * @return `true` jika elemen ditemukan
   * @return `false` jika elemen tidak ditemukan
   */
  bool cari(int nilai, int indeks) const {
    std::shared_ptr<Node> temp = kepala[indeks];
    if (!kepala[indeks]) {
      std::cout << "elemen tidak ditemukan" << std::endl;
      return false;
    }

    while (temp->data != nilai && temp->next) {
      temp = temp->next;
    }

    if (temp->next) {
      std::cout << "elemen ditemukan" << std::endl;
      return true;
    }

    if (temp->data == nilai) {
      std::cout << "elemen ditemukan" << std::endl;
      return false;
    }

    std::cout << "elemen tidak ditemukan" << std::endl;
    return false;
  }
};

int main() {
  int pilihan = 0, nilai = 0, modulus = 0, indeks = 0;
  std::cout << "masukan ukuran tabel hash = " << std::endl;
  std::cin >> modulus;

  chaining_hash chainingHash(modulus);

  bool loop = true;
  while (loop) {
    std::cout << std::endl;
    std::cout << "1. tambah elemen" << std::endl;
    std::cout << "2. cari elemen" << std::endl;
    std::cout << "3. hasilkan hash" << std::endl;
    std::cout << "4. tampilkan table hash" << std::endl;
    std::cout << "5. exit" << std::endl;
    std::cin >> pilihan;

    switch (pilihan) {
    case 1:
      std::cout << "masukkan elemen untuk ditambahkan = " << std::endl;
      std::cin >> nilai;
      // hitung hash dari elemen
      indeks = chainingHash.hash(nilai);
      // pastikan indeks positif
      indeks = std::abs(indeks);
      // tambahkan elemen ke rantai
      chainingHash.tambah(nilai, indeks);
      break;
    case 2:
      std::cout << "masukkan elemen untuk dicari = " << std::endl;
      std::cin >> nilai;
      // hitung hash dari elemen
      indeks = chainingHash.hash(nilai);
      // cari elemen di rantai
      chainingHash.cari(nilai, indeks);
      break;
    case 3:
      std::cout << "masukkan elemen untuk menghasilkan hash = " << std::endl;
      std::cin >> nilai;
      std::cout << "hash dari " << nilai
                << " adalah = " << chainingHash.hash(nilai) << std::endl;
      break;
    case 4:
      // tampilkan isi tabel hash
      chainingHash.tampilkan();
      break;
    default:
      loop = false;
      break;
    }
    std::cout << std::endl;
  }
  return 0;
}
