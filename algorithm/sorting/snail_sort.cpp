#include <iostream>
#include <unordered_map>
#include <vector>

using std::cout;
using std::pair;
using std::vector;

using Matrix = vector<vector<int>>;

vector<int> snail_sort(const Matrix& mat) {
  if (mat.empty() || mat.at(0).empty()) return {};

  auto redirect = [](pair<int, int> delta) -> pair<int, int> {
    if (delta == pair{0, 1}) return {-1, 0};   // right to bottom
    if (delta == pair{-1, 0}) return {0, -1};  // bottom to left
    if (delta == pair{0, -1}) return {1, 0};   // left to top
    return {0, 1};                             // go to right again
  };

  int n = mat.size();
  int m = mat.at(0).size();

  Matrix marker(n, vector<int>(m));
  vector snail = {mat.at(0).at(0)};

  pair pos = {0, 0};
  pair delta = {0, 1};

  while (snail.size() < (n * m)) {
    auto [x, y] = pos;
    auto [dx, dy] = delta;
    auto [next_x, next_y] = pair{x + dx, y + dy};

    auto left_right = (next_x < 0 || next_x >= n);
    auto up_down = (next_y < 0 || next_y >= n);

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

void print_vec(const vector<int>& vec) {
  cout << "{";
  for (auto x : vec) {
    cout << x << ", ";
  }
  cout << "}\n";
}

int main(void) {
  Matrix matrix1 = {
      {1, 2, 3, 4, 5},
      {6, 7, 8, 9, 10},
      {11, 12, 13, 14, 15},
      {16, 17, 18, 19, 20},
      {21, 22, 23, 24, 25},
  };

  Matrix matrix2 = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9},
  };

  vector snail1 = snail_sort(matrix1);
  vector snail2 = snail_sort(matrix2);

  print_vec(snail1);
  print_vec(snail2);
}