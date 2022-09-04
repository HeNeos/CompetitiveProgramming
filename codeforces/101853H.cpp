#include <iostream>
using namespace std;

int findSqrt(int x){
    int lo = 0;
    int hi = x;
    while(lo < hi){
        int me = lo + (hi-lo)/2;
        if(1LL*me*me >= x) hi = me;
        else lo = me + 1;
    }
    return hi;
}

int main(){
    int t; cin >> t;
    while(t--){
        int x; cin >> x;
        x /= 6;
        cout << findSqrt(x) << '\n';
    }
    return 0;
}