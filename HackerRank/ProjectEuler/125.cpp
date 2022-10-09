#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isPalindrome(int x){
    int n = x;
    int t = 0;
    while(n > 0){
        t *= 10;
        t += n%10;
        n /= 10;
    }
    return t == x;
}


int main(){
    int t;
    cin >> t;
    while (t--){
        int n, d; cin >> n >> d;
        set <int> solutions;
        for(ll first = 1; 2*first*first < n; first++){
            int next = first + d;
            ll current = first * first + next * next;
            while(current < n){
                if(isPalindrome(current)) solutions.insert(current);
                next += d;
                current += 1LL*next*next;
            }
        }
        ll sum = 0;
        for (auto x : solutions)
            sum += x;
        cout << sum << '\n';
    }
    return 0;
}
