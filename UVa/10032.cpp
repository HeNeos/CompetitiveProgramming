#include <bits/stdc++.h>
#define FIFO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;
using ll = long long;
vector <int> arr;
int n;
int s;

ll dp[450*100+5];
void clean(){
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
}

void solve(){
    for(int i=0; i<n; i++){
        for(int j=s; j>=0; j--){
            if(dp[j])
                dp[j+arr[i]] |= (dp[j]<<1);
        }
    }
}

int main(){
    FIFO;
    int t; cin >> t;
    while(t--){
        cin >> n;
        arr.clear();
        arr.resize(n);
        clean();
        s = 0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            s += arr[i];
        }
        solve();
        int val = -1;
        for(int i=s/2; i>=0; i--){
            if(dp[i] & (1LL<<(n/2))){
                val = i;
                break;
            }
            if(dp[i] & (1LL<<(n - n/2))){
                val = i;
                break;
            }
        }
        cout << val << " " << s-val << '\n';
        if(t) cout << '\n';
    }
    return 0;
}