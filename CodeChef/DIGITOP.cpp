#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--){
        long long n, k; cin >> n >> k;
        string a[n];
        string b[n];
        map <char, int> m;
        for(int i=0; i<n; i++){
            cin >> a[i];
            for(int j=0; j<a[i].size(); j++) m[a[i][j]]++;
        }
        for(int i=0; i<n; i++){
            cin >> b[i];
            for(int j=0; j<b[i].size(); j++) m[b[i][j]]--;
        }
        bool ispossible = true;
        for(int i=0; i<n; i++){
            if(a[i].size() != b[i].size()) ispossible = false;
        }
        if(!ispossible){
            cout << "NO\n";
            continue;
        }
        long long ans = 0;
        for(auto v: m){
            ans += abs(v.second);
        }
        // cout << ans << "XD\n";
        if(ans <= 2LL*k) cout << "YES";
        else cout << "NO";
        cout << '\n';
    }
    return 0;
}