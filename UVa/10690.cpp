#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m;
vector <int> arr;
ll dp[100*100+5];

void solve(){
    int s = 0;
    for(int i=0; i<(n+m); i++) s+= arr[i];
    dp[0] = 1;
    for(int i=0; i<(n+m); i++){
        for(int j=s; j>=0; j--){
            if(dp[j]) dp[j+arr[i]] |= (dp[j]<<1);
        }
    }
    int real_sum = s-50*(n+m);
    int ans_1 = -1;
    int ans_2 = -1;
    int diff = INT_MAX;
    int DIFF = -1;
    int ANS_1 = -1;
    int ANS_2 = -1;
    for(int i=0; i<=s; i++){
        if(dp[i] & (1LL<<n)){
            int real_s1 = i - 50*n;
            int real_s2 = real_sum - real_s1;
            if(diff > abs(real_s1 - real_s2)){
                diff = abs(real_s1 - real_s2);
                ans_1 = real_s1;
                ans_2 = real_s2;
            }
            if(DIFF < abs(real_s1 - real_s2)){
                DIFF = abs(real_s1 - real_s2);
                ANS_1 = real_s1;
                ANS_2 = real_s2;
            }
        }
    }
    cout << max(ans_1*ans_2, ANS_1*ANS_2) << " " << min(ans_1*ans_2, ANS_1*ANS_2) << '\n';
}

int main(){
    while(cin >> n >> m){
        arr.clear();
        arr.resize(n+m);
        for(int i=0; i<n+m; i++) cin >> arr[i];
        for(int i=0; i<n+m; i++) arr[i] += 50;
        memset(dp, 0, sizeof dp);
        solve();
    }
    return 0;
}