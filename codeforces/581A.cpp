#include<bits/stdc++.h>
using namespace std;
int main(){
      int A;
      int B;
      cin>>A>>B;
      cout<<min(A,B);
      cout<<" "<<(max(A,B)-min(A,B))/2;
}
