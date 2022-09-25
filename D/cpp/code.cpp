#include <iostream>
#include <vector>

using vi = std::vector<int>;

bool canMove(int i, int j, size_t n, size_t m) {
  return i >= 0 && j >= 0 && i < n && j < m;
}

int dfs(const std::vector<vi> &matrix, int i, int j, size_t n, size_t m,
        std::vector<vi> &distances) {
  // проверка, можем ли перейти в зту ячейку.
  if (!canMove(i, j, n, m)) {
    return 0;
  }
  // если эту ячейку уже посещали, возвращаем результат
  if (distances[i][j] != -1) {
    return distances[i][j];
  }
  int res = 1;
  // массивы координат, куда можем перемещаться
  int dx[4] = {-1, 1, 0, 0};
  int dy[4] = {0, 0, -1, 1};
  // перебираем 4 направления
  for (int k = 0; k < 4; k++) {
    int newi = i + dx[k];
    int newj = j + dy[k];
    // проверка, можем ли перейти в зту ячейку.
    if (canMove(newi, newj, n, m)) {
      if (matrix[newi][newj] > matrix[i][j] &&  // возрастающий путь
          distances[i][j] <
              distances[newi][newj] + 1) {  // новый путь длиннее чем старый
        // запускаем dfs там где еще не было
        res = std::max(res, dfs(matrix, newi, newj, n, m, distances) + 1);
      }
    }
  }
  return distances[i][j] = res;
}

int getLongestIncreasingPath(const std::vector<vi> &matrix) {
  auto n = matrix.size();  // для совместимости с LeetCode
  auto m = matrix[0].size();
  std::vector<vi> distances(n, vi(m, -1));
  for (auto i = 0; i < n; i++) {
    for (auto j = 0; j < m; j++) {
      dfs(matrix, i, j, n, m, distances);
    }
  }
  int ans = 1;

  for (auto &row : distances) {
    for (auto &el : row) {
      ans = std::max(ans, el);
    }
  }
  return ans;
}

int main() {
  // freopen("input.txt", "r", stdin);
  int n, m;
  scanf("%d %d", &n, &m);
  std::vector<vi> matrix(n, vi(m));
  for (auto &row : matrix) {
    for (auto &el : row) {
      scanf("%d", &el);
    }
  }
  printf("%d\n", getLongestIncreasingPath(matrix));
  return 0;
}
