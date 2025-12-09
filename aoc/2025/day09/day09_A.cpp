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

int main() {
  string s;
  ll ans = 0;
  vector<pair<ll, ll>> points;
  while (cin >> s) {
    vector<string> line = split(s, ',');
    ll x = stoll(line[0]);
    ll y = stoll(line[1]);
    points.push_back({x, y});
  }
  for (int i = 0; i < points.size(); i++) {
    for (int j = i + 1; j < points.size(); j++) {

      ll area = (abs(points[i].first - points[j].first) + 1) *
                (abs(points[i].second - points[j].second) + 1);
      ans = max(area, ans);
    }
  }
  cout << ans << '\n';
  return 0;
}
