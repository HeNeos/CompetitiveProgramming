#include <bits/stdc++.h>
using namespace std;
#define N 105
using ull = unsigned long long;

int dp[N][N];
ull f[N];
ull f2[N];
ull F[N];
ull F2[N];

bool is_possible(int current, int prev_taken){
    if(current == 0) return true;
    if(dp[current][prev_taken] != -1) return dp[current][prev_taken];
    for(int i=1; i<=2*prev_taken; i++){
        if(is_possible(current-i, i)){
            dp[current][prev_taken] = 0;
            return false;
        }
    }
    dp[current][prev_taken] = 1;
    return true;
}

int H(int n){
    for(int i=1; i<=n; i++){
        if(is_possible(n-i, i)) return i;
    }
}

void gen_fibonacci(){
    f[0] = 0; f2[0] = 0; F[0] = 0; F2[0] = 0;
    f[1] = 1; f2[1] = 0; F[1] = 1; F2[1] = 0;
    f2[2] = 0; f2[3] = 0; f2[4] = 0;
    F2[2] = 0; F2[3] = 0; F2[4] = 0;
    for(int i=2; i<N; i++){
        f[i] = f[i-1]+f[i-2];
        F[i] = F[i-1]+f[i];
        if(i >= 5){
            f2[i] = f2[i-1] + f2[i-2] + f[i-3];
            F2[i] = F2[i-1] + f2[i];
        }
    }
}

int find_lower_fibonacci(ull n){
    int lo = 0;
    int hi = N-1;
    while(lo < hi){
        int me = lo + (hi - lo + 1)/2;
        if(f[me] <= n) lo = me;
        else hi = me-1;
    }
    return lo;
}

ull G(ull n){
    int pos = find_lower_fibonacci(n);
    ull ans = F[pos] + F2[pos] - 1;
    n -= f[pos];
    while(n){
        if(n >= f[pos] - f[pos-1] - 1){
            ans += f2[pos];
            n -= (f[pos] - f[pos-1] - 1);
            if(n){
                n--;
                ans += f[pos-2];
            }
        }
        else pos--;
    }
    return ans;
}

int main(){
    memset(dp, -1, sizeof(dp));
    gen_fibonacci();
    // for(int i=1; i<100; i++){
    //     // cout << "H(" << i << ") = " << H(i) << '\n';
    //     if(i == H(i)){
    //         cout << i << '\n';
    //     }
    //     else{
    //         cout << H(i) << ' ';
    //     }
    // }
    cout << G(23416728348467685) << '\n';
    return 0;
}