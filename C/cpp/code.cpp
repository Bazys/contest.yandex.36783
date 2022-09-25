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
#include <map>
#include <vector>

long long getNumberOfGoodPairs(const std::vector<int>& numbers) {
  std::vector<long long> counter(200, 0);
  // получаем количество одинаковых остатков от деления на 200
  for (const int& el : numbers) {
    counter[el % 200]++;
  }
  long long res{0};
  // суммируем количество возможных перестановок пар
  for (const long long& val : counter) {
    res += (val * (val - 1) / 2);
  }
  return res;
}

int main() {
  //  freopen("input.txt", "r", stdin);
  int n{0};
  scanf("%d", &n);
  if (n == 1) {
    printf("0\n");
    return 0;
  }
  std::vector<int> numbers(n);
  for (auto& el : numbers) {
    scanf("%d", &el);
  }
  printf("%lld\n", getNumberOfGoodPairs(numbers));
  return 0;
}
