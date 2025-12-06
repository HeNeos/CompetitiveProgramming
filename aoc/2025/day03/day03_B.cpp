#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int max_from_position(vector<int> &v, int p, int right_padding) {
  int value = v[p];
  int position = p;
  for (int i = p; i < v.size() - right_padding; i++) {
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
    int position = 0;
    vector<int> number_digits;
    for (int i = 11; i >= 0; i--) {
      int next_position = max_from_position(batteries, position, i);
      int digit = batteries[next_position];
      number_digits.push_back(digit);
      position = next_position + 1;
    }
    ll number = 0;
    for (auto digit : number_digits) {
      number *= 10;
      number += digit;
    }
    out += number;
  }
  cout << out << '\n';
  return 0;
}
