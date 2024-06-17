#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define N 5000
#define MAXN 1600000

bitset<MAXN> is_prime;
vector<int> primes;

#define MOD 10000000000000000

void sieve() {
  int primes_count = 0;
  for (int i = 2; i < MAXN; i++) {
    if (!is_prime[i]) {
      primes.push_back(i);
      primes_count++;
      for (ll j = 1LL * i * i; j < MAXN; j += i)
        is_prime[j] = 1;
    }
  }
}

int main() {
  int n;
  cin >> n;
  if (n == -1)
    n = N;
  n = min(n, N);
  sieve();

  int sum_primes = 0;
  for (auto prime : primes) {
    if (prime > n)
      break;
    sum_primes += prime;
  }

  vector<ll> t(1 + sum_primes, 0);
  t[0] = 1;
  int sum = 0;
  for (auto prime : primes) {
    if (prime > n)
      break;
    sum += prime;
    for (int j = sum; j >= prime; j--)
      t[j] = (t[j] + t[j - prime]) % MOD;
  }
  ll ans = 0;
  for (auto prime : primes) {
    if (prime >= sum_primes)
      break;
    ans += t[prime];
    ans %= MOD;
  }

  cout << ans << '\n';

  return 0;
}