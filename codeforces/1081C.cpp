#include <bits/stdc++.h>
using namespace std;
long long prim = 998244353; 
long long tablee[2002][2002];
int main(){
    int n;
    int m;
    int k;
    cin >> n >> m >> k;
    tablee[1][0] = m;
    for(int i=1; i<n; i++){
        for(int j=0; j<=k; j++){
            tablee[i+1][j] = ((tablee[i][j])%prim + (tablee[i+1][j])%prim)%prim;
            tablee[i+1][j+1] = ((tablee[i][j]*(m-1))%prim + tablee[i+1][j+1]%prim)%prim;
        }
    }
    cout << (tablee[n][k])%prim;
    return 0;
}
