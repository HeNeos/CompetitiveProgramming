#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define MOD 1000000007

ll fastexp(ll x, ll y, ll p){
    ll ans = 1;
    while(y > 0){
        if(y&1) ans = (ans*x)%p;
        y = y>>1;
        x = (x*x)%p;
    }
    return ans%p;
}

ll dp2[65];
ll dp3[65];

void fill(){
    dp2[0] = 1;
    dp3[0] = 1;
    for(int i=1; i<65; i++){
        dp2[i] = dp2[i-1]*2;
        dp3[i] = dp3[i-1]*3;
        dp2[i] %= MOD;
        dp3[i] %= MOD;
    }
}

int main() {
    fill();
    int t; cin >> t;
    while(t--){
        ll m; cin >> m;
        int n = 0;
        while(m > 0){
            if(m&1 == 1) n++;
            m /= 2;
        }
        if(n < 3){
            cout << 0 << '\n';
            continue;
        }
        ll ans = 0;
        for(int i=1; i<n; i++){
            for(int j=i+1; j<n; j++){
                int middle = j-i-1;
                ans += (1LL*dp2[middle]*dp3[n-(j+1)])%MOD;
                ans %= MOD;
            }
        }
        ans = ans*6;
        ans %= MOD;
        cout << ans << '\n';
        
        // a+b = a|b + a&b
        // (x+y)&z = 0
        // x&y&z = x&y + x&z + y&z
        // x&y = 0, y&z=0, z&x = 0
        // 111 -> 4^(n-3)*C(n, 3)
    }

    return 0;
}