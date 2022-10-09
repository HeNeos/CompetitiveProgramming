#include <bits/stdc++.h>
using namespace std;

int powers[10][7];

void fill(){
    for(int i=0; i<10; i++) powers[i][0] = 1;
    for(int i=0; i<10; i++){
        for(int j=1; j<7; j++) powers[i][j] = powers[i][j-1]*i;
    }
}

int find_sum(int x, int n){
    int ans = 0;
    while(x > 0){
        int d = x%10;
        x /= 10;
        ans += powers[d][n];
    }
    return ans;
}

int main() {
    fill();
    int n; cin >> n;
    // k*9^N > 10^k-1 -> N*log_10(9) > log_10((10^k-1)/k) -> N*log_10(9) > k - log_10(k)
    // N = 3 -> 3 > (k - log_10(k))*log_9(10)
    // k = N + log_10(N) -> 
    // N = 3, k = 4
    // N = 4, k = 5
    // N = 5, k = 6
    // N = 6, k = 7
    int max_value = (n+1)*(powers[9][n]);
    long long ans = 0;
    for(int i=10; i<=max_value; i++){
        if(find_sum(i, n) == i) ans += i;
    }
    cout << ans << '\n';
    return 0;
}
