#include <iostream>
using namespace std;

#define N 1000005

long long divisors[N];
long long dp[N];
void sieve(){
    for(int i=1; i<N; i++){
        divisors[i] -= i;
        for(long long j=i; j<N; j+=i){
            divisors[j] += i;
        }
    }
}

void fill(){
    dp[1] = 0;
    for(int i=2; i<N; i++)
        dp[i] = dp[i-1] + divisors[i];
}

int main(){
    sieve();
    fill();
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}