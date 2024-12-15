#include <bits/stdc++.h>
using namespace std;

#define N 29000

int lpf[N];
void sieve(){
    lpf[0] = -1;
    lpf[1] = -1;
    for(int i=2; i<N; i++){
        if(lpf[i] == 0) lpf[i] = i;
        for(int j=i*i; j<N; j+=i){
            if(lpf[j] == 0) lpf[j] = i;
            else lpf[j] = min(i, lpf[j]);
        }
    }
}

int fastexp(int a, int b){
    if(b == 0) return 1;
    if(b == 1) return a;
    int aux = fastexp(a, b/2);
    aux = aux*aux;
    if(b%2 == 1) aux *= a;
    return aux;
}

int getDivisorsSum(int x){
    int ans = 1;
    while(x != 1){
        int d = lpf[x];
        int p = 0;
        while(x%d == 0){
            x /= d;
            p++;
        }
        ans *= (fastexp(d, p+1) - 1)/(d - 1);
    }
    return ans;
}

bitset <N> b;
vector <int> abundant;
void build(){
    for(int i=10; i<N; i++){
        int s = getDivisorsSum(i) - i;
        if(s > i){
            abundant.push_back(i);
        }
    }
}


int main(){
    sieve();
    build();
    int sz = abundant.size();
    for(int i=0; i<sz; i++){
        for(int j=0; j<sz; j++){
            int s = abundant[i] + abundant[j];
            if(s >= N) break;
            b[s] = 1;
        }
    }
    int ans = 0;
    for(int i=1; i<N; i++){
        if(b[i] == 0) ans += i;
    }
    cout << ans << '\n';
    return 0;
}
