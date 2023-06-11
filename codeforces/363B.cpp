#include <bits/stdc++.h>
using namespace std;
int main(){
      int n, k;
    cin >> n >> k;
    int arr[n];
    int dp[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    dp[0] = 0;
    for(int i=0; i<k; i++) dp[0] += arr[i];
    for(int i=1; i<n-k+1; i++) dp[i] = dp[i-1] - arr[i-1] + arr[k+i-1];    
      int answ = 0;
    int minimu = INT_MAX;
    for(int i=0; i<n-k+1; i++){
          if(minimu > dp[i]){
            minimu = dp[i];
            answ = i;
        }
    }
    cout << answ+1;
    return 0;
}
