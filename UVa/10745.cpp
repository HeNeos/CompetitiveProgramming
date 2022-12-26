#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    vector <string> S;
    vector <bitset<260> > B;
    while(cin >> s){
        S.push_back(s);
        vector <int> cont(26);
        for(int i=0; i<s.size(); i++)
            cont[s[i]-'a']++;
        bitset <260> b;
        for(int i=0; i<26; i++){
            for(int j=0; j<cont[i]; j++) b[10*i+j] = 1;
        }
        
        B.push_back(b);
    }
    vector <string> ans;
    for(int i=0; i<B.size(); i++){
        bool isContained = false;
        for(int j=0; j<B.size(); j++){
            if(i == j) continue;
            if((B[i] & B[j]) == B[i]){
                isContained = true;
                break;
            }
        }
        if(!isContained) ans.push_back(S[i]);
    }
    sort(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++) cout << ans[i] << '\n';
    return 0;
}