#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define N 1000005
bitset <N> primes;
vector <int> p;
void sieve(){
    for(int i=2; i<N; i++){
        if(!primes[i]){
            p.push_back(i);
            for(ll j=1LL*i*i; j<N; j+=i) primes[j] = 1;
        }
    }
}

bool solve(int x){
    string s = to_string(x);
    int sz = s.size();
    s += s;
    for(int i=0; i<sz; i++){
        int n = stoi(s.substr(i, sz));
        if(primes[n]) return false;
    }
    return true;
}

int main() {
    sieve();
    int n; cin >> n;
    ll ans = 0;
    for(auto v:p){
        if(v >= n) break;
        if(solve(v))
            ans += v;
    }
    cout << ans << '\n';
    return 0;
}
