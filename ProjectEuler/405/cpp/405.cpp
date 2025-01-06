#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define N 2000000
#define MOD 410338673

vector <ll> PHI;
vector <int> primes;

int phi[N];
void cphi(){
    phi[1] = 1;
    for(int i=2; i<N; i++){
        if(!phi[i]){
            primes.push_back(i);
            phi[i] = i-1;
            for(ll j=2*i; j<N; j+=i){
                if(phi[j] == 0) phi[j] = j;
                phi[j] = phi[j]/i*(i-1);
            }
        }
    }
}

ll calculate_phi(ll n){
    if(n < N) return phi[n];
    ll n_copy = n;
    vector <ll> f_primes;
    for(auto p: primes){
        if(1LL*p*p > n_copy) break;
        if(n_copy%p == 0){
            while(n_copy%p == 0) n_copy /= p;
            f_primes.push_back(p);
        }
    }
    if(n_copy != 1) f_primes.push_back(n_copy);
    for(auto p: f_primes)
        n -= n/p;
    return n;
}


typedef vector<vector<ll> > Matrix;

//Matrix fibo(2, vector <ll>(2));
//fibo[0] = {1, 1}; fibo[1] = {1, 0};
//Matrix F = be(fibo, n);

Matrix f(6, vector <ll>(6));

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

ll fastexp(ll x, ll y, ll p){
    ll ans = 1;
    while(y > 0){
        if(y&1) ans = (ans*x)%p;
        y = y>>1;
        x = (x*x)%p;
    }
    return ans%p;
}

void fill_phi(int n){
    PHI.resize(n);
    PHI[0] = calculate_phi(MOD);
    for(int i=1; i<n; i++)
        PHI[i] = calculate_phi(PHI[i-1]);
}

int main(){
    cphi();
    f[0] = {4, 1, 0, 4, 0, -2};
    f[1] = {0, 1, 2, 0, 0, -2};
    f[2] = {0, 1, 0, 0, 0, 0};
    f[3] = {0, 0, 0, 1, 2, 1};
    f[4] = {0, 0, 0, 1, 0, 0};
    f[5] = {0, 0, 0, 0, 0, 1};

    Matrix r(6, vector <ll>(1));
    r[0] = {0}; r[1] = {4}; r[2] = {2}; r[3] = {0}; r[4] = {0}; r[5] = {1};

    vector <ll> input;
    ll x;
    while(cin >> x) input.push_back(x);
    fill_phi(input.size());
    ll exp = 1;
    ll previous = input.back();
    for(int i=input.size()-2; i>=0; i--){
        ll a = input[i];
        ll b = previous;
        previous = fastexp(a, b, PHI[i]);
    }
    ll n = previous;
    if(n == 0){
        cout << "-1\n";
        return 0;
    }
    Matrix F = be(f, n-1);
    F = F*r;

    cout << F[0][0] << '\n';
    return 0;
}