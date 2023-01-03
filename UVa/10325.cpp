#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll lcm(ll x, ll y){
    return (1LL*x*y)/(__gcd(x,y));
}

int main(){
    ll n, m;
    while(cin >> n >> m){
        ll arr[m];
        for(int i=0; i<m; i++) cin >> arr[i];
        ll mask = 1LL<<m;
        ll out = 0;
        for(int i=0; i<mask; i++){
            ll ans = 1;
            for(int j=0; j<m; j++){
                if(i&(1<<j)) ans = lcm(ans,arr[j]);
            }
            if(__builtin_popcount(i)&1) out -= n/ans;
            else out += n/ans;
        }
        cout << out << '\n';
    }
    return 0;
}