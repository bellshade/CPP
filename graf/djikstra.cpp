#include <cassert>
#include <cstdint>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <ostream>
#include <queue>
#include <utility>
#include <vector>

// buat nilai maksimum dari int64_t
const std::int64_t TAK_TERHINGGA = std::numeric_limits<std::int64_t>::max();

namespace graf {
/**
 * @brief fungsi untuk menambah sisi antara dua node atau vertex pada graf
 * @param u salah satu node atau vertex pada graf
 * @param v node atau vertex lainnya pada graf
 * @param berat boobot dari edge antara node u dan v
 */
void tambahEdge(std::vector<std::vector<std::pair<int, int>>> *adj, int u,
                int v, int berat) {
  // tambah sisi dari node u ke node v dengan bobot tertentu
  (*adj)[u - 1].push_back(std::make_pair(v - 1, berat));
}

/**
 * @brief fungsi yang menjalankan algoritma djikstra untuk menemukan jarak
 *          terpendek dari vertex sumber ke vertex tujuan di graf
 * @param adj graf dalam bentuk adjacency list
 * @param s vertex sumbera
 * @param t vertex tujuan
 * @return jarak terpendek jika vertex tujuan dapat dijangkau dari vertex
 * sumber, jika tidak bisa dijangkau, akan return -1
 */
int djikstra(std::vector<std::vector<std::pair<int, int>>> *adj, int s, int t) {
  // n mewakili jumlah vertex pada graf
  int n = adj->size();
  // insialisasi ajark dengan nilai TAK_TERHINGGA
  std::vector<std::int64_t> jarak(n, TAK_TERHINGGA);

  // membuat min heap menggunakan priority queue
  // elemen pertama dari pair adalah jarak, elemen kedua adalah vertex
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      std::greater<std::pair<int, int>>>
      pq;

  // tambahin vertex sumber dengan jarak 0 ke dalam priority_queue
  pq.push(std::make_pair(0, s));

  // tandai jarak dari sumber ke dirinya sendiri adalah 0
  jarak[0] = 0;

  // selama min heap tidak kosong, maka eksplorasi vertex
  while (!pq.empty()) {
    // elemen kedua dari pair adalah vertex yang di eksplorasi
    int simpulSaatIni = pq.top().second;
    // elemen pertama dari pair adalah jarak
    int jarakSaatIni = pq.top().first;

    // mengeluarkan simpul dari antrian
    pq.pop();

    // untuk setiap vertex yang terhubung dari simpul saat ini, kita coba untuk
    // update jarak
    for (std::pair<int, int> edge : (*adj)[simpulSaatIni]) {
      // jika jarak yang lebih pendek ditemukan , perbarui jarak dan masukkan
      // vertex ke dalam heap
      if (jarakSaatIni + edge.second < jarak[edge.first]) {
        jarak[edge.first] = jarakSaatIni + edge.second;
        pq.push(std::make_pair(jarak[edge.first], edge.first));
      }
    }
  }

  // jika jarak ke vertex tujuan tidak terhingga, return jarak
  if (jarak[t] != TAK_TERHINGGA) {
    return jarak[t];
  }

  // jika tidak dapat dijangkau
  return -1;
}
} // namespace graf

void testing() {
  std::vector<std::vector<std::pair<int, int>>> adj1(
      4, std::vector<std::pair<int, int>>());

  // tambahin edge dengan bobot tertentu

  graf::tambahEdge(&adj1, 1, 2, 1);
  graf::tambahEdge(&adj1, 4, 1, 2);
  graf::tambahEdge(&adj1, 2, 3, 2);
  graf::tambahEdge(&adj1, 1, 3, 5);

  int sumber = 1, tujuan = 3;
  assert(graf::djikstra(&adj1, sumber - 1, tujuan - 1) == 3);
  std::cout << "testing pass..." << std::endl;
}

int main() {
  testing();

  int JumlahVertex = 0, jumlahEdge = 0;
  std::cout << "masukkan jumlah vertex: ";
  std::cin >> JumlahVertex;
  std::cout << "jumlah edge: ";
  std::cin >> jumlahEdge;

  std::vector<std::vector<std::pair<int, int>>> adj(
      JumlahVertex, std::vector<std::pair<int, int>>());

  // input edge dari user
  int u = 0, v = 0, berat = 0;
  while (jumlahEdge--) {
    std::cin >> u >> v >> berat;
    graf::tambahEdge(&adj, u, v, berat);
  }

  // input vertex sumber dan tujuan
  int sumber = 0, tujuan = 0;
  std::cin >> sumber >> tujuan;

  // jalankan algoritma djikstra
  int jarak = graf::djikstra(&adj, sumber - 1, tujuan - 1);
  if (jarak == -1) {
    std::cout << "tujuan tidak dapat dijangkau dari sumber" << std::endl;
  } else {
    std::cout << "jarak terpendek: " << jarak << std::endl;
  }

  return 0;
}
