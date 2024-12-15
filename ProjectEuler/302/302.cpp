#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vii = vector<pii>;
using vvii = vector<vii>;

#define N 630000
#define MAXN 1000000000000000000

vector<int> p;
int lpf[N];
void sieve() {
  for (int i = 2; i < N; i++) {
    if (!lpf[i]) {
      lpf[i] = i;
      p.push_back(i);
      for (ll j = 1LL * i * i; j < N; j += i) {
        if (lpf[j] == 0)
          lpf[j] = i;
      }
    }
  }
}

vii factorization(int n) {
  vii ans;
  while (n != 1) {
    int d = lpf[n];
    int counter = 0;
    while (n % d == 0) {
      n /= d;
      counter++;
    }
    ans.push_back({d, counter});
  }
  return ans;
}

ll number_strong_achiles = 0;

void solve(int n, vii &factors, ll value, int gcd, int last_prime) {
  if (n == factors.size()) {
    if (gcd == 1) {
      unordered_map<int, int> totient;
      for (int i = 0; i < factors.size(); i++) {
        pii factor = factors[i];
        totient[factor.first] += factor.second - 1;
        vii f = factorization(factor.first - 1);
        for (auto v : f)
          totient[v.first] += v.second;
      }
      int totient_gcd = 0;
      bool is_strong = false;
      for (auto v : totient) {
        if (v.second == 1) {
          is_strong = false;
          break;
        }
        totient_gcd = __gcd(totient_gcd, v.second);
        if (totient_gcd == 1)
          is_strong = true;
      }
      if (is_strong) {
        number_strong_achiles++;
      }
    }
    return;
  }
  for (int i = last_prime + 1; i < p.size(); i++) {
    ll p_e = p[i];
    if (value > (double)1. * MAXN / p_e / p[i])
      break;
    for (int exponent = 2;; exponent++) {
      if (value > (double)1. * MAXN / p_e / p[i])
        break;
      p_e *= p[i];
      int new_gcd = __gcd(gcd, exponent);
      factors.push_back({p[i], exponent});
      solve(n, factors, value * p_e, new_gcd, i);
      factors.pop_back();
    }
  }
}

void solve() {
  for (int different_factors = 2; different_factors < 9; different_factors++) {
    vii factors;
    solve(different_factors, factors, 1, 0, -1);
  }
}

int main() {
  sieve();
  solve();
  cout << number_strong_achiles << '\n';
  return 0;
}