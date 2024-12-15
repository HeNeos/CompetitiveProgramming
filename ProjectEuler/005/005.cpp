#include <iostream>
#include <algorithm>
#include <math.h>
#include <numeric>
using namespace std;
using ll = long long;

template<typename T>
inline T gcd(T a, T b){
    T c;
    while (b)
    {
        c = b;
        b = a % b;
        a = c;
    }
    return a;
}

ll lcm(ll a, ll b){
    ll g = gcd(a, b);
    return 1LL*a/g*b;
}

int main(){
    ll ans = 1;
    for(int i=2; i<=20; i++)
        ans = lcm(ans, i);
    cout << ans << '\n';
    return 0;
}