#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int n, x;

bool check(vector<int> &frequencies) {
  for (int i = 0; i < x; i++) {
    if (frequencies[i] != 0)
      return false;
  }
  return frequencies[x] >= 1;
}

int main() {
  cin >> n >> x;
  vector<int> a(n);
  vector<int> freq(x + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    freq[a[i]]++;
  }
  for (int i = 1; i < x; i++) {
    int c = freq[i];
    int next_freq = c / (i + 1);
    int residue = c % (i + 1);
    freq[i] = residue;
    freq[i + 1] += next_freq;
  }
  if (check(freq))
    cout << "Yes\n";
  else
    cout << "No\n";
  return 0;
}