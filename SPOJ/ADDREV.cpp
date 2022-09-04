#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void formatString(string &s1, int n){
    for(int i=0; i<n; i++) s1 += '0'; 
}

string addStrings(string s1, string s2){
    string ans = "";
    int sz = s1.size();
    int previous = 0;
    for(int i=0; i<sz; i++){
        int v1 = (int)(s1[i] - '0');
        int v2 = (int)(s2[i] - '0');
        int v = v1 + v2 + previous;
        previous = v/10;
        v %= 10;
        ans += (char)(v + '0');
    }
    if(previous != 0) ans += (char)(previous + '0'); 
    return ans;
}

void clearZeros(string &s){
    int last = s.size() - 1;
    while(last >= 0 && s[last] == '0'){
        s.pop_back();
        last--;
    }
}

int main(){
    int N; cin >> N;
    while(N--){
        string s1, s2;
        cin >> s1 >> s2;
        int sz = max(s1.size(), s2.size());
        formatString(s1, sz - s1.size());
        formatString(s2, sz - s2.size());
        string s3 = addStrings(s1, s2);
        reverse(s3.begin(), s3.end());
        clearZeros(s3);
        reverse(s3.begin(), s3.end());
        cout << s3 << '\n';
    }
    return 0;
}