/*
*
*
* A. Goshtasp, Vishtasp and Eidi
* 
*
*/


#include<bits/stdc++.h>
using namespace std;
bool prim[10001];
void sieve(int m){
      for(int i=0; i<=m; i++){
            prim[i]=true;
      }
      prim[0]=false;
      //prim[1]=false; 
      for(int i=2; i*i<=m; i++){
            if(prim[i]==true){
                  for(int j=i*i; j<=m; j=j+i){
                        prim[j]=false;
                  }
            }
      }
}
int main(){
      int n;
      cin>>n;
      sieve(n);
      int sum=0;
      for(int i=n; i>=1; i--){
            if(prim[i] && i+sum<=n){
                  sum=sum+i;
                  cout<<i;
                  if(sum==n){
                        cout<<"=";
                        break;
                  }
                  else cout<<"+";
            }
      }
      cout<<n;
      return 0;
}
