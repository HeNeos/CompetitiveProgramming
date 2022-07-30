#include "bits/stdc++.h"
using namespace std;
long long n;
long long k=0;
long long abc=1;
long long a[100010];
bool sqr(long long x){
    long long y=sqrt(x);
    return y*y==x;
}
int main(){
    cin>>n;
    for(int i=2;i<=n;i+=2) cin>>a[i];
    for(int i=1;i<=n;i+=2){
        while(abc*abc<=k) abc++;
        while(abc<5*100000 && !sqr(abc*abc+a[i+1])) abc++;
        a[i]=abc*abc-k;
        if(a[i]>1*10000000000000 || abc==5*100000){
			  cout<<"No";
			  return 0;
			  }
        k=k+a[i]+a[i+1];
    }
    cout<<"Yes\n";
    for(int i=1;i<=n;++i) cout<<a[i]<<" ";
}
