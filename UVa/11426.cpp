#include <bits/stdc++.h>
using namespace std;

#define N 4000005

vector <pair <int, int> > mb;

int lpf[N];
void sieve(){
    for(int i=2; i<N; i++){
        if(!lpf[i]){
            lpf[i] = i;
            for(long long j=1LL*i*i; j<N; j+=i){
                if(lpf[j] == 0) lpf[j] = i;
            }
        }
    }
}

int mobius[N];

void cmob(){
    mobius[1] = 1;
    for(int i=2; i<N; i++){
        if(lpf[i] == i) mobius[i] = -1;
        else{
            if(lpf[i/lpf[i]] == lpf[i]) mobius[i] = 0;
            else mobius[i] = -1*mobius[i/lpf[i]];
        }
    }
    for(int i=1; i<N; i++){
        if(mobius[i] != 0) mb.push_back(make_pair(i, mobius[i]));
    }
}

int main(){
    sieve();
    cmob();
    while(true){
        int n; cin >> n;
        if(n == 0) break;
        unsigned long long ans1 = 0;
        unsigned long long ans2 = (1LL*n*(n+1))/2;
        for(int k=1; k<=n; k++){
            long long aux = 0;
            for(int i=0; i<mb.size(); i++){
                int index = mb[i].first;
                int value = mb[i].second;
                if(index > n/k) break;
                aux += 1LL*value*((n/k)/index)*((n/k)/index);
            }
            if(aux < 0){
                aux *= -1;
                ans2 += 1LL*k*aux;
            }
            else ans1 += 1LL*k*aux;
        }
        ans1 /= 2; ans2 /= 2;
        ans1 = ans1 - ans2;
        cout << ans1 << '\n';
    }
    return 0;
}