#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define N 10000005

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

ll ans[N];

void build(){
    ans[0] = 0;
    ans[1] = 0;
    for(int i=2; i<N; i++)
        ans[i] = ans[i-1] + lpf[i];
}

int main(){
    sieve();
    build();
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << ans[n] << '\n';
    }
}