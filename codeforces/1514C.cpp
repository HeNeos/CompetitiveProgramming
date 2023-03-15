#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int n; cin >> n;
  vector <int> ans;
  ll p = 1;
  for(int i=1; i<n; i++){
    if(__gcd(i, n) == 1){
      ans.push_back(i);
      p *= i;
      p %= n;
    }
  }
  int sz = ans.size();
  sz--;
  cout << sz << '\n';
  for(int i=0; i<ans.size(); i++){
    if(sz != ans.size() && ans[i] == p) continue;
    cout << ans[i] << " ";
  }
  return 0;
}
