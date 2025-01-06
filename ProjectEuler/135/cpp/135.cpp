#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define N 8000005

int lpf[N];
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

void getFactorization(int n, vector <pair <int, int> > &f){
    while(n > 1){
        int d = lpf[n];
        f.push_back(make_pair(d, 0));
        while(n%d == 0){
            n /= d;
            f[f.size()-1].second++;
        }
    }
}

void generate_divisors(int n, int index, int d, vector<pair <int,int> > &factorization, vector <int> &ans){ 
    if(1LL*d*d > n) return;
    
    if(index == factorization.size()){
        ans.push_back(d);
        if(d*d != n) ans.push_back(n/d); 
        return;
    }
    for(int i = 0; i <= factorization[index].second; ++i){
        generate_divisors(n, index+1, d, factorization, ans); 
        d *= factorization[index].first;
    }
}

int solve(int n){
    int ans = 0;
    vector <pair <int, int> > f;
    getFactorization(n, f);
    vector <int> d;
    generate_divisors(n, 0, 1, f, d);
    for(auto div:d){
        ll v = n+1LL*div*div;
        v /= div;
        if(v%4 == 0 && v/4 < div) ans++;
    }
    return ans;
}

int main() {
    sieve();
    int ans = 0;
    for(int i=2; i<1000000; i++){
        if(solve(i) == 10) ans++;
    }
    cout << ans << '\n';
    return 0;
}
