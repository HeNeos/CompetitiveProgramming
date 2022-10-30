#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define N 1000005

ll phi[N];
void cphi(){
    phi[1] = 1;
    for(ll i=2; i<N; i++){
        if(!phi[i]){
            phi[i] = i-1;
            for(ll j=2LL*i; j<N; j+=i){
                if(phi[j] == 0) phi[j] = j;
                phi[j] = phi[j]/i*(i-1);
            }
        }
    }
}

ll S[N];
void fill(){
    S[1] = 0;
    for(int i=2; i<N; i++){
        S[i] = S[i-1] + phi[i];
    }
}

int main(){
    cphi();
    fill();
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << S[n] << '\n';
    }
}
