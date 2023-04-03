#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector <int> x(26);
        for(int i=0; i<2*n+1; i++){
            string s; cin >> s;
            for(int j=0; j<s.size(); j++){
                int c = s[j] - 'a';
                x[c]++; x[c] %= 2;
            }
        }
        for(int i=0; i<26; i++){
            if(x[i] == 1){
                cout << (char)('a' + i) << '\n';
                break;
            }
        }
    }
    return 0;
}