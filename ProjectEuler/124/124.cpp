#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define N 100001
int lpf[N];
pair <int, int> t[N];
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

void build(){
    for(int i=1; i<N; i++){
        int aux = i;
        int p = 1;
        while(aux > 1){
            int d = lpf[aux];
            p *= d;
            while(aux%d == 0)
                aux /= d;
        }
        t[i].first = p;
        t[i].second = i;
    }
}

int main() {
    sieve();
    build();
    sort(t+1, t+N);
    cout << t[10000].first << " " << t[10000].second;
    return 0;
}
