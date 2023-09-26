#include <bits/stdc++.h>
using namespace std;
#define N 100000000

using ll = long long;
vector <int> t[3];

void build(){
    unordered_set <ll> s;
    for(int n=3; 1LL*n*n<=N/6; n++){
        //if(m%10 == 0) cout << m << '\n';
        for(int m=n+1; 1LL*m*m<=N/6; m++){
            //if(n%100 == 0) cout << m << " " << n << '\n';
            ll a = 2LL*m*n;
            ll b = 1LL*m*m - 1LL*n*n;
            ll c = 1LL*m*m + 1LL*n*n;
            if(a+b+c >= N) break;
            if(a > b) swap(a, b);
            ll g = __gcd(c, __gcd(a, b));
            a /= g; b /= g; c /= g;
            ll x = a*N + b;
            if(s.find(x) != s.end())
                continue;
            s.insert(x);
            t[0].push_back(a); t[1].push_back(b); t[2].push_back(c);
        }
    }
}

int main(){
    //m^2+n^2, m^2-n^2, 2mn
    build();
    int ans = 0;
    for(int i=0; i<t[0].size(); i++){
        int a = t[0][i];
        int b = t[1][i];
        int c = t[2][i];
        if(c%(b - a) == 0){
            cout << a << " " << b << " " << c << '\n';
            ans += (N/(a+b+c));
        }
    }
    cout << ans << '\n';
    return 0;
}
