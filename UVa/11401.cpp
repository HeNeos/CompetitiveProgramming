#include <bits/stdc++.h>
using namespace std;

#define N 1000005

long long dp[N];

void fill(){
    dp[4] = 1;
    for(int i=5; i<N; i++){
        dp[i] = dp[i-1];
        int v = i/2;
        dp[i] += 1LL*v*(v-1)/2;
        v =  (i-1) - (i/2 + 1);
        dp[i] += 1LL*v*(v+1)/2;
    }
}

int main(){
    fill();
    int n;
    while(cin >> n){
        if(n < 3) break;
        cout << dp[n] << '\n';
    }
    return 0;
}