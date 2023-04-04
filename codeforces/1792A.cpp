#include <iostream>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int h[n];
        int x = 0;
        for(int i=0; i<n; i++){
            cin >> h[i];
            if(h[i] == 1) x++;
        }
        cout << (x+1)/2 + (n-x) << '\n';
    }
}