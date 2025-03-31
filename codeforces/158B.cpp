#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int n; cin >> n;
  vector <int> a(5, 0);
  for(int i=0; i<n; i++){
    int x; cin >> x;
    a[x]++;
  }
  int ans = a[4];
  a[4] = 0;
  int shared_3_1 = min(a[3], a[1]);
  ans += a[3];
  a[3] = 0;
  a[1] -= shared_3_1;
  ans += a[2] / 2;
  a[2] %= 2;
  if(a[2] == 1){
    ans++;
    a[2] = 0;
    a[1] -= 2;
  }
  if(a[1] > 0)
    ans += (a[1] + 3)/4;
  cout << ans << '\n';

  return 0;
}
