#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

#define N 1000000000000
#define MAXN 1000000

int lpf[MAXN + 5];
void sieve() {
  for (int i = 2; i < MAXN + 5; i++) {
    if (!lpf[i]) {
      lpf[i] = i;
      for (ll j = 1LL * i * i; j < MAXN + 5; j += i) {
        if (lpf[j] == 0)
          lpf[j] = i;
      }
    }
  }
}

vector<pii> get_factorization(int n) {
  vector<pii> factorization;
  while (n > 1) {
    int d = lpf[n];
    int c = 0;
    while (n % d == 0) {
      n /= d;
      c++;
    }
    factorization.push_back(make_pair(d, c));
  }
  return factorization;
}

int next_square(int n) {
  vector<pii> factorization = get_factorization(n);
  ll ans = 1;
  for (auto factor : factorization) {
    if (factor.second % 2 == 1) {
      ans *= factor.first;
    }
  }
  return ans;
}

unordered_set<ll> s;
void fill() {
  for (int i = 1; i < MAXN; i++) {
    s.insert(1LL * i * i + i);
  }
  for (int r = 1; r < MAXN; r++) {
    ll d = next_square(r);
    ll q = sqrt(1LL * r * d);
    for (int m = 1;; m++) {
      ll new_q = q * m;
      ll new_d = d * m * m;
      if (new_d < r + 1 or new_q < r + 1 or new_q > new_d)
        continue;
      ll n = 1LL * new_d * new_q + r;
      if (n > N)
        break;
      s.insert(n);
    }
  }
}

int main() {
  sieve();
  fill();
  ll ans = 0;
  for (auto x : s) {
    ll sq = sqrt(x);
    if (sq * sq == x) {
      ans += x;
    }
  }
  cout << ans << '\n';
  return 0;
}