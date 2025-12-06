#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string read_line() {
  string line;
  getline(cin, line);
  return line;
}

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

bool is_valid(vector<pair<ll, ll>> ranges, ll id) {
  for (auto range : ranges) {
    if (id >= range.first and id <= range.second)
      return true;
  }
  return false;
}

int main() {
  string s;
  vector<pair<ll, ll>> ranges;
  while (true) {
    s = read_line();
    if (s == "")
      break;
    vector<string> range = split(s, '-');
    ranges.push_back(make_pair(stoll(range[0]), stoll(range[1])));
  }

  int ans = 0;
  ll id;
  while (cin >> id) {
    if (is_valid(ranges, id))
      ans++;
  }
  cout << ans << '\n';
  return 0;
}
