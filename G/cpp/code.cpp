#include <iostream>
#include <vector>

using namespace std;

struct Vertex {
  int w;
  int p;

  Vertex(int w, int p) : w(w), p(p) {}
};

/**
 * @brief Дано укоренённое дерево на N вершинах и число X.
 * В каждой вершине записано число — её вес. Назовём восходящим путь
 * ai,p(ai),p(p(ai)),..., где p(a) — родитель вершины a. Проще говоря,
 * восходящий путь — это путь, который начинается с некоторой вершины и
 * двигается в сторону корня (не обязательно доходя до него). Путь может
 * состоять из одной вершины. Весом пути назовём суммарный вес вершин на
 * этом пути. Найдите количество восходящих путей с весом X.
 * @param tree
 * @param x
 * @return int
 */
int getNumberOfUpgoingPaths(vector<Vertex> tree, int x) {
  int n = tree.size();
  int count = 0;

  for (int i = 0; i < n; i++) {
    int sum = tree[i].w;
    int j = i;

    while (sum < x && j != 0) {
      j = tree[j].p;
      sum += tree[j].w;
    }

    if (sum == x) {
      count++;
    }
  }

  return count;
}

vector<Vertex> readTree(int n) {
  vector<Vertex> tree;
  for (int i = 0; i < n; i++) {
    int parent, weight;
    cin >> parent >> weight;
    tree.push_back(Vertex(weight, parent));
  }
  return tree;
}

int main() {
  int n;
  cin >> n;
  int x;
  cin >> x;
  vector<Vertex> tree = readTree(n);
  cout << getNumberOfUpgoingPaths(tree, x);
}
