#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(n%2 == 0){
            cout << -1 << '\n';
            continue;
        }
        string ans = "";
        while(n > 1){
            int prev = (n-1)/2;
            if(prev%2 == 0){
                prev++;
                ans += "1";
            }
            else{
                ans += "2";
            }
            n = prev;
        }
        cout << ans.size() << '\n';
        // for(int i=ans.size()-1; i>=0; i--) cout << ans[i] << " ";
        cout << '\n';
    }
    return 0;
}