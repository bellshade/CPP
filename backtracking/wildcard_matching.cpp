#include <cassert>
#include <cstdint>
#include <functional>
#include <iostream>
#include <vector>

namespace backtracking {
namespace wildcard_matching {

/**
 * @brief wildcard matching - cek apakah string cocok dengan pattern wildcard
 *
 * @param s - referensi ke string input
 * @param p - referensi ke pattern (const&)
 * @return true jika cocok, false jika tidak
 */
bool wildcard_matching(std::string s, std::string p, uint32_t pos1,
                       std::uint32_t pos2) {
  const uint32_t n = static_cast<uint32_t>(s.length());
  const uint32_t m = static_cast<uint32_t>(p.length());
  std::vector<std::vector<int8_t>> dp(n + 1, std::vector<int8_t>(m + 1, -1));

  std::function<bool(uint32_t, uint32_t)> match = [&](uint32_t i,
                                                      uint32_t j) -> bool {
    if (dp[i][j] != -1) {
      return static_cast<bool>(dp[i][j]);
    }

    if (i == n && j == m) {
      return dp[i][j] = true;
    }

    if (i < n && j == m) {
      return dp[i][j] = false;
    }

    if (i == n && j < m) {
      while (j < m && p[j] == '*') {
        ++j;
      }
      return dp[i][j] = (j == m);
    }

    if (s[i] == p[j] || p[j] == '?') {
      return dp[i][j] = match(i + 1, j + 1);
    }

    if (p[j] == '*') {
      return dp[i][j] = (match(i, j + 1) || match(i + 1, j));
    }
    return dp[i][j] = false;
  };

  return match(0, 0);
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
