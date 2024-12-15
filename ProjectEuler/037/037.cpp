#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define N 1000005

bitset <N> primes;
vector <int> pr;
void sieve(){
    primes[0] = 1;
    primes[1] = 1; 
    for(int i=2; i<N; i++){
        if(!primes[i]){
            pr.push_back(i);
            for(ll j=1LL*i*i; j<N; j+=i) primes[j] = 1;
        }
    }
}

bool solve(int x){
    string s = to_string(x);
    for(int i=1; i<=s.size(); i++){
        if(primes[stoi(s.substr(0, i))]) return false;
    }
    reverse(s.begin(), s.end());
    for(int i=1; i<=s.size(); i++){
        string aux = s.substr(0, i);
        reverse(aux.begin(), aux.end());
        if(primes[stoi(aux)]) return false;
    }
    return true;
}

int main() {
    sieve();
    int cont = 0;
    ll ans = 0;
    for(int i=4; i<pr.size(); i++){
        if(cont >= 11) break;
        if(solve(pr[i])){
            ans += pr[i];
            cont++;
        }
    }
    cout << ans << '\n';
    return 0;
}
