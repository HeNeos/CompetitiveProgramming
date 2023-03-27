#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll binomial(int x, int y){
    ll ans = 1;
    for(int i=x-y+1; i<=x; i++){
        ans *= i;
        ans /= (i-(x-y));
    }
    return ans;
}

int main(){
    ll power_10 = 1;
    for(int i=1; i<=100; i++){
        power_10 *= 10;
        int n = i;
        ll ans = power_10 - binomial(n+10, 10) - binomial(n+9, 9) + 10*n + 1;
        cout << i << ": " << (power_10-1) - ans << '\n';
    }
    return 0;
}