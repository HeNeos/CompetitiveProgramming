#include <bits/stdc++.h>
using namespace std;

void solve(string &ans, string &s){
    int sz = s.size();
    for(int i=0; i<sz-1; i++){
        int c1 = (int)(ans[i] - '0');
        int c2 = (int)(s[i] - '0');
        ans += to_string(c1^c2);
    }
}

void check(string s1, string s2){
    int sz = s1.size();
    int c1 = 0;
    int c2 = 0;
    for(int i=0; i<sz; i++){
        if(s1[i] == '1') c1++;
        if(s2[i] == '1') c2++;
    }
    cout << max(c1, c2) << '\n';
}

int main() {
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        string ans_1 = "1";
        string ans_2 = "0";
        solve(ans_1, s);
        solve(ans_2, s);
        check(ans_1, ans_2);
    }
	return 0;
}