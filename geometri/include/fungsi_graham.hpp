#include <cstdint>
#include <cstdlib>
#include <stack>
#include <utility>
#include <vector>
namespace geometri {
namespace graham_scan {
struct Titik {
  // koordinat x dan y
  int x, y;
};

// sebuah titik global yang dibutuhkan untuk mengurutkan titik
// dengan referensi ke titik pertama. digunakan nantinya dalam
// fungsi compare() dan qsort()
Titik titik_awal;

/**
 * @brief fungsi utilitis untuk mendapatkan elemen kedua dari atas pada stack
 * @param S stack yang digunakan dalam proses ini
 * @return @param titik koordinat dari Titik <int, int>
 */
Titik elemenKeduaDariAtas(std::stack<Titik> *S) {
  // ambil elemen teratas dari stack
  Titik p = S->top();
  // keluarkan elemen teratas dari stack
  S->pop();
  // ambil eleme kedua dari atas
  Titik hasil = S->top();
  // masukkan kembali elemen yang tadi dikeluarkan
  S->push(p);
  // return elemen kedua dari atas
  return hasil;
}

/**
 * @brief fungsi utilitis untuk menghitung kuadrat jarak antara dua titik
 * @param t1 koordinat Titik 1 <int, int>
 * @param t2 koordinat Titik 2 <int, int>
 * @return @param int jarak kuadrat antara t1 dan t2
 */
int jarakKuadrat(Titik t1, Titik t2) {
  return (t1.x - t2.x) * (t1.x - t2.x) + (t1.y - t2.y) * (t1.y - t2.y);
}

/**
 * @brief fungsi untuk menentukan orientasi triplet terurut (p, q, r)
 * @param p koordinat Titik p <int, int>
 * @param q koordinat Titik q <int, int>
 * @param r koordinat Titik r <int, int>
 * @return @param int 0 --> p, q, dan r segaris, 1 --> searah jarum jam
 *         2 -> berlawanan arah jarum jam
 */
int orientasi(Titik p, Titik q, Titik r) {
  int nilai = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

  if (nilai == 0) {
    // jika collinear
    return 0;
  }

  // searah atau berlawanan arah jarum jam
  return (nilai > 0) ? 1 : 2;
}

/**
 * @brief fungsi yang digunakan oleh fungsi lib qsort() untuk
 *        mengurutkan array titik-titik dengan referensi pada
 *        titik pertama
 * @param t1 koordinat Titik 1 <int, int>
 * @param t2 koordinat Titik 2 <int, int>
 * @return @param int jarak antara t1 dan t2
 */
int bandingkan(const void *t1, const void *t2) {
  // konversi tipe titik
  auto *p1 = static_cast<const Titik *>(t1);
  auto *p2 = static_cast<const Titik *>(t2);

  // tentukan orientasi
  int o = orientasi(titik_awal, *p1, *p2);
  if (o == 0) {
    return (jarakKuadrat(titik_awal, *p2) >= jarakKuadrat(titik_awal, *p1)) ? -1
                                                                            : 1;
  }

  return (o == 2) ? -1 : 1;
}

/**
 * @brief mencetak convek hull dari kumpulan n titik
 * @param titik-titik vektor dari titik-titik <int, int> dengan koordinat
 * @param ukuran ukuran dari vektor
 * @return @param vector vektor dari convek hull
 */
std::vector<Titik> convexHull(std::vector<Titik> titik_titik,
                              std::uint64_t ukuran) {
  // temukan titik terbawah
  int y_minimum = titik_titik[0].y, minimum = 0;
  for (int i = 1; i < ukuran; i++) {
    int y = titik_titik[i].y;

    // pilih tiitk terbawah atau pilih titik paling kiri jika ada ikatan
    if ((y < y_minimum) ||
        (y_minimum == y && titik_titik[i].x < titik_titik[minimum].x)) {
      y_minimum = titik_titik[i].y;
      minimum = i;
    }
  }

  // tempatkan titik terbawah pada posisi pertama
  std::swap(titik_titik[0], titik_titik[minimum]);

  // urutukan titik-titik dengan referensi pada titik pertama
  titik_awal = titik_titik[0];
  qsort(&titik_titik[1], ukuran - 1, sizeof(Titik), bandingkan);

  // jika ada beberapa titik yang memliki sudut yang sama, hanya simpan titik
  // terjauh

  // inisialisasi ukuran array yang dimodifikasi
  int m = 1;
  for (int i = 1; i < ukuran; i++) {
    // hapus titik jika sudutnya sama dengan titik berikutnya
    while (i < ukuran - 1 &&
           orientasi(titik_awal, titik_titik[i], titik_titik[i + 1]) == 0) {
      ++i;
    }

    titik_titik[m] = titik_titik[i];
    // memperbarui ukuran array yang dimodifikasi
    m++;
  }

  // jik ada kurang dari 3 titik, convex hull tidak mungkin
  if (m < 3) {
    return {};
  }

  // buat stack kosong dan masukan tiga titik pertama dalamnya
  std::stack<Titik> St;
  St.push(titik_titik[0]);
  St.push(titik_titik[1]);
  St.push(titik_titik[2]);

  // proses sisa titik
  for (int i = 3; i < m; i++) {
    // hapus elemen teratas jika sudut yang terbentuk oleh elemen
    // ledua dari atas, elemen teratas, dan titik[i]
    // membuat putaran yang bukan ke kiri
    while (St.size() > 1 &&
           orientasi(elemenKeduaDariAtas(&St), St.top(), titik_titik[i]) != 2) {
      St.pop();
    }
    St.push(titik_titik[i]);
  }

  std::vector<Titik> hasil;
  // pindahkan titik_titik dari stack ke vektor hasil
  while (!St.empty()) {
    Titik p = St.top();
    hasil.push_back(p);
    St.pop();
  }

  // return vektor hasil dengan koordinat convek hull
  return hasil;
}

} // namespace graham_scan
} // namespace geometri
