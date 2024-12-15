#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define N 1000000000000000

ll solve(ll n){
    ll pos = 5;
    ll current = 14;
    ll previous = 13;
    ll current_length = 1;
    while(true){
        if(pos >= n) break;
        pos += 1;
        if(1LL*current_length*current_length >= pos){
            pos -= (current_length + 1);
            current -= (current_length + 1);
            current += pos-1;
            pos = 2*pos - 2;
            current_length = 0;
            continue;
        }
        previous = current;
        current += __gcd(pos, current);
        if(current - previous == 1)
            current_length++;
        else current_length = 0;
    }
    return current-pos+n;
}

int main(){
    cout << solve(N) << '\n';
    return 0;
}