#include <bits/stdc++.h>
using namespace std;
using ll = __int128;

#define MOD 1234567891011

typedef vector<vector<ll> > Matrix;
Matrix ones(int n) {
    Matrix r(n,vector<ll>(n));
    for(int i=0; i<n; i++) r[i][i]=1;
    return r;
}
Matrix operator*(Matrix &a, Matrix &b){
    int n=a.size(),m=b[0].size(),z=a[0].size();
    Matrix r(n,vector<ll>(m));
    for(int i=0; i<n; i++)for(int j=0; j<m; j++)for(int k=0; k<z; k++)
        r[i][j]+=a[i][k]*b[k][j],r[i][j]%=MOD;
    return r;
}
Matrix be(Matrix b, ll e) {
    Matrix r=ones(b.size());
    while(e){if(e&1LL)r=r*b;b=b*b;e>>=1;}
    return r;
}    

ll fib(ll n){
    Matrix fibo(2, vector <ll>(2));
    fibo[0] = {1, 1};
    fibo[1] = {1, 0};
    Matrix F = be(fibo, n);
    return F[1][0]%MOD;
}

int main(){
    unsigned long long p;
    ll ans = 0;
    while(cin >> p){
        ans += fib(p);
        ans %= MOD;
    }
    unsigned long long out = ans;
    cout << out << '\n';
    return 0;
}