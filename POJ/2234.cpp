#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int n;
int a[100];
int main(){
    while(cin >> n){
        for(int i=0; i<n; i++) cin >> a[i];
        int ans = 0;
        for(int i=0;i<n;i++) ans = (ans^a[i]);
        if(ans) cout << "Yes\n";
        else cout<< "No\n";
    }
    return 0;
}