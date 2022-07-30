#include<bits/stdc++.h>
using namespace std;
int main(){
      long long n;
      int k;
      int cont2=0;
      int cont5=0;
      cin>>n>>k;
      long long aux=n;
      for(int i=1; i<=32; i++){
            if(aux<2) break;
            if(aux%2==0){
                  cont2++;
                  aux/=2;
            }
            if(aux%5==0){
                  aux/=5;
                  cont5++;
            }
      }
      int flt2=0;
      int flt5=0;
      int num5=1;
      int num2=1;
      if(k>=cont2) flt2=k-cont2;
      if(k>=cont5) flt5=k-cont5;
      for(int i=1; i<=flt5; i++){
            num5*=5;
      }
      for(int i=1; i<=flt2; i++){
            num2*=2;
      }
      cout<<num2*num5*n;
}
