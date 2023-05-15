#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int lo = 1;
    int hi = 5000;
    while(lo < hi){
        int me = lo + (hi-lo)/2;
        int ans = 0;
        for(int a=1; a<=me; a++){
            for(int x=2; x<=2*a; x++){
                if(a >= x/2){
                    ll current = a*a + x*x;
                    if((ll)sqrt(current)*(ll)sqrt(current) == current){
                        ans += x/2;
                        if(x-1 > a) ans -= x-1-a;
                    }
                }
            }
        }
        if(ans >= 1000000) hi = me;
        else lo = me + 1;
    }
    cout << lo << '\n';
    return 0;
}