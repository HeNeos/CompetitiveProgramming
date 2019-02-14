#include<iostream>
using namespace std;

int main(){
  int i;
  int c=0;
  int k=0;
  int len=0;
  string s;
  cin>>s;
  for(i=0;i<s.size();i++){
    len++;
    c=c+(s[i]/*-48*/);
    if(c%3==0||s[i]%3==0||len>=3){
      k++;
      c=0;
      len=0;
    }
  }
  cout<<k;
}
