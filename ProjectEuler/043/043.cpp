#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll ans = 0;
int primes[7] = {17, 13, 11, 7, 5, 3, 2};
int inv[7] = {8, 3, 1, 4, -1, 1, -1};
int pot10[8] = {100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

void solve(int pos, int suff, bitset <10> check, ll current){
    if(pos == 7){
        for(int i=0; i<10; i++){
            if(!check[i]){
                ans += current+1LL*pot10[pos]*i;
                return;
            }
        }
    }
    if(inv[pos] == -1){
        if(suff%primes[pos] != 0) return;
        for(int i=0; i<10; i++){
            if(check[i]) continue;
            check[i] = 1;
            solve(pos+1, i*10+suff/10, check, current + 1LL*i*pot10[pos]);
            check[i] = 0;
        }
    }
    else{
        int m = (primes[pos]-(suff%primes[pos]))%primes[pos];
        int x = (m*inv[pos])%primes[pos];
        int nextValue = x;
        while(nextValue < 10){
            if(!check[nextValue]){
                check[nextValue] = 1;
                solve(pos+1, nextValue*10+suff/10, check, current + 1LL*nextValue*pot10[pos]);
                check[nextValue] = 0;
            }
            nextValue += primes[pos];
        }
    }
}

int main(){
    for(int i=17; i<1000; i+=17){
        bitset <10> check;
        int f = i%10; int s = (i%100)/10; int t = i/100; 
        if(f == s or s == t or f == t) continue;
        check[f] = 1; check[s] = 1; check[t] = 1;
        solve(1, i/10, check, 1LL*i);
    }
    cout << ans;
    return 0;
}
