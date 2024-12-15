#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define N 100000000
#define MAXN 100000005
const int MOD = 1000000009;

ll fastexp(ll x, ll y, int p) {
  ll ans = 1;
  while (y > 0) {
    if (y & 1)
      ans = (ans * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return ans % p;
}

bitset<MAXN> is_prime;
vector<int> primes;
void sieve(int n) {
  int primes_count = 0;
  for (int i = 2; i < n; i++) {
    if (!is_prime[i]) {
      primes.push_back(i);
      primes_count++;
      for (ll j = 1LL * i * i; j < n; j += i)
        is_prime[j] = 1;
    }
  }
}

int extract_power(int n, int p) {
  int exponent = 0;
  while (n) {
    n /= p;
    exponent += n;
  }
  return exponent;
}

vector<pair<int, int>> get_factorization(int n) {
  vector<pair<int, int>> factorization;
  for (auto prime : primes) {
    if (prime > n)
      break;
    int exponent = extract_power(n, prime);
    factorization.push_back({prime, exponent});
  }
  return factorization;
}

int get_polynomial_factor(pair<int, int> factor) {
  return 1 + fastexp(factor.first, 2 * factor.second, MOD);
}

ll solve(int n) {
  vector<pair<int, int>> factorization = get_factorization(n);
  ll ans = 1;
  for (auto factor : factorization) {
    int multiplicator = get_polynomial_factor(factor);
    ans *= multiplicator;
    ans %= MOD;
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  if (n == -1)
    n = N;
  n = min(n, N);
  sieve(n);
  cout << solve(n) << '\n';
  return 0;
}