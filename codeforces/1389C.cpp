#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int find_lis(int x, int y, string &s) {
  int sz = s.size();
  bool odd = true;
  int ans = 0;
  for (int i = 0; i < sz; i++) {
    int c = (int)(s[i] - '0');
    if (odd) {
      if (c == x) {
        ans++;
        odd = 1 - odd;
      }
    } else {
      if (c == y) {
        ans++;
        odd = 1 - odd;
      }
    }
  }
  if (!odd)
    ans--;
  return ans;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    vector<pair<int, int>> count_chars(10, {0, 0});
    vector<pair<int, int>> even_count_chars(10, {0, 0});
    vector<pair<int, int>> odd_count_chars(10, {0, 0});
    int sz = s.size();
    for (int i = 0; i < sz; i++) {
      int digit = (s[i] - '0');
      count_chars[digit].first++;
      count_chars[digit].second = digit;
      if (i % 2 == 0) {
        even_count_chars[digit].first++;
        even_count_chars[digit].second = digit;
      } else {
        odd_count_chars[digit].first++;
        odd_count_chars[digit].second = digit;
      }
    }
    sort(count_chars.rbegin(), count_chars.rend());
    int sol = sz - count_chars[0].first;
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        int counter = sz - find_lis(i, j, s);
        sol = min(sol, counter);
      }
    }
    cout << sol << '\n';
  }
  return 0;
}
