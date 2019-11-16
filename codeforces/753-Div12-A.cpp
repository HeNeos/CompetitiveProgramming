#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i = 0; i<60; i++){
        if(i*(i+1) > 2*n){
            cout << i-1 << '\n';
            for(int j=1; j<i-1; j++) cout << j << " ";
            cout << n-((i-1)*(i-2))/2;
            return 0;
        }
        if(i*(i+1) == 2*n){
            cout << i << '\n';
            for(int j=1; j<i; j++) cout << j << " ";
            cout << i;
            return 0;
        }
    }
    return 0;
}
