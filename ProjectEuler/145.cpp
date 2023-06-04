#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int pow_10[9] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};

int reverse_n(int x){
    int ans = 0;
    while(x > 0){
        ans *= 10;
        ans += x%10;
        x /= 10;
    }
    return ans;
}

bool check(int x){
    int a = x;
    int b = reverse_n(a);
    int n = a+b;
    while(n>0){
        int d = n%10;
        n /= 10;
        if(d%2 == 0) return false;
    }
    return true;
}

int count(int n, int a0, int a1, int an_1, int an){
    int ans = 0;
    for(int i=0; i<pow_10[n]; i++){
        int x = i*100+an_1*10+an;
        x += a1*pow_10[n+2] + a0*pow_10[n+3];
        if(check(x)) ans++;
    }
    return ans;
}

int main(){
    ll ans = 0;
    for(int i=1; i<10000; i++){
        if(i%10 == 0) continue;
        if(check(i)) ans++;
    }
    for(int n=5; n<=9; n++){
        int b_digits = n-4;
        for(int a0=1; a0<=9; a0++){
            for(int a1=0; a1<=9; a1++){
                for(int an=1+(a0&1); an<=9; an+=2){
                    int aux = 1 - ((a0+an)/10 + a1)&1;
                    for(int an_1=aux; an_1<=9; an_1+=2){
                        ans += count(b_digits, a0, a1, an_1, an);
                    }
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}