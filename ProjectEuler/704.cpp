#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
    Sum F(n) from 1 to 10^16
    F(n) = max(g(n, m)) for all m from 1 to n
    g(n, m) = max power of 2 that divides n bin m
*/

int g(int n, int m){
    int ans = 0;
    int diff = n-m;
    while(diff > 1){
        ans -= diff/2;
        diff /= 2;
    }
    while(n > 1){
        ans += n/2;
        n /= 2;
    }
    while(m > 1){
        ans -= m/2;
        m /= 2;
    }
    return ans;
    
}

int count(int x){
    int ans = 0;
    while(x > 1){
        x /= 2;
        ans++;
    }
    return ans;
}

int F(int n){
    int b = count(n);
    int v = (1<<b);
    if(n == v) return b;
    else if(n == 2*v - 1) return 0;
    else return g(n, n-v+1);        
}

#define N 100

int main(){
    //__builtin_ctz(x);
    int ans = 0;
    for(int i=1; i<=N; i++){
        int v = F(i);
        ans += v;
        cout << i << ": " << v << " " << ans << '\n';
    }
    cout << "\nSum: " << ans << '\n';
    return 0;
}