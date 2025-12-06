#include <bits/stdc++.h>
using namespace std;

int max_from_position(vector<int> &v, int p, bool take_last = false) {
  int value = v[p];
  int position = p;
  for (int i = p; i < v.size(); i++) {
    if (!take_last and i == v.size() - 1)
      continue;
    if (v[i] > value) {
      position = i;
      value = v[i];
    }
  }
  return position;
}

int main() {
  string s;
  long long out = 0;
  while (cin >> s) {
    vector<int> batteries;
    for (auto c : s)
      batteries.push_back((int)(c - '0'));
    int first_position = max_from_position(batteries, 0, false);
    int second_position =
        max_from_position(batteries, first_position + 1, true);

    int first_digit = batteries[first_position];
    int second_digit = batteries[second_position];
    int ans = first_digit * 10 + second_digit;
    out += ans;
  }
  cout << out << '\n';
  return 0;
}
