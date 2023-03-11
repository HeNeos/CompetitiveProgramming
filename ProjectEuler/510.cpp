#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define N 1000000000
// #define N 10000000

int main(){
    ll ans = 0;
    // rb = ra*multiplier
    // (multiplier+1)/rb + 2/(ra*i) = ((multiplier+1) + 2*i)/(ra*multiplier)
    // rc*(i+1)^2 = ra*i*i
    // ra*i^2 = rc*(i+1)^2
    // rb = rc*(i+1)^2
    for(ll a=1; a*a<=N; a++){
        ll ra = a*a;
        for(ll b=a; b*b<=N; b++){
            ll rb = b*b;
            ll g = __gcd(b, a);
            ll den = a/g;
            ll num = b/g + a/g;
            if(rb%(num*num) != 0) continue;
            ll rc = rb/num; rc /= num;
            rc *= den; rc *= den;
            if(__gcd(__gcd(ra, rb), rc) == 1) {
                ll l = N/rb;
                ll s = (ra+rb+rc);
                s *= (l*(l+1))/2;
                ans += s;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}