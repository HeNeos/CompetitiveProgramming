#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int maximum_group = 1;
  int current_group = 1;
  int previous_value = a[0];
  for (int i = 1; i < n; i++) {
    if (a[i] <= 2 * previous_value) {
      current_group++;
      maximum_group = max(maximum_group, current_group);
      previous_value = a[i];
    } else {
      current_group = 1;
      previous_value = a[i];
    }
  }
  cout << maximum_group << '\n';
  return 0;
}
