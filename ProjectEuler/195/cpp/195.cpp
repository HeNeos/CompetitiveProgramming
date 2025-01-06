#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const long n = 1053779;
// const long n = 10000;

int main() {
    ll ans = 0;
    for(int v=1;; v++){
        if(v + 1LL*v*v > 4*n) break;
        for(int u=2*v+1;; u++){
            if(1LL*u*v - 1LL*v*v > 4*n) break;
            if(__gcd(u, v) != 1) continue;
            ll a = 1LL*u*u-1LL*v*v;
            ll b = 2LL*u*v - 1LL*v*v;
            ll c = 1LL*u*u + 1LL*v*v - 1LL*u*v;
            if (a <= 0 || b <= 0 || c <= 0) continue;
            ll t = __gcd(a, b);
            a /= t, b /= t, c /= t;
            int r_2_sqrt3 = a+b-c; // 2*sqrt(3)*r
            if (1. * (r_2_sqrt3) * (r_2_sqrt3) <= 12. * n * n)
                ans += (2*sqrt(3.)*n)/(r_2_sqrt3);
        }
    }
    printf("%ld\n", ans);
    return 0;
}