
#include "include/fungsi_graham.hpp"
#include <cassert>
#include <iostream>
#include <vector>

/**
 * @brief fungsi testing dari graham scan
 * @return void
 */
static void testing() {
  // deklarasi vektor `titik_titik`yang menyimpan
  // beberapa titik dengan koordinat (x, y)
  std::vector<geometri::graham_scan::Titik> titik_titik = {
      {0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};

  // deklarasi vektor `hasil_ekspetasi` yang menyimpan hasil
  // yang diharapkan dari convex hull
  std::vector<geometri::graham_scan::Titik> hasil_ekspetasi = {
      {0, 3}, {4, 4}, {3, 1}, {0, 0}};

  // deklarasi vektor `hasil_terhitung` yang menyimpan hasil dari
  // perhitungan convex hull
  std::vector<geometri::graham_scan::Titik> hasil_terhitung;

  // memanggil fungsi convex hull dengan argumen `titik_titik` dengan ukuran
  // vektor `titik_titik`
  hasil_terhitung =
      geometri::graham_scan::convexHull(titik_titik, titik_titik.size());

  // menampilkan hasil uji yang pertama{0, 3}, {4, 4}, {3, 1}, {0, 0}
  std::cout << "testing pertama: ";

  // looping untuk memeriksa apakah hasil yang diharapkan sama dengan hasil yang
  // akan dihitung
  for (int i = 0; i < hasil_ekspetasi.size(); i++) {
    assert(hasil_terhitung[i].x == hasil_ekspetasi[i].x);
    assert(hasil_terhitung[i].y == hasil_ekspetasi[i].y);
  }

  std::cout << "testing pass !" << std::endl;
}

int main() {
  testing();
  return 0;
}
