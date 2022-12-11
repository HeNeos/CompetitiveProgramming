#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector <int> to(n+1, n+1);
        for(int i=0; i<m; i++){
            int x, y; cin >> x >> y;
            if(x > y) swap(x, y);
            to[x] = min(to[x], y);
        }
        for(int i=n-1; i>=1; i--) to[i] = min(to[i], to[i+1]);
        long long ans = 0;
        for(int i=1; i<=n; i++)
            ans += to[i] - i;
        cout << ans << '\n';
    }
    return 0;
}
