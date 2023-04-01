#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int zeros = 0;
        int s = 0;
        int a[n];
        for(int i=0; i<n; i++){
            cin >> a[i];
            if(a[i] == 0) zeros++;
            s += a[i];
        }
        int ans = zeros;
        if(s != 0 and zeros == 0){
            cout << "0\n";
            continue;
        }
        if(s == 0 and zeros == 0){
            cout << "1\n";
            continue;
        }
        if(s + zeros == 0) ans++;
        cout << ans << '\n';
    }
    return 0;
}