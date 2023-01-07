#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define N 500005

int s_div[N];

void sieve(){
    for(int i=1; i<N; i++){
        for(ll j=i; j<N; j+=i){
            s_div[j] += i;
        }
    }
}

int main(){
    sieve();
    int t; cin >> t;
    while(t--){
        int x; cin >> x;
        cout << s_div[x] - x << '\n';
    }
    return 0;
}