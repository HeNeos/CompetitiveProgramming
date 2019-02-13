#include<bits/stdc++.h>
using namespace std;
int main(){
      int n;
      cin>>n;
      int sum=0;
      for(int i=1; i<=n; i++){
            int a;
            cin>>a;
            sum=sum+a;
      }
      printf("%.8f",1.0*(sum*1.0)/(n*1.0));
      return 0;
}
