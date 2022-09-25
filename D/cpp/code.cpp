#include <iostream>
#include <vector>

using vi = std::vector<int>;

bool canMove(int i, int j, int n, int m) {
  return i >= 0 && j >= 0 && i < n && j < m;
}

int dfs(const std::vector<vi> &matrix, int i, int j, int n, int m,
        std::vector<vi> &distances) {
  if (!canMove(i, j, n, m)) {  // проверка, можем ли перейти в зту ячейку.
    return 0;
  }
  if (distances[i][j] !=
      -1) {  // если эту ячейку уже посещали, возвращаем результат
    return distances[i][j];
  }
  int res = 1;
  int dx[4] = {-1, 1, 0, 0};  // массивы координат, куда можем перемещаться
  int dy[4] = {0, 0, -1, 1};
  for (int k = 0; k < 4; k++) {  // перебираем 4 направления
    int newi = i + dx[k];
    int newj = j + dy[k];
    if (canMove(newi, newj, n,
                m)) {  // проверка, можем ли перейти в зту ячейку.
      if (matrix[newi][newj] > matrix[i][j] &&  // возрастающий путь
          distances[i][j] <
              distances[newi][newj] + 1) {  // новый путь длиннее чем старый
        res =
            std::max(res, dfs(matrix, newi, newj, n, m, distances) + 1);  // dfs
      }
    }
  }
  return distances[i][j] = res;
}

int getLongestIncreasingPath(const std::vector<vi> &matrix) {
  int n = matrix.size();
  int m = matrix[0].size();
  std::vector<vi> distances(n, vi(m, -1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
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
