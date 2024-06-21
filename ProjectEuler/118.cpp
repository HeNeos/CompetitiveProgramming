#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define MAXN 10000000

bitset<MAXN> is_prime;
void sieve() {
  int primes_count = 0;
  for (int i = 2; i < MAXN; i++) {
    if (!is_prime[i]) {
      primes_count++;
      for (ll j = 1LL * i * i; j < MAXN; j += i)
        is_prime[j] = 1;
    }
  }
  is_prime[1] = 1;
}

int TestMillerRabin[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

ll fastexpp(ll x, ll y, ll p) {
  ll ans = 1;
  while (y > 0) {
    if (y & 1)
      ans = (ans * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return ans % p;
}

// Change fastexpp to fastexp for small numbers :)
bool check_composite(ll n, ll a, ll d, int s) {
  ll x = fastexpp(a, d, n);
  if (x == 1 || x == n - 1)
    return false;
  for (int r = 1; r < s; r++) {
    x = (1LL * x * x) % n;
    if (x == n - 1)
      return false;
  }
  return true;
}

bool check_primality(ll p) {
  if (p <= 1)
    return false;
  if (p < MAXN)
    return !is_prime[p];
  int r = 0;
  ll d = p - 1;
  while (!(d & 1)) {
    d >>= 1;
    r++;
  }
  for (int i = 0; i < 12; i++) {
    int value = TestMillerRabin[i];
    if (p == value)
      return true;
    if (check_composite(p, value, d, r))
      return false;
  }
  return true;
}

ll count_solutions(vector<int> &permutation, int idx = 0, ll current_number = 0,
                   ll previous_number = 0) {
  int n = permutation.size();
  ll ans = 0;
  for (int i = idx; i < n; i++) {
    current_number = current_number * 10 + permutation[i];
    if (current_number < previous_number)
      continue;
    if (check_primality(current_number)) {
      if (i == n - 1)
        ans++;
      else
        ans += count_solutions(permutation, i + 1, 0, current_number);
    }
  }
  return ans;
}

ll generate_permutations() {
  ll ans = 0;
  vector<int> permutation = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  do {
    int last = permutation.back();
    if (last % 2 == 0 or last == 5)
      continue;
    ll out = count_solutions(permutation);
    ans += out;
  } while (next_permutation(permutation.begin(), permutation.end()));
  return ans;
}

int main() {
  sieve();
  ll ans = generate_permutations();
  cout << ans << '\n';
  return 0;
}