#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        ll ans = n;
        for(int i=1; i<n; i++){
            if(s[i] != s[i-1]) ans += i;
        }
        cout << ans << '\n';
    }
    return 0;
}