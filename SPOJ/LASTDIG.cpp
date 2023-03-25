#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll fastexp(ll a, ll b){
    if(b == 0) return 1;
    if(b == 1) return a%10;
    ll ans = fastexp(a, b/2);
    ans = (ans*ans)%10;
    if(b%2 == 1) ans = (ans*a)%10;
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll a, b;
        cin >> a >> b;
        cout << fastexp(a, b) << '\n';
    }
    return 0;
}