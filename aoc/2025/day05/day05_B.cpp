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

vector<pair<ll, ll>> merge_ranges(vector<pair<ll, ll>> ranges) {
  if (ranges.empty())
    return {};

  sort(ranges.begin(), ranges.end());

  vector<pair<ll, ll>> merged;
  merged.push_back(ranges[0]);

  for (size_t i = 1; i < ranges.size(); i++) {
    auto &last = merged.back();
    auto &curr = ranges[i];

    if (curr.first <= last.second) {
      last.second = max(last.second, curr.second);
    } else {
      merged.push_back(curr);
    }
  }

  return merged;
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
  auto merged_ranges = merge_ranges(ranges);
  unsigned long long ans = 0;
  for (auto range : merged_ranges) {
    ans += range.second - range.first + 1;
  }
  cout << ans << '\n';
  return 0;
}
