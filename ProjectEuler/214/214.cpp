#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define N 40000005
#define MAXN 40000000

int phi[N];
vector<int> primes;
void cphi() {
  phi[1] = 1;
  for (int i = 2; i < N; i++) {
    if (!phi[i]) {
      phi[i] = i - 1;
      primes.push_back(i);
      for (ll j = 2 * i; j < N; j += i) {
        if (phi[j] == 0)
          phi[j] = j;
        phi[j] = phi[j] / i * (i - 1);
      }
    }
  }
}

bool test(int n) {
  int ans = 1;
  while (true) {
    n = phi[n];
    ans++;
    if (n == 1)
      break;
    if (ans > 25)
      return false;
  }
  return ans == 25;
}

int main() {
  cphi();
  ll ans = 0;
  for (auto prime : primes) {
    if (test(prime))
      ans += prime;
  }
  cout << ans << '\n';
  return 0;
}