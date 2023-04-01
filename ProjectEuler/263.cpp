#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;
#define N 230000005

int lpf[N];
vi primes;
int pi[N];
vi possible_ans;

ll fastexp(ll x, ll y){
    ll ans = 1;
    while(y > 0){
        if(y&1) ans = (ans*x);
        y = y>>1;
        x = (x*x);
    }
    return ans;
}

void sieve(){
    for(int i=2; i<N; i++){
        if(!lpf[i]){
            primes.push_back(i);
            lpf[i] = i;
            pi[i] = pi[i-1]+1;
            for(ll j=1LL*i*i; j<N; j+=i){
                if(lpf[j] == 0) lpf[j] = i;
            }
        }
        else pi[i] = pi[i-1];
    }
    for(auto p: primes){
        if(p%60 == 11 or p%60 == 31){
            if(lpf[p+6] == p+6 and lpf[p+12] == p+12 and lpf[p+18] == p+18){
                if(pi[p+6] - pi[p] == 1 and pi[p+12] - pi[p+6] == 1 and pi[p+18] - pi[p+12] == 1){
                    possible_ans.push_back(p+9);
                }
            }
        }
    }
}

vll factorize(ll n){
    vll ans;
    while(n>1){
        int d = lpf[n];
        int c = 0;
        while(n%d == 0){
            c++;
            n /= d;
        }
        ans.push_back(make_pair(d, c));
    }
    return ans;
}

bool is_practical(ll n){
    vll factors = factorize(n);
    ll current_sum = (fastexp(factors[0].first, factors[0].second+1)-1)/(factors[0].first-1);
    for(int i=1; i<factors.size(); i++){
        int p = factors[i].first;
        int a = factors[i].second;
        if(p > 1 + current_sum){
            return false;
            break;
        }
        current_sum *= (fastexp(p, a+1) - 1)/(p-1);
    }
    return true;
}

int main(){
    sieve();
    for(auto pr: possible_ans){
        ll value = pr;
        bool take = true;
        for(int i=-8; i<=8; i+=4){
            if(!is_practical(value+i)){
                take = false;
                break;
            }
        }
        if(take){
            cout << value << '\n';
        }
    }
    return 0;
}