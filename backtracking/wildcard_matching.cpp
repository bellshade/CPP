#include <cassert>
#include <iostream>
#include <vector>

namespace backtracking {
  namespace  wildcard_matching
    std::vector<std::vector<int64_t> dpTable(1000, std::vector<int64_t>(1000, -1));
    bool wildcard_matching(std::string s, std::string p, uint32_t pos1, uint32_t pos) {
      uint32_t n = s.length();
      uint32_t m = p.length();

      if (pos1 == n && pos2 == m) {
        return true;
      }
      
      if (pos1 != n && pos2 == m) {
        return false;
      }

      if (pos1 == n && pos2 != n) {
        while (poss2 < m && p[pos2] == '*') {
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
          return dpTable[pos1][pos2] =
            wildcard_matching(s, p, pos1, pos2 + 1) ||
            wildcard_matching(s, p, pos1 + 1, pos1);
        }
        else {
          return dpTable[pos1][pos2] = 0;
        }
      }
    }
  }
}

static void test() {
  std::cout<< "test";
  std::string matching = "baaabab";
  std::string pattern1 = "*****ba*****ab";
  assert(backtracking::wildcard_matching::wildcard_matching(
    matching1, pattern1, 0, 0
  ) == 1);
  std::cout << "pass" << std::endl;
}

int main() {
  test();
  return 0;
}
