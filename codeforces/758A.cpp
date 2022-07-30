#include<bits/stdc++.h>
using namespace std;
int main(){
      int max=-1;
      int n;
      int suma=0;
      cin>>n;
      int ciud[n];
      for(int i=0; i<n; i++){
            cin>>ciud[i];
            suma+=ciud[i];
            if(ciud[i]>=max){
                  max=ciud[i];
            }
      }
      cout<<max*n-suma;
      return 0;
}
