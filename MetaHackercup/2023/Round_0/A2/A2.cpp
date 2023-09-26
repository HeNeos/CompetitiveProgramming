#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int t; cin >> t;
    for(int _=1; _<=t; _++){
        ll a, b, c;
        cin >> a >> b >> c;
        ll n_1 = 0;
        ll n_2 = (c - n_1*a)/b;
        ll r = b/a;
        // int buns = 2*n_1 + 2*n_2;
        // int patty = n_1 + 2*n_2;
        // int cheese = n_1 + 2*n_2;
        ll ans = 0;
        if(c >= a) ans = max(ans, 1 + (c-a)/b * 2);
        ans = max(ans, 2*n_2-1);
        if(b >= 2*a){
            n_1 = c/a;
            n_2 = (c-n_1*a)/b;
            ans = max(ans, n_1 + 2*n_2);
        }
        else{
            n_1 = 1 + ((c-a)%b)/a;
            n_2 = (c-n_1*a)/b;
            if(n_1 >= 1 and n_1 <= c/a)
                ans = max(ans, n_1+2*n_2);
        }
        // ans = max(ans, c/a + (c - c/a * a)/b * 2);
        // if(b <= 2*a)
        //     ans = max(ans, 1 + 2*(c-a)/b);
        // else
        //     ans = max(ans, c/a);
        // if n_1 == 0: max 2*n_2 - 1;
        // else max n_1 + 2*n_2 = n_1 + 2*floor(c-n_1*a / b)
        // max min(n_1+2*n_2, 2*n_1+2*n_2-1)
        cout << "Case #" << _ << ": " << ans << '\n';
    }
    return 0;
}