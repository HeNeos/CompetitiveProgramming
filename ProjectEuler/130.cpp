#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;

#define N 100000
vi primes;

ll fastexp(ll x, ll y, ll p) {
  ll ans = 1;
  while (y > 0) {
    if (y & 1)
      ans = (ans * x) % p;
    y >>= 1;
    x = (x * x) % p;
  }
  return ans % p;
}

ll inv(ll x, ll p) { return fastexp(x, p - 2, p); }

int phi[N];
void cphi() {
  phi[1] = 1;
  for (int i = 2; i < N; i++) {
    if (!phi[i]) {
      primes.push_back(i);
      phi[i] = i - 1;
      for (ll j = 2 * i; j < N; j += i) {
        if (phi[j] == 0)
          phi[j] = j;
        phi[j] = phi[j] / i * (i - 1);
      }
    }
  }
}

vi get_divisors(int n) {
  vi divisors;
  for (int i = 1; 1LL * i * i <= n; i++) {
    if (n % i == 0) {
      divisors.push_back(i);
      if (n / i != i)
        divisors.push_back(n / i);
    }
  }
  sort(divisors.begin(), divisors.end());
  return divisors;
}

int find_min_repunit_length(int n) {
  vi possible_lengths = get_divisors(phi[n]);
  for (auto length : possible_lengths) {
    if (fastexp(10, length, 9 * n) == 1) {
      return length;
    }
  }
  return -1;
}

int main() {
  cphi();
  int counter = 0;
  ll ans = 0;
  for (int i = 5; i < N and counter < 25; i++) {
    if (phi[i] == i - 1)
      continue;
    if (i % 2 == 0 or i % 5 == 0)
      continue;
    int length = find_min_repunit_length(i);
    if (length == -1)
      continue;
    if ((i - 1) % length == 0) {
      counter++;
      ans += i;
    }
  }
  cout << ans << '\n';
  return 0;
}