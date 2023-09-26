#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define INF (1LL<<40)

ll solve_last(vector <int> &a){
    int sz = a.size();
    ll s = a[1] + a[sz-1];
    for(int i=1; i<sz; i++){
        if(i > sz-i) break;
        if(a[i] + a[sz-i] != s) return -1;
    }
    ll ans = s-a[0];
    if(ans > 0 and ans >= a[sz-1] ) return ans;
    return -1;
}

ll solve_first(vector <int> &a){
    int sz = a.size();
    ll s = a[0] + a[sz-2];
    for(int i=1; i<sz; i++){
        if(i > sz-i-2) break;
        if(a[i] + a[sz-i-2] != s) return -1;
    }
    ll ans = s-a[sz-1];
    if(ans > 0 and ans <= a[0]) return ans;
    else return -1;
}

ll solve_middle(vector <int> &a){
    int sz = a.size();
    ll s = a[0] + a[sz-1];
    ll S = 0;
    for(int i=0; i<sz; i++) S += a[i];
    ll ans = (sz+1)/2 * s - S;
    if(ans > 0 and ans >= a[0] and ans <= a[sz-1]) return ans;
    else return -1;
}

int main(){
    int t; cin >> t;
    for(int _=1; _<=t; _++){
        cout << "Case #" << _ << ": ";
        int n; cin >> n;
        vector <int> arr(2*n-1);
        for(int i=0; i<2*n-1; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());
        if(n == 1){
            cout << "1\n";
            continue;
        }
        ll ans = INF;
        ll last = solve_last(arr);
        ll first = solve_first(arr);
        ll middle = solve_middle(arr);
        if(middle != -1){
            arr.push_back(middle);
            sort(arr.begin(), arr.end());
            ll s = arr[0] + arr[2*n-1];
            for(int i=0; i<n; i++){
                if(arr[i] + arr[2*n-1-i] != s) middle = -1;
            }
        }
        if(last != -1) ans = min(ans, last);
        if(first != -1) ans = min(ans, first);
        if(middle != -1) ans = min(ans, middle);
        if(ans == INF) ans = -1;
        cout << ans << '\n';
    }
    return 0;
}