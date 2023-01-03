#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define N 10005
#define FIFO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
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

int mobius[N];
vector <pair <int,int> > dat;
void cmob(){
    mobius[1] = 1;
    for(int i=2; i<N; i++){
        if(lpf[i] == i) mobius[i] = -1;
        else{
            if(lpf[i/lpf[i]] == lpf[i]) mobius[i] = 0;
            else mobius[i] = -1*mobius[i/lpf[i]];
        }
        if(mobius[i] != 0) dat.push_back(make_pair(mobius[i],i));
    }
}

vector <int> divisors[N];

void solve(){
    for(int i=2; i<N; i++){
        for(int j=1; j*j<=i; j++){
            if(i%j == 0){
                if(mobius[j] != 0) divisors[i].push_back(j);
                if(i/j != j){
                    if(mobius[i/j] != 0) divisors[i].push_back(i/j);
                }
            }
        }
    }
}

int main(){
    FIFO;
    sieve();
    cmob();
    solve();
    int n;
    while(cin >> n){
        int arr[n];
        for(int i=0; i<n; i++) cin >> arr[i];
        int maxi = *max_element(arr, arr + n);
        ll ans = (1LL*n*(n-1)*(n-2)*(n-3))/24;
        int VALUES[N];
        for(int i=0; i<N; i++) VALUES[i] = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<divisors[arr[i]].size(); j++)
                VALUES[divisors[arr[i]][j]]++;
        }
        for(int i=0; i<dat.size(); i++){
            if(dat[i].second > maxi) break;
            ll aux = VALUES[dat[i].second];
            ans += 1LL*dat[i].first*(1LL*aux*(aux-1)*(aux-2)*(aux-3))/24;
        }
        cout << ans << '\n';
    }
    return 0;
}