#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define MOD 1000000007
#define N 50005

bool isPrime[N];
vector <int> primes;
void sieve(){
    for(int i=2; i<N; i++){
        if(!isPrime[i]){
            primes.push_back(i);
            for(ll j=1LL*i*i; j<N; j+=i) isPrime[j] = 1;
        }
    }
}

vector <int> primeDiv(int n){
    vector <int> ans;
    for(int i=0; i<primes.size(); i++){
        if(primes[i] > n) break;
        int aux_n = n;
        int cont = 0;
        while(aux_n != 0){
            aux_n /= primes[i];
            cont += aux_n;
        }
        ans.push_back(cont);
    }
    return ans;
}

long long solve(int n){
    vector <int> f = primeDiv(n);
    long long ans = 1;
    for(auto v: f){
        ans *= (v+1);
        ans %= MOD;
    }
    return ans;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << solve(n) << '\n';
    }
    return 0;
}