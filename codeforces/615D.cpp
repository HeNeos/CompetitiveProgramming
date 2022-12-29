#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define MOD 1000000007
map <int, int> f;

ll fastexp(ll x, ll y, ll p){
    ll ans = 1;
    while(y > 0){
        if(y&1) ans = (ans*x)%p;
        y = y>>1;
        x = (x*x)%p;
    }
    return ans%p;
}

ll sigma_0(bool &is_square){
    ll ans = 1;
    bool divide = false;
    for(auto it: f){
        int p = it.first;
        int e = it.second;
        ans *= (e+1);
        if(e%2 == 1 && !divide){
            divide = true;
            ans /= 2;
        }
        ans %= (MOD-1);
    }
    if(!divide)
        is_square = true;
    return ans;
}

ll get_sqrt(){
    ll ans = 1;
    for(auto it: f){
        int p = it.first;
        int e = it.second;
        ans *= fastexp(p, e/2, MOD);
        ans %= MOD;
    }
    return ans;
}

int main(){
    int m; cin >> m;
    ll ans = 1;
    for(int i=0; i<m; i++){
        int x; cin >> x;
        ans *= x;
        ans %= MOD;
        f[x]++;
    }
    bool is_square = false;
    ll d = sigma_0(is_square);
    if(!is_square)
        cout << fastexp(ans, d, MOD) << '\n';
    else
        cout << fastexp(get_sqrt(), d, MOD) << '\n';
    return 0;
}