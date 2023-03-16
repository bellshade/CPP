#include <iostream>
#include <unordered_map>
#include <vector>

using std::cout;
using std::pair;
using std::vector;

// melakukan alias pada vector<vector<int>> menjadi Matrix
using Matrix = vector<vector<int>>;

vector<int> snail_sort(const Matrix& mat) {
  // mengecek matrix mat
  // jika kosong maka return vector kosong
  if (mat.empty() || mat.at(0).empty()) return {};

  // mengontrol arah pointer
  auto redirect = [](pair<int, int> delta) -> pair<int, int> {
    if (delta == pair<int, int>{0, 1}) return {-1, 0};   // kanan ke bawah
    if (delta == pair<int, int>{-1, 0}) return {0, -1};  // bawah ke kiri
    if (delta == pair<int, int>{0, -1}) return {1, 0};   // kiri ke atas
    return {0, 1};                                       // atas ke kanan
  };

  size_t n = mat.size();

  Matrix marker(n, vector<int>(n));       // matrix untuk mark
  vector<int> snail = {mat.at(0).at(0)};  // hasil dari sorting

  pair<int, int> pos = {0, 0};    // posisi saat ini (pointer)
  pair<int, int> delta = {0, 1};  // arah pointer sekarang

  while (snail.size() < (n * n)) {
    // melakukan binding pada variable yang dibutuhkan (C++17)
    auto [x, y] = pos;
    auto [dx, dy] = delta;
    auto [next_x, next_y] = pair{x + dx, y + dy};

    // mengecek agar posisi (pointer) selanjut nya
    // tidak keluar dari index matrix
    auto left_right = (next_x < 0 || next_x >= n);
    auto up_down = (next_y < 0 || next_y >= n);

    // mengecek mark, jika 1 maka ubah arah pointer (delta)
    // jika 0 masukan posisi selanjut nya ke hasil sorting (snail),
    // mark posisi sekarang menjadi 1 dan ganti posisi sekarang (pos)
    if (left_right || up_down || marker.at(next_x).at(next_y)) {
      delta = redirect(delta);
    } else {
      snail.push_back(mat.at(next_x).at(next_y));
      marker.at(x).at(y) = true;
      pos = {next_x, next_y};
    }
  }

  return snail;
}

// Mencetak vector
void print_vec(const vector<int>& vec) {
  cout << "{";
  for (auto x : vec) {
    cout << x << ", ";
  }
  cout << "}\n";
}

int main(void) {
  // membuat 2 matrix untuk di test
  Matrix matrix1 = {
      {1, 2, 3, 4, 5},      {6, 7, 8, 9, 10},     {11, 12, 13, 14, 15},
      {16, 17, 18, 19, 20}, {21, 22, 23, 24, 25},
  };

  Matrix matrix2 = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9},
  };

  vector<int> snail1 = snail_sort(matrix1);
  vector<int> snail2 = snail_sort(matrix2);

  // cetak hasil sorting
  print_vec(snail1);
  print_vec(snail2);
}