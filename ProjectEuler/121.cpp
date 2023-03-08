#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define N 15

ll f[N+5];
void factorial(){
    f[0] = 1;
    for(int i=1; i<N+5; i++) f[i] = f[i-1]*i;
}

vector < vector <ll> > dp;

void fill(){
    dp.push_back({1});
    for(int i=1; i<=N; i++){
        vector <ll> aux;
        for(int j=0; j<=i; j++){
            ll temp = 0;
            if(j < i) temp = dp[i-1][j] * i;
            if(j > 0) temp += dp[i-1][j-1];
            aux.push_back(temp);
        }
        dp.push_back(aux);
    }

}

int main(){
    factorial();
    fill();
    ll n = 0;
    for(int i=N/2+1; i<=N; i++) n += dp[N][i];
    ll m = f[N+1];
    cout << m/n << '\n';
    return 0;
}