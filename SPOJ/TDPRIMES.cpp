#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define N 100000003
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
int main(){
    sieve();
    for(int i=1; i<100000000; i+=100){
        if(i-1 >= pr.size()) break;
        printf("%d\n",pr[i-1]);
    }
    return 0;
}