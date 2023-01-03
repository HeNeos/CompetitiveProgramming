#include <bits/stdc++.h>
using namespace std;

bool dp[34][645][645];
vector <int> arr;
int n;
void clean(int elements, int s){
    for(int i=0; i<elements; i++){
        for(int j=0; j<s; j++){
            for(int k=0; k<s; k++) dp[i][j][k] = false;
        }
    }
    arr.clear();
}

bool solve(int pos, int a1, int a2){
    if(pos >= n){
        dp[pos][a1][a2] = true;
        return true;
    }
    if(dp[pos][a1][a2]) return true;

    bool ans = solve(pos+1, a1+arr[pos], a2);
    ans |= solve(pos+1, a1, a2+arr[pos]);
    ans |= solve(pos+1, a1, a2);
    

    dp[pos][a1][a2] = ans;

    return dp[pos][a1][a2];
}

int main(){
    int t; cin >> t;
    int c = 0;
    while(t--){
        c++;
        if(c == 1) clean(34, 645);
        cin >> n;
        arr.resize(n);
        int s = 0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            s += arr[i];
        }
        int ans = INT_MAX;
        solve(0, 0, 0);
        for(int i=0; i<=s; i++){
            for(int j=0; j<=s; j++){
                if(dp[n][i][j]){
                    int mini = min(s-i-j, min(i, j));
                    int maxi = max(s-i-j, max(i, j));
                    ans = min(ans, maxi-mini);
                }
            }
        }
        clean(n+2, s+5);
        cout << "Case " << c << ": " << ans << '\n';
    }
    return 0;
}