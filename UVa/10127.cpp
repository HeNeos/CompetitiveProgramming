#include <iostream>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        int ans = 1;
        int v = 1;
        while(true){
            if(v%n == 0) break;
            v = v*10+1;
            v %= n;
            ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}