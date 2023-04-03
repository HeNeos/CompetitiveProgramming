#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int q;
    cin >> q;
    while(q--){
        int n; cin >> n;
        string s, t;
        cin >> s >> t;
        string s_s = "";
        string t_t = "";
        vector <int> ss;
        vector <int> tt;
        for(int i=0; i<n; i++){
            if(s[i] != 'b'){
                s_s += s[i];
                ss.push_back(i);
            }
            if(t[i] != 'b'){
                t_t += t[i];
                tt.push_back(i);
            }
        }
        // if(s_s.size() != t_t.size()) cout << "NO\n";
        if(s_s != t_t) cout << "NO\n";
        else{
            bool can = true;
            for(int i=0; i<ss.size(); i++){
                char c = s_s[i];
                if(c == 'a'){
                    if(ss[i] > tt[i]){
                        can = false;
                        break;
                    }
                }
                else{
                    if(ss[i] < tt[i]){
                        can = false;
                        break;
                    }
                }
            }
            if(can) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}