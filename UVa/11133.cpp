#include <bits/stdc++.h>
using namespace std;

#define N 50
int a1, an;

int dp[2*N][2*N][N];

void clean(){
    for(int i=0; i<2*N; i++){
        for(int j=0; j<2*N; j++){
            for(int k=0; k<N; k++) dp[i][j][k] = -1;
        }
    }
}

int solve(int pos, int dig_a, int dig_b){
    if(dig_b > an) return 0;
    if(dig_b == an) return 1;
    if(dp[pos][dig_a][dig_b] != -1) return dp[pos][dig_a][dig_b];
    
    dp[pos][dig_a][dig_b] = 0;
    for(int k=1; k<=an; k++){
        int new_a = dig_a + k;
        int new_b = new_a/k * k;
        if(new_a == new_b)
            dp[pos][dig_a][dig_b] += solve(pos+1, new_a, new_b);
    }
    return dp[pos][dig_a][dig_b];
}

int main(){
    while(true){
        cin >> a1 >> an;
        if(a1 == 0 and an == 0) break;
        clean();
        cout << a1 << " " << an << " " << solve(0, a1, a1) << '\n';
    }
    return 0;
}