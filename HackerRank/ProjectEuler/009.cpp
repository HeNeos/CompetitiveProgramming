#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void getSolution(int &a, int &b, int s, int p){
    ll d_2 = 1LL*s*s - 2*p;
    int d = (int)(sqrt(d_2));
    if(d*d != d_2) return;
    b = (s + d)/2;
    a = s - b;
    if(2*a*b != p){
        a = -1;
        b = -1;
    }
    if(a <= 0 or b <= 0){
        a = -1;
        b = -1;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n%2 != 0){
            cout << -1 << '\n';
            continue;
        }
        // c = N - a - b
        // c^2 = N^2 + (a+b)^2 - 2*N*(a+b) = a^2 + b^2
        // N^2 + 2ab = 2N(a+b)
        // N = 0 mod (2)
        // 2ab = 0 mod (N)
        // ab = 0 mod (2)
        // 2ab = N(2a+2b - N)
        ll ans = -1;
        // N < 2(a+b)
        // N/2 < (a+b)
        // c^2 = N^2 + s^2 - 2Ns
        // 0 = 2ab + N^2 - 2Ns
        for(int s=n/2; s<n; s++){
            ll aux = 2LL*n*s - 1LL*n*n; // = 2ab
            int a = -1; int b = -1;
            getSolution(a, b, s, aux);
            if(a != -1 && b != -1)
                ans = max(ans, 1LL*(aux/2)*(n-s)); 
        }
        cout << ans << '\n';
    }
    return 0;
}
