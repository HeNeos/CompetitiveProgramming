#include <bits/stdc++.h>
using namespace std;
int prim[100005];
long long fastexp(long long a, long long b){
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2 == 0){
        long long aux = fastexp(a,b/2);
        return 1LL*aux*aux;
    }
    long long aux = fastexp(a,(b-1)/2);
    return 1LL*a*aux*aux;
}
void lpf(){
    for(int i=0; i<100005; i++) prim[i] = 0;
    for(int i=2; i<100005; i++){
        if(!prim[i]){
            for(int j=1; 1LL*j*i<100005; j++){
                if(!prim[1LL*i*j]) prim[1LL*i*j] = i;
            }
        }
    }
}
int mobius[100005];
void cmob(){
    mobius[1] = 1;
    for(int i=2; i<100005; i++){
        if(prim[i] == i) mobius[i] = -1;
        else{
            if(prim[i/prim[i]] == prim[i]) mobius[i] = 0;
            else mobius[i] = -1*mobius[i/prim[i]];
        }
    }
}
int main(){
    lpf();
    cmob();
    int t;
    cin >> t;
    for(int i=1; i<=t; i++){
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        if(k==0){
            cout << "Case " << i << ": " << 0 << '\n';
            continue;
        }
        long long answ = 0;
        for(int j=1; j<=b/k; j++){
            answ = answ + 1LL*mobius[j]*((b/k)/j)*((d/k)/j);
        }
        long long answ2 = 0;
        for(int j=1; j<=min(b,d)/k; j++){
            answ2 = answ2 + 1LL*mobius[j]*((min(b,d)/k)/j)*((min(b,d)/k)/j);
        }
        answ = answ-answ2/2;
        cout << "Case " << i << ": " << answ << '\n';
    }
    return 0;
}
