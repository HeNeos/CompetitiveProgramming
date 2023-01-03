#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector <int> ans;
int n;
void solve(int p, ll m, int l, int r, int v){
    if(v == n+1) return;
    if(m <= (1LL<<(n-p-1))){
        ans[l] = v;
        solve(p+1, m, l+1, r, v+1);
    }
    else{
        ans[r] = v;
        solve(p+1, (m-(1LL<<(n-p-1))), l, r-1, v+1);
    }
}

int main(){
    ll m; cin >> n >> m;
    ans.resize(n);
    solve(1, m, 0, n-1, 1);
    for(int i=0; i<n; i++)
        cout << ans[i] << " ";
    cout << '\n';
    return 0;
}