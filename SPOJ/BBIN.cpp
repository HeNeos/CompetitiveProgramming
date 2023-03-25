#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n, q; cin >> n >> q;
    int a[n];
    set <int> s;
    for(int i=0; i<n; i++){
        cin >> a[i];
        s.insert(a[i]);
    }
    while(q--){
        int x;
        cin >> x;
        if(s.find(x) != s.end()){
            int lo = 0;
            int hi = n-1;
            while(lo < hi){
                int me = lo + (hi - lo)/2;
                if(a[me] < x) lo = me+1;
                else hi = me;
            }
            cout << hi << '\n';
        }
        else cout << -1 << '\n';
    }
    return 0;
}