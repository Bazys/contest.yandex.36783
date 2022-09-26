#include <iostream>
#include <stack>

std::string makeGood(const std::string& s) {
  if (s.size() == 1) return s;
  std::string res{""};
  auto n = s.size();

  std::stack<char> st;
  for (int i = 0; i < n; i++) {
    if (!st.empty()) {
      if (abs((st.top() - s[i])) == 32) {
        st.pop();
        continue;
      }
    }
    st.push(s[i]);
  }

  while (st.size()) {
    res.push_back(st.top());
    st.pop();
  }

  reverse(res.begin(), res.end());
  return res;
}

int main() {
  std::string probablyBadString;
  std::cin >> probablyBadString;
  std::cout << makeGood(probablyBadString);
}
