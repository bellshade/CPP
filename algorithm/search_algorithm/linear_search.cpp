#include <algorithm>
#include <array>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

void clearScreen() {
#ifdef _WIN32
  std::system("cls");
#else
  std::system("clear");
#endif // DEBUG
}

/*sumber crud dan saya memodifikasi sedikit
https://gist.github.com/nihitx/1f56c129b35c992d35ba9c11647d2721
karena program ini fokus ke implementasi linear search bukan membuat crud maka
penjelesan nya hanya fokus ke linear search
*/
bool SearchName(std::vector<std::string> &nama, std::string &DataNama) {
  // looping melalui vektor `nama` untuk mencari kecocokan dengan input pengguna
  for (const auto &name : nama) {
    if (DataNama == name) {
      return true;
    }
  }
  return false;
}

bool SearchBook(const std::vector<std::string> &buku,
                const std::string &DataBuku) {
  // looping melalui vektor `buku` untuk mencari buku berdasarkan input
  for (const auto &book : buku) {
    if (DataBuku == book) {
      return true;
    }
  }
  return false;
}

bool LinearSearch(const std::vector<std::string> &bookarray,
                  const std::string &data) {
  // looping melalui vektor `bokarray` untuk searching buku berdasarkan input
  for (const auto &book : bookarray) {
    if (data == book) {
      return true;
    }
  }
  return false;
}

int main() {
  char choice;
  int pilihan;
  std::string data, DataNama, DataBuku, bookname, removebook, authorname,
      fullbook;
  std::vector<std::string> bookarray, nama, buku;
  int countnum;

  do {
    clearScreen();
    std::cout << "a. tambah buku" << std::endl;
    std::cout << "b. hapus buku" << std::endl;
    std::cout << "c. kosongkan database" << std::endl;
    std::cout << "d. tampillkan jumlah buku" << std::endl;
    std::cout << "e. tampilkan semua buku" << std::endl;
    std::cout << "f. cari buku" << std::endl;
    std::cout << "g. keluar" << std::endl;
    std::cin >> choice;

    if (choice == 'g') {
      std::cout << "close program" << std::endl;
    } else {
      switch (choice) {
      case 'a':
        std::cout << "masukkan judul buku: ";
        std::cin >> bookname;
        buku.push_back(bookname);

        std::cout << "masukkan nama penulis: ";
        std::cin >> authorname;
        nama.push_back(authorname);

        fullbook = bookname + " " + authorname;
        bookarray.push_back(fullbook);
        std::cout << "buku berhasil ditambah" << std::endl;
        break;

      case 'b':
        std::cout << "masukkan judul buku yang ingin dihapus: ";
        std::cin >> removebook;
        for (auto it = bookarray.begin(); it != bookarray.end(); ++it) {
          if (it->find(removebook) != std::string::npos) {
            bookarray.erase(it);
            std::cout << "buku berhasil dihapus" << std::endl;
            break;
          }
        }
        break;
      case 'c':
        bookarray.clear();
        std::cout << "database telah dikosongkan" << std::endl;
        break;

      case 'd':
        countnum = bookarray.size();
        std::cout << "jumlah buku dalam database: " << countnum << std::endl;
        break;

      case 'e':
        std::cout << "daftar buku dalam database: " << std::endl;
        for (size_t i = 0; i < bookarray.size(); ++i) {
          std::cout << i + 1 << ". " << bookarray[i] << std::endl;
        }
        break;

      case 'f':
        std::cout << "1. cari buku berdasarkan nama penulis" << std::endl;
        std::cout << "2. cari buku berdasarkan nama buku" << std::endl;
        std::cout << "3. cari buku berdasarkan judul dan penulis" << std::endl;
        std::cin >> pilihan;

        switch (pilihan) {
        case 1:
          std::cout << "masukkan nama penulis: ";
          std::cin >> DataNama;
          if (SearchName(nama, DataNama)) {
            std::cout << "data penulis ditemukan" << std::endl;
          } else {
            std::cout << "data penulis tidak ditemukan" << std::endl;
          }
          break;

        case 2:
          std::cout << "masukkan nama buku: ";
          std::cin >> DataBuku;
          if (SearchBook(buku, DataBuku)) {
            std::cout << "data buku ditemukan" << std::endl;
          } else {
            std::cout << "data buku tidak ditemukan" << std::endl;
          }
          break;

        case 3:
          std::cout << "masukkan judul atau penulis buku: ";
          std::cin >> data;
          if (LinearSearch(bookarray, data)) {
            std::cout << "data buku ditemukan" << std::endl;
          } else {
            std::cout << "data buku tidak ditemukan" << std::endl;
          }
          break;

        default:
          std::cout << "pilihan tidak valid" << std::endl;
          break;
        }
        break;

      default:
        std::cout << "pilihan tidak valid" << std::endl;
        break;
      }
    }
  } while (choice != 'g');
  return 0;
}
