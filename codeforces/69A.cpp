#include <bits/stdc++.h>
using namespace std;
int x[100];
int y[100];
int z[100];
int n;
int sumx=0;
int sumy=0;
int sumz=0;

int main() {
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>x[i]>>y[i]>>z[i];
        sumx=sumx+x[i];
        sumy=sumy+y[i];
        sumz=sumz+z[i];
    }
    if(sumx==0 && (sumy==0 && sumz==0)){
        cout<<"YES"<<endl;
    }else cout<<"NO"<<endl;
    return 0;
}
