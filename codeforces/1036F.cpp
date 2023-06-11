#include <bits/stdc++.h>
using namespace std;
int prim[100];
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
    for(int i=0; i<100; i++) prim[i] = 0;
    for(int i=2; i<100; i++){
        if(!prim[i]){
            for(int j=1; j*i<100; j++){
                if(!prim[i*j]) prim[i*j] = i;
            }
        }
    }
}
int mobius[100];
void cmob(){
    mobius[1] = 1;
    for(int i=2; i<100; i++){
        if(prim[i] == i) mobius[i] = -1;
        else{
            if(prim[i/prim[i]] == prim[i]) mobius[i] = 0;
            else mobius[i] = -1*mobius[i/prim[i]];
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lpf();
    cmob();
    int t;
    cin >> t;
    while(t--){
      long long n;
      cin >> n;
      long long answ = 0;
      for(int i=1; i<=68; i++){
            long long aux = (long long)floor(pow(n,1.0/i));
        long long lo = max(aux-100,0LL);
              long long hi = min(aux+100,(long long) pow(10,18.0/i));
              while(lo < hi){
                  long long me = lo + (hi-lo+1)/2;
                  long long gg = fastexp(me,i);
                  if(gg <= n) lo = me;
                  else hi = me-1;
              }
            aux = lo;
            if(aux == 0) break;
        answ = answ + (mobius[i]*(aux-1));
      }
      cout << answ << '\n';
    }
    return 0;
}
