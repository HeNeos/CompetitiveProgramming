#include <bits/stdc++.h>
using namespace std;

bool dp[50005][105];

void clean(){
    for(int i=0; i<50005; i++){
        for(int j=0; j<105; j++) dp[i][j] = false;
    }
}

void solve(vector <int> &arr, int pos, int acum){
    if(pos > arr.size()) return;
    if(dp[acum][pos]) return;

    dp[acum][pos] = true;
    
    solve(arr, pos+1, acum);
    if(pos < arr.size()) solve(arr, pos+1, acum+arr[pos]);
}

int main(){
    int t; cin >> t;
    while(t--){
    	clean();
        int m; cin >> m;
        vector <int> arr(m);
        int s = 0;
        for(int i=0; i<m; i++){
            cin >> arr[i];
            s += arr[i];
        }
        solve(arr, 0, 0);

        for(int i=s/2; i>=0; i--){
            if(dp[i][m]){
                cout << s - 2*i << '\n';
                break;
            }
        }
    }
    return 0;
}