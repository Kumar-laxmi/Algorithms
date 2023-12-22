#include <cmath>
#include <vector>

std::vector<std::pair<int, int>> getPythagoreanTriples(int n) {
  std::vector<std::pair<int, int>> triples;

  for (int a = 1; a <= n; ++a) {
    for (int b = a + 1; b <= n; ++b) {
      int c = std::sqrt(a * a + b * b);
      if (c <= n && c * c == a * a + b * b) {
        triples.push_back(std::make_pair(a, b));
      }
    }
  }

  return triples;
}
