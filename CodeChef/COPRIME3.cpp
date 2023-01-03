#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define FIFO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define MOD 1000000007
typedef long long ll;
#define N 1000010 //1e6
ll divisible[N];
int n;
vector <int> inp;
map <int,int> amount;

int pr[N];

void sieve(){
    for(int i=2; i<N; i++){
        if(pr[i] == 0){
            pr[i] = i;
            for(ll j=1LL*i*i; j<N;j+=i){
                if(pr[j] == 0) pr[j] = i;
            }
        }
    }
}


int mobius[N];
int dp[N];
void cmb(){
    mobius[1] = 1;
    for(int i=2; i<N; i++){
        if(pr[i] == i) mobius[i] = -1;
        else{
            if(pr[i/pr[i]] == pr[i]) mobius[i] = 0;
            else mobius[i] = -1*mobius[i/pr[i]];    
        }
    }
}

void fill(){
    for(int i=1; i<N; i++){
        for(int j=i; j<N; j+=i) dp[i] += divisible[j];
    }
}

ll solve(){
    ll ans = 0;
    for(int i=1; i<N; i++){
        int count = dp[i];
        ll aux;
        if(count >= 3) aux = (1LL*count*(count-1)*(count-2))/6;
        else aux = 0;
        aux = aux*mobius[i];
        ans += aux;
    }
    return ans;
}
int main(){
    FIFO;    
    sieve();
    cmb();
    cin >> n;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        inp.pb(a);
        divisible[a]++;
    }
    fill();
    
    ll ans = solve();
    cout << ans << '\n';
    return 0;
}
