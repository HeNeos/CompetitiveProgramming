#include <bits/stdc++.h>
using namespace std;

int main(){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            char c; cin >> c;
            if(c == '*'){
                cout << (char)(j+'a') << 8-i << '\n';
                return 0;
            }
        }  
    }
    return 0;
}
