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

int mobius[N];

void cmob(){
    mobius[1] = 1;
    for(int i=2; i<N; i++){
        if(lpf[i] == i) mobius[i] = -1;
        else{
            if(lpf[i/lpf[i]] == lpf[i]) mobius[i] = 0;
            else mobius[i] = -1*mobius[i/lpf[i]];
        }
    }
}
vector <pair <int,int> > data; 
void solve(){
    for(int i=2; i<N; i++){
        if(mobius[i] == 0) continue;
        data.push_back(make_pair(i,mobius[i]));
    }
}

int main(){
    sieve();
    cmob();
    solve();
    int t;
    cin >> t;
    
    while(t--){
        ll n;
        cin >> n;
        ll ans = 0;
        for(int i=0; i<data.size(); i++){
            ll v = 1LL*data[i].first*data[i].first;
            if(v > n) break;
            ans += data[i].second*(n/v);
        }
        cout << n+ans << '\n';
    }
    return 0;
}