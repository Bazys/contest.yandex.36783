#include <iostream>
#include <map>

/**
 * Цифры ’I’, ’X’, ’C’ и ’M’ нельзя использовать более трех раз подряд. Цифры
 * ’V’, ’L’ и ’D’ нельзя использовать более одного раза во всей записи числа.
 * @param s std::string число римскими цифрами
 * @return bool корректная ли строка
 */
bool checkCorrect(const std::string& s) {
  std::map<char, int> check;
  char prevC = '0';
  int prev{1};
  for (int i = 0; i < s.size(); ++i) {
    if ((s[i] == 'I' || s[i] == 'X' || s[i] == 'C' || s[i] == 'M') &&
        s[i] == prevC) {
      prev++;
      if (prev > 3) {
        return false;
      }
    }
    if (s[i] == 'V' || s[i] == 'L' || s[i] == 'D') {
      check[s[i]]++;
      if (check[s[i]] > 1) {
        return false;
      }
    }
    prevC = s[i];
  }
  return true;
}

int convertToArabic(const std::string& s) {
  std::map<char, int> r2a{{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                          {'C', 100}, {'D', 500}, {'M', 1000}};
  int res{0};
  for (int i = 0; s[i]; i++) {
    if (s[i + 1] &&
        r2a[s[i]] < r2a[s[i + 1]]) {  // сначала проверятся следующий символ
      res += r2a[s[i + 1]] - r2a[s[i]];  // по определению
      i++;
    } else {  // пропустить этот символ
      res += r2a[s[i]];
    }
  }
  return res;
}

int main() {
  std::string romanNumber;
  std::cin >> romanNumber;
  if (!checkCorrect(romanNumber)) {
    printf("-1\n");
    return 0;
  }
  printf("%d\n", convertToArabic(romanNumber));
  return 0;
}
