#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX (1LL<<60)
vector <ll> P[65];
void fill(){
    for(int j=0; j<=1000000; j++)
        P[3].push_back(1LL*j*j*j);
    for(int i=4; i<65; i++){
        for(int j=0; j<P[i-1].size(); j++){
            ll v = P[i-1][j];
            if(1LL*v*j >= MAX) break;
            P[i].push_back(1LL*v*j);
        }
    }
}

void solve(ll H, ll n, ll &N, ll &k){
    if(H-n == 1){
        N = n;
        k = 1;
        return;
    }
    for(int i=3; i<=64; i++){
        for(int j=1; j<P[i].size(); j++){
            if(P[i][j] > H or P[i][j-1] > n) break;
            if(P[i][j] == H && P[i][j-1] == n){
                N = j-1;
                k = i;
                return;
            }
        }
    }
    k = 2;
    ll diff = H-n;
    N = (diff - 1)/2;
    return;
}

int main(){
    fill();
    // H = (N+1)^k
    // n = N^k
    // 1 + N + N^2 + ... + N^k-1 = (N^k - 1)/(N-1)
    // (N+1)^k + N*(N+1)^(k-1) + ... = ((N+1)^(k+1) - 1)/(N+1 - 1) = (H*(N+1) - 1)/ N
    // 216*(6) - 1 / 5 = 1295/5 = 259
    ll H, n;
    while(cin >> H >> n){
        if(H == 0 and n == 0) break;
        if(H == n){
            cout << "0 1\n";
            continue;
        }
        ll N, k;
        solve(H, n, N, k);
        ll ans = 0;
        ll v = H;
        ll coeff = 1;
        for(int i=k; i>=0; i--){
            ans += v*coeff;
            v /= (N+1);
            coeff *= N;
        }
        ll aux = 0;
        if(N == 1) aux = k;
        else aux = (n-1)/(N-1);
        cout << aux << " " << ans << '\n';
    }
    return 0;
}