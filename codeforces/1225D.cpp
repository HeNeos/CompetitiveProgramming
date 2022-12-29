#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define N 100005
int lpf[N];

void sieve(){
    for(int i=2; i<N; i++){
        if(lpf[i] == 0){
            lpf[i] = i;
            for(ll j=2*i; j<N; j+=i){
                if(lpf[j] == 0) lpf[j] = i;
            }
        }
    }
}

vector <pair <int, int> > get_factorization(int n, int k){
    vector <pair <int, int> >  ans;
    while(n > 1){
        int d = lpf[n];
        int c = 0;
        while(n%d == 0){
            n /= d;
            c++;
        }
        c %= k;
        if(c != 0) ans.push_back(make_pair(d, c));
    }
    return ans;
}

int main(){
    sieve();
    int n, k; cin >> n >> k;
    int arr[n];
    map <vector <pair <int, int> >, int> m;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        m[get_factorization(arr[i], k)]++;
    }
    ll ans = 0;
    for(auto it: m){
        vector <pair <int, int> > factorization = it.first;
        int cont = it.second;
        vector <pair <int, int> > complement;
        for(pair <int, int> f: factorization){
            complement.push_back(
                make_pair(f.first, k-f.second)
            );
        }
        int c = m[complement];
        if(factorization == complement)
            ans += 1LL*c*(c-1);
        else
            ans += 1LL*c*cont;
    }
    cout << ans/2;
    return 0;
}