#include <bits/stdc++.h>
using namespace std;
#define FIFO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int solve(vector <int> &A){
    vector <int> ans; ans.push_back(A[0]);
    for(int i=1; i<A.size(); i++){
        int p = lower_bound(ans.begin(), ans.end(), A[i])-ans.begin();
        if(p == ans.size()) ans.push_back(A[i]);
        else ans[p] = A[i];
    }
    return ans.size();
}

int main(){
    FIFO;
    int t; cin >> t;
    for(int _=1; _<=t; _++){
        int n; cin >> n;
        vector <int> A(n+1), B(n+1);
        for(int i=0; i<n; i++){
            int x; cin >> x;
            A[x] = i;
        }
        for(int i=0; i<n; i++){
            int x; cin >> x;
            B[i] = A[x];
        }
        cout << "Case " << _ << ": " << 2*n-2*solve(B) << '\n';
    }
    return 0;
}