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
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("trapv")
#pragma GCC target("sse4")

#include <cmath>
#include <iostream>
#include <vector>

using ll = long long;

ll getNumberOfGoodPairs(const std::vector<ll>& numbers) {
  auto n = numbers.size();
  ll res{0};
  if (n > 0) {
    for (auto i = 0; i < n; ++i) {
      for (auto j = i + 1; j < n; ++j) {
        if (abs(numbers[i] - numbers[j]) % 200 == 0) {
          res++;
        }
      }
    }
  }
  return res;
}

int main() {
  int n;
  scanf("%d", &n);
  std::vector<ll> numbers(n);
  for (auto& el : numbers) {
    scanf("%lld", &el);
  }
  printf("%lld\n", getNumberOfGoodPairs(numbers));
}
