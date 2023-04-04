#include <iostream>

using namespace std;
using ll = long long;

int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        ll s[n+1];
        s[0] = 0;
        for(int i=1; i<=n; i++){
            cin >> s[i];
            s[i] += s[i-1];
        }
        if(k < n){
            ll mx = s[k];
            for(int i=1; i<=n-k; i++)
                mx = max(mx, s[i+k] - s[i]);
            ll ans = mx + 1LL*k*(k-1)/2;
            cout << ans;
        }
        else{
            ll ans = s[n];
            ans += 1LL*(k-n)*n;
            ans += 1LL*n*(n-1)/2;
            cout << ans;
        }
        cout << '\n';
    }
    return 0;
}