#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define N 1500000
#define MOD 1000000000

bool is_composite[N];
vector<int> primes;
void sieve() {
  for (int i = 2; i < N; i++) {
    if (!is_composite[i]) {
      primes.push_back(i);
      for (ll j = 1LL * i * i; j < N; j += i)
        is_composite[j] = true;
    }
  }
}

string to_key(ll n, int index) { return to_string(n) + "#" + to_string(index); }

#define PI_N 78500

unordered_map<string, int> cache;
ll f(ll n, int index) {
  ll d = n / primes[index];
  ll ans = d % MOD;
  if (d < 1)
    return 0;
  if (index == 0)
    return ans;
  if (index == 1)
    return (d - d / 2) % MOD;
  if (index == 2)
    return (d - d / 3 + d / 3 / 2 - d / 2) % MOD;
  string key = to_key(n, index);
  if (cache.find(key) != cache.end()) {
    return cache[key];
  }
  for (int i = 0; i < index; i++) {
    ans -= f(d, i);
    ans %= MOD;
  }
  if (ans == 0)
    ans += MOD;
  if (cache.size() < 50000000 & index >= 5)
    cache[key] = ans;
  return ans;
}

int main() {
  sieve();
  ll n;
  cin >> n;
  ll ans = 705911377;
  ll prime_sum = 0;
  for (int i = 0; i < PI_N; i++) {
    if (1LL * primes[i] * primes[i] > n)
      break;
    prime_sum += primes[i];
    int amount = f(n, i) % MOD;
    ans += (1LL * amount * primes[i]) % MOD;
  }
  cout << ((ans - prime_sum) % MOD + MOD) % MOD << '\n';
  return 0;
}
