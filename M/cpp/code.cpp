#include <iostream>
#include <queue>
#include <vector>

using ii = std::pair<int, int>;
using pq = std::priority_queue<ii, std::vector<ii>, std::greater<>>;

struct HistoricalArray {
  int size, eraId;

  std::vector<pq> data;

  HistoricalArray(int n) : size(n) { data = std::vector<pq>(size); }

  void beginNewEra(int era) { eraId = era; }

  void set(int index, int value) { data[index].push({eraId, value}); }

  int get(int index, int eraId) {
    int l{-1}, r;
    r = size;
    ii prev;
    while (l + 1 < r) {
      auto mid = (l + r) / 2;
      if (data[index]...second < version) {
        l = mid;
      } else {
        r = mid;
      }
      prev = data[l];
    }
    return (r < n && ver[r].second <= version) ? ver[r] : prev;

    return -1;
  }
};

int main(int argc, char const *argv[]) {
  int n, q;
  scanf("%d", &n);
  scanf("%d", &q);
  HistoricalArray arr(n);
  for (int i = 0; i < q; i++) {
    std::string queryType;
    std::cin >> queryType;
    if (queryType == "set") {
      int index, value;
      scanf("%d %d", &index, &value);
      arr.set(index, value);
    } else if (queryType == "begin_new_era") {
      int eraId;
      scanf("%d", &eraId);
      arr.beginNewEra(eraId);
    } else if (queryType == "get") {
      int index, eraId;
      scanf("%d %d", &index, &eraId);
      std::cout << arr.get(index, eraId) << std::endl;
    }
  }
}
