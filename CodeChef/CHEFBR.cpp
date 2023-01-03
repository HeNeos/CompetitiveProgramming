#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
using ll = long long;
ll dp[101][101];
ll arr[101];

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i+1];
    
    for(int len=0; len<n; len++){
        for(int i=1;i<=n;i++){
            int j = len+i;
            if(j>n) continue;
            if(i == j){
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = dp[i][j-1];
            for(int k=i;k<j;k++){
                if(arr[j]>0 and arr[k]==-arr[j]){
                    if(k==i)
                        dp[i][j] = (dp[i][j] + 1+dp[k+1][j-1])%MOD;    
                    else
                        dp[i][j] = (dp[i][j] + ((1+dp[k+1][j-1])*(1+dp[i][k-1]))%MOD)%MOD;    
                }
            }
        }
    }
    cout << dp[1][n]+1;
    return 0;
}