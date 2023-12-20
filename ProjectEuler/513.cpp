#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define N 2000
#define MAX 11

set <pair<ll, ll> > s;
map <ll, vector <ll> > m;

ll isqrt(ll x){
    if(x <= 1) return x;
    ll x0 = x/2;
    ll x1 = (x0 + x/x0)/2;

    while(x1 < x0){
        x0 = x1;
        x1 = (x0 + x/x0)/2;
    }
    return x0;
}

void fill(){
    for(int n=1; n<N; n++){
        for(int m=n+1; m<N; m++){
            if((m+n)%2 == 0 or __gcd(m, n) != 1) continue;
            ll a = 1LL*m*m - 1LL*n*n;
            ll b = 2LL*m*n;
            ll c = 1LL*m*m + 1LL*n*n;
            ll g = __gcd(__gcd(a, b), c);
            a /= g; b /= g; c /= g;
            s.insert({a, b});
        }
    }

    for(auto t: s){
        ll a = t.first;
        ll b = t.second;
        ll c = isqrt(a*a + b*b);
        // cout << a << " " << b << " " << c << endl;
        m[c].push_back(min(a, b));
    }
}


int main(){
    fill();
    ll out = 0;
    for(int a=1; a<=MAX; a++){
        for(int b=a; b<=MAX; b++){
            ll x = 1LL*a*a + 1LL*b*b;
            // x = 2*(m*m + p*p)
            // c = 2p -> 2p >= b, p>=b/2
            if(x%2 != 0) continue;
            x /= 2;
            x = isqrt(x);
            set <ll> ans;
            for(int i=1; 1LL*i*i<=x; i++){
                if(x%i == 0){
                    int d = i;
                    for(int j=0; j<m[d].size(); j++){
                        ll first_side = m[d][j];
                        ll second_side = isqrt(d*d - first_side*first_side);
                        first_side *= x/d;
                        second_side *= x/d;
                        if(2*first_side >= b and 2*first_side <= MAX) ans.insert(2*first_side);
                        if(2*second_side >= b and 2*second_side <= MAX) ans.insert(2*second_side);
                    }
                }
                if(i != x/i){
                    int d = x/i;
                    for(int j=0; j<m[d].size(); j++){
                        ll first_side = m[d][j];
                        ll second_side = isqrt(d*d - first_side*first_side);
                        first_side *= x/d;
                        second_side *= x/d;
                        if(2*first_side >= b and 2*first_side <= MAX) ans.insert(2*first_side);
                        if(2*second_side >= b and 2*second_side <= MAX) ans.insert(2*second_side);
                    }
                }
            }
            for(auto c: ans){
                cout << a << " " << b << " " << c << '\n';
            }
            out += ans.size();
        }
    }
    cout << out << '\n';
    return 0;
}
