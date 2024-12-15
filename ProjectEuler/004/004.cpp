#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool test(int x){
    string s = to_string(x);
    for(int i=0, j=s.size()-1; i<j; i++, j--){
        if(s[i] != s[j]) return false;
    }
    return true;
}

int main(){
    int ans = -1;
    for(int i=110; i<1000; i+=11){
        for(int j=100; j<1000; j++){
            int p = i*j;
            if(test(p)) ans = max(ans, p);
        }
    }
    cout << ans << '\n';
    return 0;
}