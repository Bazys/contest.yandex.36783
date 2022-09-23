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
  std::map<int, int> counter;
  for (auto& el : numbers) {
    counter[el]++;
  }
  int res{0};
  for (auto const& [key, val] : counter) {
    if (val > 1) {
      res += val - 1;
    }
  }
  return res;
}

int main() {
  freopen("input.txt", "r", stdin);
  int n{0};
  scanf("%d", &n);
  if (n == 1) {
    printf("0\n");
    return 0;
  }
  std::vector<int> numbers(n);
  for (auto& el : numbers) {
    int num{0};
    scanf("%d", &num);
    el = num % 200;
  }
  printf("%lld\n", getNumberOfGoodPairs(numbers));
  return 0;
}
