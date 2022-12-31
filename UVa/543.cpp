#include <bits/stdc++.h>
using namespace std;

#define N 1000005
using ll = long long;

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

void solve(int n){
    int a = -1; int b = -1;
    for(int i=1; i<p.size(); i++){
        if(n-p[i] < p[i]) break;
        if(!primes[n - p[i]]){
            a = p[i];
            b = n-p[i];
            break;
        }
    }
    if(a == -1 and b == -1)
        cout << "Goldbach\'s conjecture is wrong.\n";
    else
        cout << n << " = " << a << " + " << b << '\n';
}

int main(){
    sieve();
    int n;
    while(cin >> n){
        if(n == 0) break;
        solve(n);
    }
    return 0;
}