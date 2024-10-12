#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

namespace backtracking {
namespace wildcard_matching {
std::vector<std::vector<int64_t>> dpTable(1000, std::vector<int64_t>(1000, -1));
bool wildcard_matching(std::string s, std::string p, uint32_t pos1,
                       std::uint32_t pos2) {
  uint32_t n = s.length();
  uint32_t m = p.length();
  if (pos1 == n && pos2 == m) {
    return true;
  }
  if (pos1 != n && pos2 == m) {
    return false;
  }
  if (pos1 == n && pos2 != m) {
    while (pos2 < m && p[pos2] == '*') {
      pos2++;
    }

    return pos2 == m;
  }
  if (dpTable[pos1][pos2] != -1) {
    return dpTable[pos1][pos2];
  }
  if (s[pos1] == p[pos2]) {
    return dpTable[pos1][pos2] = wildcard_matching(s, p, pos1 + 1, pos2 + 1);
  }

  else {
    if (p[pos2] == '?') {
      return dpTable[pos1][pos2] = wildcard_matching(s, p, pos1 + 1, pos2 + 1);
    } else if (p[pos2] == '*') {
      return dpTable[pos1][pos2] = wildcard_matching(s, p, pos1, pos2 + 1) ||
                                   wildcard_matching(s, p, pos1 + 1, pos2);
    } else {
      return dpTable[pos1][pos2] = 0;
    }
  }
}

} // namespace wildcard_matching
} // namespace backtracking

static void test() {
  std::cout << "1st test ";
  std::string matching1 = "baaabab";
  std::string pattern1 = "*****ba*****ab";
  assert(backtracking::wildcard_matching::wildcard_matching(matching1, pattern1,
                                                            0, 0) == 1);
  std::cout << "passed" << std::endl;

  std::cout << "2nd test ";
  std::string matching2 = "baaabab";
  std::string pattern2 = "ba*****ab";
  assert(backtracking::wildcard_matching::wildcard_matching(matching2, pattern2,
                                                            0, 0) == 1);
  std::cout << "passed" << std::endl;

  std::cout << "3rd test ";
  std::string matching3 = "baaabab";
  std::string pattern3 = "ba*ab";
  assert(backtracking::wildcard_matching::wildcard_matching(matching3, pattern3,
                                                            0, 0) == 1);
  std::cout << "passed" << std::endl;

  std::cout << "4th test ";
  std::string matching4 = "baaabab";
  std::string pattern4 = "a*ab";
  assert(backtracking::wildcard_matching::wildcard_matching(matching4, pattern4,
                                                            0, 0) == 1);
  std::cout << "passed" << std::endl;

  std::cout << "5th test ";
  std::string matching5 = "baaabab";
  std::string pattern5 = "aa?ab";
  assert(backtracking::wildcard_matching::wildcard_matching(matching5, pattern5,
                                                            0, 0) == 1);
  std::cout << "passed" << std::endl;
}

int main() {
  test();
  return 0;
}
