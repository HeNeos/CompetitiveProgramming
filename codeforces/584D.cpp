#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define N 100005

bitset <N> primes;
vector <int> pr;
void sieve(){
    for(int i=2; i<N; i++){
        if(!primes[i]){
            pr.push_back(i);
            for(ll j=1LL*i*i; j<N; j+=i) primes[j] = 1;
        }
    }
}

int TestMillerRabin[12] = {2,3,5,7,11,13,17,19,23,29,31,37};

ll mulmod(ll a, ll b, ll p){
    ll x = 0, y = a%p;
    while(b>0){
        if(b%2==1) x = (x+y)%p;
        y = (1LL*y*2)%p;
        b = b/2;
    }
    return x%p;
}

ll fastexpp(ll x, ll y, ll p){
    ll ans = 1;
    while(y > 0){
        if(y&1) ans = mulmod(ans,x,p);
        y = y>>1;
        x = mulmod(x,x,p);
    }
    return ans%p;
}


//Change fastexpp to fastexp for small numbers :)
bool check_composite(ll n, ll a, ll d, int s){
    ll x = fastexpp(a,d,n);
    if(x == 1 || x == n-1) return false;
    for(int r=1; r<s; r++){
        x = (1LL*x*x)%n;
        if(x == n-1) return false;
    }
    return true;
}

bool isPrime(ll p){
    if(p<=1) return false;
    int r = 0;
    ll d = p-1;
    while(!(d&1)){
        d >>= 1;
        r++;
    }
    for(int i=0; i<12; i++){
        int value = TestMillerRabin[i];
        if(p == value) return true;
        if(check_composite(p,value,d,r)) return false;
    }
    return true;
}

int main() {
    sieve();
    int n; cin >> n;
    if(isPrime(n)){
        cout << "1\n" << n << endl;
    }
    else{
        if(isPrime(n-2)){
            cout << "2\n2 " << n-2 << endl;
        }
        else{
            for(int i=0; i<pr.size(); i++){
                if(isPrime(n-3-pr[i])){
                    cout << 3 << endl;
                    cout << 3 << " " << pr[i] << " " << n-3-pr[i] << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}