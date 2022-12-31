#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define N 1000005
int phi[N];
ll s[N];
void sieve(){
    for(int i=2; i<N; i++){
        if(phi[i] == 0){
            phi[i] = i-1;
            for(ll j=2*i; j<N; j+=i){
                if(phi[j] == 0) phi[j] = j;
                phi[j] /= i;
                phi[j] *= (i-1);
            }
        }
    }
    phi[1] = 1;
}

void fill(){
    for(int i=1; i<N; i++){
        for(ll j=i; j<N; j+=i){
            s[j] += 1LL*i*phi[i];
        }
    }
}

int main(){
    sieve();
    fill();
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ll ans = s[n];
        ans++;
        ans *= n;
        ans /= 2;
        cout << ans << '\n';
    }
    return 0;
}