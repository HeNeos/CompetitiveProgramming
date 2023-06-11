/*
*
* 1401-Factorial:
* http://poj.org/problem?id=1401
*
*/
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
int T;
long long M;
long long sum;
long long pot5[16];
long long numb5[16];
int main(){
    cin>>T;
    pot5[0]=1;
    for(int j=1; j<=15;j++){
         pot5[j]=pot5[j-1]*5;
    }
    for(int i=1;i<=T;i++){
        sum=0;
        cin>>M;
        for(int j=1; j<=15; j++){
            numb5[j]=M/pot5[j];
            sum=sum+numb5[j];
        }
        cout<<sum<<endl;
    }
}
