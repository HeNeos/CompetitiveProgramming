#include <bits/stdc++.h>
using namespace std;

bool solve1(string s){
    int sz = s.size();
    char x = s[0];
    int pos = -1;
    for(int i=1; i<sz-1; i++){
        if(s[i] >= x){
            if(s[i] > x or pos == -1) pos = i;
            x = s[i];
        }
    }
    if(pos != -1){
        if(s[sz-1] > s[pos]) return false;
        if(s.substr(0, pos) > s.substr(pos, sz-pos-1)) return false;
        for(int i=0; i<pos; i++) cout << s[i];
        cout << " ";
        for(int i=pos; i<sz-1; i++) cout << s[i];
        cout << " ";
        cout << s[sz-1];
        return true;
    }
    else return false;
}

bool solve2(string s){
    int sz = s.size();
    char x = s[0];
    int pos = -1;
    for(int i=1; i<sz-1; i++){
        if(s[i] <= x){
            x = s[i];
            pos = i;
        }
    }
    if(pos != -1){
        if(s[pos+1] < s[pos]) return false;
        for(int i=0; i<pos; i++) cout << s[i];
        cout << " ";
        cout << s[pos] << " ";
        for(int i=pos+1; i<sz; i++) cout << s[i];
        return true;
    }
    else return false;
}

int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        if(solve1(s)){
            cout << '\n';
        }
        else{
            if(solve2(s))cout << '\n';
            else cout << ":(\n";
        }
    }
    return 0;
}