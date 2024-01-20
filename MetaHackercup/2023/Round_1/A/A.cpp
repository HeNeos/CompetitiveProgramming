#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int t; cin >> t;
    for(int _=1; _<=t; _++){
        cout << "Case #" << _ << ": ";
        int n; cin >> n;
        ll a[n];
        for(int i=0; i<n; i++){
            cin >> a[i];
            a[i] *= 2;
        }
        sort(a, a+n);
        if(n == 5){
            ll p1 = (a[0] + a[2])/2;
            ll p2 = (a[3] + a[4])/2;
            ll ans1 = p2 - p1;
            p1 = (a[0] + a[1])/2;
            p2 = (a[2] + a[4])/2;
            ll ans2 = p2 - p1;
            ll ans = max(ans1, ans2);
            if(ans%2 == 0) cout << ans/2;
            else cout << ans/2 << ".5";
            cout << '\n';
            continue;
        }
        ll p1 = (a[0] + a[1])/2;
        ll p2 = (a[n-1] + a[n-2])/2;
        ll ans = p2-p1;
        if(ans%2 == 0) cout << ans/2;
        else cout << ans/2 << ".5";
        cout << '\n';
    }
    return 0;
}