#include <bits/stdc++.h>
using namespace std;

#define N 20000005
using ll = long long;

bitset <N> primes;
vector <int> p;
vector <int> twin_primes;
void sieve(){
    for(int i=2; i<N; i++){
        if(!primes[i]){
            p.push_back(i);
            for(ll j=1LL*i*i; j<N; j+=i) primes[j] = 1;
        }
    }
    for(int i=1; i<p.size(); i++){
        if(p[i] - p[i-1] == 2)
            twin_primes.push_back(p[i-1]);
    }
}

int main(){
    sieve();
    int s;
    while(cin >> s){
        cout << "(" << twin_primes[s-1] << ", " << twin_primes[s-1]+2 << ")\n";
    }
    return 0;
}