#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define N 100005
int lpf[N];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll a, ll b){return uniform_int_distribution<ll>(a, b)(rng);}

ll fastexp(ll x, ll y, ll p){
    ll ans = 1;
    while(y > 0){
        if(y&1) ans = (ans*x)%p;
        y = y>>1;
        x = (x*x)%p;
    }
    return ans%p;
}

ll fastexp2(ll x, ll y){
    ll ans = 1;
    while(y > 0){
        if(y&1) ans = (ans*x);
        y = y>>1;
        x = (x*x);
    }
    return ans;
}

pair <ll, ll> multiply(pair <ll, ll> a, pair <ll, ll> b){
    pair <ll, ll> ans;
    ll x3 = a.first * b.first - a.second * b.second;
    ll y3 = a.first * b.second + a.second * b.first;
    ans.first = x3;
    ans.second = y3;
    return ans;
}

void sieve(){
    for(int i=2; i<N; i++){
        if(!lpf[i]){
            lpf[i] = i;
            for(ll j=1LL*i*i; j<N; j+=i){
                if(lpf[j] == 0) lpf[j] = i;
            }
        }
    }
}

vector <pair <int, int> > get_factorization(ll n){
    vector <pair <int, int> > ans;
    if(n%2 == 0){
        int e = 0;
        while(n%2 == 0){
            e++;
            n /= 2;
        }
        ans.push_back(make_pair(2, e));
    }
    while(n != 1){
        int d = lpf[n];
        if(n%d == 0){
            int e = 0;
            while(n%d == 0){
                e++;
                n /= d;
            }
            ans.push_back(make_pair(d, e));
        }
    }
    return ans;
}

bool check(vector <pair <int, int> > &f){
    for(int i=0; i<f.size(); i++){
        if(f[i].first % 4 == 3){
            if(f[i].second % 2 != 0) return false;
        }
    }
    return true;
}

ll legendre(ll a, ll p){
    if(a%p==0)return 0; if(p==2)return 1;
    return fastexp(a,(p-1)/2,p);
}

ll tonelli_shanks(ll n, ll p){    // sqrt(n) mod p (p must be a prime)
    assert(legendre(n,p)==1); if(p==2)return 1;
    ll s=__builtin_ctzll(p-1), q=(p-1LL)>>s, z=rnd(1,p-1);
    if(s==1)return fastexp(n,(p+1)/4LL,p);
    while(legendre(z,p)!=p-1)z=rnd(1,p-1);
    ll c=fastexp(z,q,p), r=fastexp(n,(q+1)/2,p), t=fastexp(n,q,p), m=s;
    while(t!=1){
        ll i=1, ts=(t*t)%p;
        while(ts!=1)i++,ts=(ts*ts)%p;
        ll b=c; 
        for(int _=0; _<m-i-1; _++)b=(b*b)%p;
        r=r*b%p;c=b*b%p;t=t*c%p;m=i;
    }
    return r;
}

ll getSquare(ll n){
    ll lo = 0;
    ll hi = 40000000;
    while(lo < hi){
        ll me = lo + (hi - lo + 1)/2;
        if(me*me <= n) lo = me;
        else hi = me - 1;
    }
    return lo;
}

pair <int, int> solve(int p){
    int a = p;
    int b = tonelli_shanks(p-1, p);
    int l = getSquare(p);
    while(b > l){
        int r = a%b;
        a = b;
        b = r;
    }
    int c = (p-b*b);
    pair <int, int> ans;
    ans.first = b;
    ans.second = getSquare(c);
    return ans;
}

int main() {
    sieve();
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector <pair <int, int> > f = get_factorization(n);
        bool isPossible = check(f);
        if(!isPossible){
            cout << -1 << '\n';
            continue;
        }
        ll aux = 1;
        pair <ll, ll> aux2;
        aux2.first = 1;
        aux2.second = 0;
        for(int i=0; i<f.size(); i++){
            if(f[i].second %2 == 1){
                aux2 = multiply(aux2, solve(f[i].first));
                int rest = f[i].second-1;
                aux = aux*fastexp2(f[i].first, rest/2);
            }    
            else{
                aux = aux*fastexp2(f[i].first, f[i].second/2);
            }
        }
        
        aux2.first *= aux;
        aux2.second *= aux;
        
        cout << abs(aux2.first) << " " << abs(aux2.second) << '\n';
    }
    return 0;
}