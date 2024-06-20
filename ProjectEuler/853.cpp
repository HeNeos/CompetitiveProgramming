#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;

int divisors[5] = {20, 24, 30, 40, 60};
vector<ll> short_fib(62);

i128 f_120;
i128 f_121;

void fill() {
  short_fib[0] = 0;
  short_fib[1] = 1;
  i128 aux1;
  i128 aux2;
  for (int i = 2; i <= 121; i++) {
    if (i <= 61) {
      short_fib[i] = short_fib[i - 1] + short_fib[i - 2];
      aux2 = short_fib[i - 1];
      aux1 = short_fib[i];
    } else {
      aux1 = aux1 + aux2;
      aux2 = aux1 - aux2;
    }
  }
  f_120 = aux2;
  f_121 = aux1;
}

bool check(int m) {
  for (int i = 0; i < 5; i++) {
    int d = divisors[i];
    if (short_fib[d] % m == 0 and short_fib[d + 1] % m == 1)
      return false;
  }
  return f_120 % m == 0 and f_121 % m == 1;
}

#define MAXN 1000000000

int main() {
  fill();
  int n;
  cin >> n;
  if (n == -1)
    n = MAXN;
  n = min(n, MAXN);
  ll ans = 0;
  for (int i = 20; i <= n; i++) {
    if (check(i)) {
      ans += i;
    }
  }
  cout << ans << '\n';
  return 0;
}