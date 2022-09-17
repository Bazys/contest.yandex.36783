/**
 * Вам дан массив натуральных чисел ai. Найдите число таких пар элементов
 * (ai,aj), где ∣ai − aj∣%200==0 и i<j.
 * Формат ввода
 * В первой строке дан размер массива n(1≤n≤200_000).
 * Во второй строке через пробел записаны элементы массива ai(1≤ai≤10^9).
 * Формат вывода
 * Выведите единственное число — количество пар, подходящих под указанное выше
 * условие.
 */
#include <iostream>
#include <vector>

using namespace std;

long long getNumberOfGoodPairs(int n, const vector<int>& numbers) {
  // your code goes here
  return 0;
}

int readInt() {
  int x;
  cin >> x;
  return x;
}

vector<int> readList(int n) {
  vector<int> res(n);
  for (int i = 0; i < n; i++) {
    cin >> res[i];
  }
  return res;
}

int main() {
  int n = readInt();
  vector<int> numbers = readList(n);
  cout << getNumberOfGoodPairs(n, numbers);
}
