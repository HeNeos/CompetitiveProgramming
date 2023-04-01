#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    int t; cin >> t;
    while(t--){
        int n, c, d;
        cin >> n >> c >> d;
        set <int> s;
        vector <int> a;
        for(int i=0; i<n; i++){
            int x; cin >> x;
            if(s.find(x) == s.end()){
                s.insert(x);
                a.push_back(x);
            }
        }
        sort(a.begin(), a.end());
        
        ll ans = 0;

        // remove duplicates
        ans += 1LL*(n - a.size())*c; 

        ll min_ans = (1LL<<62);
        // for each maximum, find the answer
        for(int i=a.size()-1; i>=0; i--){
            ll current_len = i+1;
            if(a[i] >= current_len){
                ll current_cost = 1LL*(a.size() - current_len)*c;
                current_cost += 1LL*(a[i] - current_len)*d;
                min_ans = min(min_ans, current_cost);
            }
        }
        min_ans = min(min_ans, d + 1LL*c*(a.size()));

        ans += min_ans;
        cout << ans << '\n';
    }
    return 0;
}