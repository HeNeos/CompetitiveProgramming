#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<string> split(const string &str, char delimiter = ' ') {
  vector<string> words;
  string word;

  for (char ch : str) {
    if (ch == delimiter) {
      if (!word.empty()) {
        words.push_back(word);
        word.clear();
      }
    } else
      word += ch;
  }
  if (!word.empty())
    words.push_back(word);
  return words;
}

bool is_duplicated(ll x) {
  vector<int> digits;
  while (x) {
    int digit = x % 10;
    digits.push_back(digit);
    x /= 10;
  }
  reverse(digits.begin(), digits.end());
  int sz = digits.size();
  if (sz % 2 == 1)
    return false;
  for (int i = 0; i < sz / 2; i++) {
    if (digits[i] != digits[i + sz / 2])
      return false;
  }
  return true;
}

int main() {
  string line;
  cin >> line;
  vector<string> ranges = split(line, ',');
  ll ans = 0;
  for (auto range : ranges) {
    vector<string> values = split(range, '-');
    ll left = stoll(values[0]);
    ll right = stoll(values[1]);
    for (ll x = left; x <= right; x++) {
      if (is_duplicated(x))
        ans += x;
    }
  }
  cout << ans << '\n';
  return 0;
}
