#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define N 100000

bitset<N> primes;
int count_primes[N];
vector<int> ans;
void sieve() {
  for (int i = 2; i < N; i++) {
    if (!primes[i]) {
      count_primes[i] = 1;
      for (ll j = 2 * i; j < N; j += i) {
        primes[j] = 1;
        count_primes[j]++;
      }
    }
  }
  for (int i = 2; i < N; i++) {
    if (count_primes[i] >= 3)
      ans.push_back(i);
  }
}

int main() {
  sieve();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << ans[n - 1] << '\n';
  }
  return 0;
}
