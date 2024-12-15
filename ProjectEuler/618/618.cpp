#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define N 100005

bitset<N> is_prime;
vector<int> primes;
void sieve() {
  for (int i = 2; i < N; i++) {
    if (!is_prime[i]) {
      primes.push_back(i);
      for (ll j = 1LL * i * i; j < N; j += i)
        is_prime[j] = 1;
    }
  }
}

int fibonacci[30];

void fill_fibonacci() {
  fibonacci[1] = 1;
  for (int i = 2; i < 30; i++)
    fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
}

ll next_move(vector<int> &exponents) {
  int sz = exponents.size();
  ll current_sum = 0;
  for (int i = 0; i < sz; i++)
    current_sum += primes[i] * exponents[i];
  exponents[0]++;
  current_sum += primes[0];
  int last_position = 0;
  while (current_sum > fibonacci[24] && last_position < sz) {
    current_sum -= exponents[last_position] * primes[last_position];
    exponents[last_position] = 0;
    current_sum += exponents[last_position + 1];
    last_position++;
  }
  return current_sum;
}

ll ans[N];
void fill(vector<int> &exponents) {
  ll s = next_move(exponents);
  ans[s] += s;
}

int main() {
  sieve();
  ll ans = 0;
  fill_fibonacci();
  vector<int> exponents(N, 0);
  fill(exponents);
  return 0;
}