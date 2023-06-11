#include <bits/stdc++.h>
using namespace std;
int w;
int m;
int a[40];
int main(){
    bool flag = true;
    cin >> w >> m;
    int cont = 0;
    while(m){
        a[cont] = m%w;
        m /= w;
        cont++;
    }
    for(int i = 0; i < cont; i++){
        if(a[i] != 0 && a[i] != 1 && a[i] != w-1 && a[i] != w){
           flag = false;
           break;
        }
        else{
            if(a[i] == w-1 || a[i] == w) a[i+1]++;
        }
    }
    if(flag)
       cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
