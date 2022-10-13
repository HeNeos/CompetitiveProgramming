#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool isPalindrome(string s){
    for(int i=0, j=s.size()-1; i<j; i++, j--){
        if(s[i] != s[j]) return false;
    }
    return true;
}

string toK(int n, int k){
    string ans = "";
    while(n > 0){
        ans += (char)(n%k + '0');
        n /= k;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    int n, k; cin >> n >> k;
    ll ans = 0;
    for(int i=1; i<n; i++){
        if(isPalindrome(to_string(i))){
            if(isPalindrome(toK(i, k)))
                ans += i;
        }
    }
    cout << ans << '\n';
    return 0;
}
