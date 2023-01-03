#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int MOD = 1000000007;

ll fastexpp(ll x, ll y, ll p){
    ll ans = 1;
    while(y > 0){
        if(y&1) ans = (ans*x)%p;
        y = y>>1;
        x = (x*x)%p;
    }
    return ans%p;
}


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
    while(e){if(e&1LL)r=r*b;b=b*b;e/=2;}
    return r;
}

int main(){
    ll n;
    int f1, f2, f3, c;
    ll exp_c, exp_f1, exp_f2, exp_f3;
    cin >> n >> f1 >> f2 >> f3 >> c;
    if(n == 4){
        ll ans = (1LL*c*c)%MOD;
        ans = (ans*f1)%MOD;
        ans = (ans*f2)%MOD;
        ans = (ans*f3)%MOD;
        cout << ans << endl;
        return 0;
    }
    if(n == 5){
        ll ans = fastexpp(c,6,MOD);
        ans = (ans*f1)%MOD;
        ans = (1LL*ans*(1LL*f2*f2)%MOD)%MOD;
        ans = (1LL*ans*(1LL*f3*f3)%MOD)%MOD;
        cout << ans << endl;
        return 0;
    }
    Matrix b(5,vector <ll>(5));
    Matrix b_f(3,vector <ll>(3));
    b[0] = {1,0,0,0,0};
    b[1] = {-1,1,0,0,0};
    b[2] = {0,0,0,1,0};
    b[3] = {0,0,0,0,1};
    b[4] = {6,2,1,1,1};
    MOD -= 1;
    Matrix c_exp = be(b,n-6);
    int p[5] = {-1,7,2,6,14};
    exp_c = 0;
    for(int i=0; i<5; i++)
        exp_c = (exp_c + (1LL*p[i]*c_exp[4][i])%MOD)%MOD;
    b_f[0] = {0,1,0};
    b_f[1] = {0,0,1};
    b_f[2] = {1,1,1};
    Matrix f_exp = be(b_f,n-6);
    vector <vector <int> > v(3,vector <int>(3));
    v[0] = {1,1,2};
    v[1] = {1,2,3};
    v[2] = {1,2,4};
    exp_f1=0; exp_f2=0; exp_f3=0;
    for(int i=0; i<3; i++){
        exp_f1 = (exp_f1 + (1LL*v[0][i]*f_exp[2][i])%MOD)%MOD;
        exp_f2 = (exp_f2 + (1LL*v[1][i]*f_exp[2][i])%MOD)%MOD;
        exp_f3 = (exp_f3 + (1LL*v[2][i]*f_exp[2][i])%MOD)%MOD;
    }
    MOD += 1;
    ll ans = 1;
    ans = (1LL*ans*fastexpp(f1,exp_f1,MOD))%MOD;
    ans = (1LL*ans*fastexpp(f2,exp_f2,MOD))%MOD;
    ans = (1LL*ans*fastexpp(f3,exp_f3,MOD))%MOD;
    ans = (1LL*ans*fastexpp(c,exp_c,MOD))%MOD;
    cout << ans << endl;;
    return 0;
}