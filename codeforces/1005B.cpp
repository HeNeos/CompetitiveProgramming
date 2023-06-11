#include <bits/stdc++.h>
using namespace std;
string s1;
string s2;
int longstr(int p, int q){
    if(p<0 or q<0) return 0;
    if(s1[p] == s2[q]) return 1+longstr(p-1,q-1);
    else return 0;
}
int main(){
    cin >> s1 >> s2;
    cout << s1.size()+s2.size()-2*longstr(s1.size()-1, s2.size()-1);
    return 0;
}
