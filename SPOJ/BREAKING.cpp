#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define N 1000005

int lpf[N];
void sieve(){
    for(int i=2; i<N; i++){
        if(!lpf[i]){
            lpf[i] = i;
            for(ll j=1LL*i*i; j<N; j+=i){
                if(lpf[j] == 0) lpf[j] = i;
            }
        }
    }
}

void solve(int n){
  while(n != 1){
    int d = lpf[n];
    cout << d << " ";
    while(n % d == 0) n /= d;
  }
}

int main(){
  sieve();
  int t; cin >> t;
  for(int _=1; _<=t; _++){
    int n; cin >> n;
    cout << "Case " << _ << ": ";
    solve(n); cout << '\n';
  }
  return 0;
}
