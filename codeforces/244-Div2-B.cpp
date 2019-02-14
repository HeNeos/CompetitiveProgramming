#include<bits/stdc++.h>
using namespace std;
long long N;
set <long long> num;
void Numbr(long long n, int i, int j){
	if(n<=N){
		if(n!=0){
			num.insert(n);
		}
		if(n+i!=0) Numbr(n*10+i,i,j);
		if(n+j!=0) Numbr(n*10+j,i,j);
	}
}
int main(){
	cin>>N;
	for(int i=0; i<=9; i++){
		for(int j=0; j<=9; j++){
			Numbr(0,i,j);
		}
	}
	cout<<num.size()<<endl;
}
