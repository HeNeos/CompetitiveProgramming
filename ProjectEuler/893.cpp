#include <bits/stdc++.h>
using namespace std;

#define N 1000005

const int Plus = 2;
const int Multiply = 2;
int digits[10];

int numbers[N];

void init() {
  digits[0] = 6;
  digits[1] = 2;
  digits[2] = 5;
  digits[3] = 5;
  digits[4] = 4;
  digits[5] = 5;
  digits[6] = 6;
  digits[7] = 3;
  digits[8] = 7;
  digits[9] = 6;
}

int build_number(int x) {
  int ans = 0;
  while (x) {
    int d = x % 10;
    ans += digits[d];
    x /= 10;
  }
  if (!ans)
    ans = digits[0];
  return ans;
}

vector<int> dp;
map<int, vector<int>> inverse_dp;
void build_numbers(int n) {
  for (int i = 0; i < n; i++) {
    numbers[i] = build_number(i);
  }
  for (int i = 0; i < 10; i++) {
    dp[i] = numbers[i];
    inverse_dp[numbers[i]].push_back(i);
  }
}

void build_multiplication(int n) {
  for (int i = 2; i < n; i++) {
    for (int j = 2 * i; j < n; j += i) {
      numbers[j] = min(numbers[j], numbers[i] + numbers[j / i] + Multiply);
    }
  }
}

int solve(int x) {
  /*
    Find the shortest way to write x
  */
  if (dp[x])
    return dp[x];
  // x = a*b
  int ans = numbers[x];
  // x = a+b
  for (auto v : inverse_dp) {
    int weight = v.first;
    if (2 * weight + Plus >= ans)
      break;
    vector<int> indices = v.second;
    for (auto index : indices) {
      if (index == 0)
        continue;
      ans = min(ans, weight + dp[x - index] + Plus);
    }
  }
  dp[x] = ans;
  inverse_dp[ans].push_back(x);
  return ans;
}

int main() {
  init();
  int n;
  cin >> n;
  if (n == -1)
    n = N;
  n = min(n, N);
  dp.resize(n + 1);
  build_numbers(n + 1);
  build_multiplication(n + 1);
  build_multiplication(n + 1);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += solve(i);
  }
  cout << ans << '\n';
  return 0;
}