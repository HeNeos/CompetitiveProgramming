#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
bool aux[40005];
vector <int> prim;
void sieve(){
    for(int i=0; i<40005; i++){
        aux[i] = true;
    }
    for(int i=2; i<40005; i++){
        if(aux[i]){
            for(long long j=1LL*i*i; j<40005; j=j+i) aux[j] = false;
        }
    }
    for(int i=2; i<40005; i++){
        if(aux[i]) prim.push_back(i);
    }
}
long long fastexp(long long a, long long n){
    if(n == 0) return 1;
    if(n == 1) return a%mod;
    if(n%2 == 0){
        long long x = (1LL*fastexp(a,n/2))%mod;
        return (1LL*x*x)%mod;
    }
    long long x = (1LL*fastexp(a,(n-1)/2))%mod;
    return ((1LL*(1LL*x*x)%mod)*a)%mod;
}
int main(){
    int x;
    long long n;
    cin >> x >> n;
    sieve();
    vector <int> divisors;
    for(int i=0; i<prim.size(); i++){
        if(x%prim[i] == 0){
            divisors.push_back(prim[i]);
            while(x%prim[i] == 0) x = x/prim[i];
        }
    }
    if(x > 1) divisors.push_back(x);
    long long outp = 1;
    for(int i=0; i<divisors.size(); i++){
        long long gg = n;
        vector <long long> answ;    
        while(gg > 0){
            answ.push_back(gg);
            gg = gg/divisors[i];
        }
        for(int j=0; j<answ.size()-1; j++) answ[j] = answ[j]-answ[j+1];
        for(int j=0; j<answ.size(); j++) outp = 1LL*outp*fastexp(divisors[i],1LL*j*answ[j])%mod;
    }
    cout << outp;
    return 0;
}
