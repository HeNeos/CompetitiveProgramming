#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n, q;
    cin >> n >> q;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);
    ll ac[n+1];
    ac[0] = 0;
    for(int i=1; i<=n; i++) ac[i] = ac[i-1] + a[i-1];
    while(q--){
        ll ans = 0;
        int x, y; cin >> x >> y;
        cout << ac[n-x+y] - ac[n-x] << '\n';
    }
    return 0;
}