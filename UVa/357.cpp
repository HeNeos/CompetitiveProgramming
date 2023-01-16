#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define N 30005
int n;
ll dp[N];

int change[5] = {1,5,10,25,50};

void solve(){
    dp[0] = 1;
    for(int j=0; j<5; j++){
        for(int i=change[j]; i<N; i++){
            dp[i] += dp[i-change[j]];
        }
    }
}

int main(){
    solve();
    while(cin >> n){
        if(dp[n] == 1) cout << "There is only 1 way";
        else cout << "There are " << dp[n] << " ways";
        cout << " to produce " << n << " cents change.\n"; 
    }
    return 0;
}