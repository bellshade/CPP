#include <algorithm>
#include <cmath>
#include <iostream>
#include <array>
namespace backtracking {
template <size_t T>
int minimax(int depth, int node_index, bool is_max,
            const std::array<int, T> &scores, double height) {
    if (depth == height) {
        return scores[node_index];
    }

    int v1 = minimax(depth + 1, node_index * 2, !is_max, scores, height);
    int v2 = minimax(depth + 1, node_index * 2 + 1, !is_max, scores, height);

    return is_max ? std::max(v1, v2) : std::min(v1, v2);
}
} 
int main() {
    std::array<int, 8> scores = {90, 23, 6, 33, 21, 65, 123, 34423};
    double height = log2(scores.size());

    std::cout << "Optimasi value: " << backtracking::minimax(0, 0, true, scores, height)
              << std::endl;
    return 0;
}