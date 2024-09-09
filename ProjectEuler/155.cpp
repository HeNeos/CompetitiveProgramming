#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using si = short int;

#define C 1
#define N 20

set<pair<si, si>> D[N];
set<pair<si, si>> ans;

void generate_capacitance(si n) {
  for (si sub_level = (n + 1) / 2; sub_level < n; sub_level++) {
    for (auto c : D[sub_level]) {
      for (auto cc : D[n - sub_level]) {
        pair<si, si> s = {cc.first * c.second + cc.second * c.first,
                          cc.second * c.second};
        si g = __gcd(s.first, s.second);
        D[n].insert({s.first / g, s.second / g});
        si product = cc.first * c.first;
        g = __gcd(product, s.first);
        D[n].insert({product / g, s.first / g});
      }
    }
  }
  for (auto c : ans)
    D[n].erase(c);
}

int main() {
  D[1].insert({C, 1});
  ans.insert({C, 1});
  si n;
  cin >> n;
  if (n == -1 or n > 18)
    n = 18;
  for (si i = 2; i <= n; i++) {
    generate_capacitance(i);
    for (auto c : D[i]) {
      ans.insert(c);
    }
  }
  cout << ans.size() << '\n';
  return 0;
}
