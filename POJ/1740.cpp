#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int n;
int a[10];
int main(){
    while(cin >> n && n){
        for(int i=0; i<n; i++) cin>>a[i];
        sort(a,a+n);
        int ans = 0;
        if(!(n&1)){
            for(int i=0;i<n;i+=2){
                if(a[i]!=a[i+1]) ans=1;
            }
            cout<< ans << '\n';
        }
        else cout<< 1 << '\n';
    }
    return 0;
}