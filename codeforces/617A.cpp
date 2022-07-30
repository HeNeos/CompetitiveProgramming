#include<bits/stdc++.h>
using namespace std;
int main(){
      int n;
      cin>>n;
      int cant5=n/5;
      int cant4=(n-(cant5*5))/4;
      int cant3=(n-(cant5*5)-(cant4*4))/3;
      int cant2=(n-(cant5*5)-(cant4*4)-(cant3*3))/2;
      int cant1=(n-(cant5*5)-(cant4*4)-(cant3*3)-(cant2*2))/1;
      cout<<cant5+cant4+cant3+cant2+cant1;
}
