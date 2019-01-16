/*
*
* V1.
* 1401-Factorial:
* http://poj.org/problem?id=1401
*
*
*/
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
int T;
long long M;
int main(){
    cin>>T;
    for(int i=1;i<=T;i++){
          cin>>M;
			    long long num5=M/5;
        	long long num25=M/25;
        	long long num125=M/125;
        	long long num625=M/625;
        	long long num3125=M/3125;
        	long long num15625=M/15625;
        	long long num78125=M/78125;
        	long long num390625=M/390625;
        	long long num1953125=M/1953125;
        	long long num9765625=M/9765625;
        	long long num48828125=M/48828125;
        	long long num244140625=M/244140625;
        	long long num1220703125=M/1220703125;
        	long long sum=num5+num25+num125+num625+num3125+num15625+num78125+num390625+num1953125+num9765625+num48828125+num244140625+num1220703125;
    
    	cout<<sum<<endl;
    }
}
