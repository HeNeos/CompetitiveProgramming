#include<bits/stdc++.h>
using namespace std;
long long n;
int main(){
cin>>n;
	for(int a=0; a<=811; a++){
		for(int b=0; b<=8101; b++){
			if(n-1234567*a-b*123456<0) break;
			if((n-1234567*a-b*123456)%1234==0){
			//cout<<a<<" "<<b<<" "<<n-a-b<<endl;
			cout<<"YES"<<endl;
			goto salir;
			}
		}
	}
	cout<<"NO"<<endl;
	salir:;
}
