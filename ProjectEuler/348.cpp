#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// #define N 10000000
// #define M 1000000

#define N 29000
#define M 800

ll pow_2[N];
ll pow_3[M];

map <ll, int> m;

bool is_palindrome(ll x){
    string s = to_string(x);
    for(int l=0, r=s.size()-1; l<r; l++, r--){
        if(s[l] != s[r]) return false;
    }
    return true;
}


void fill(){
    for(int i=1; i<N; i++) pow_2[i] = 1LL*i*i;
    for(int i=1; i<M; i++) pow_3[i] = pow_2[i] * i;
}

ll solve(){
    for(int i=2; i<N; i++){
        for(int j=2; j<M; j++){
            ll sum = pow_2[i] + pow_3[j];
            if(m.find(sum) == m.end()){
                if(is_palindrome(sum)) m[sum]++;
            }
            else m[sum]++;
        }
    }
    int c = 0;
    ll ans = 0;
    for(auto v: m){
        if(c == 5) break;
        if(v.second == 4){
            ans += v.first;
            c++;
        }
    }
    return ans;
}

int main(){
    fill();
    cout << solve() << '\n';
    return 0;
}