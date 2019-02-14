#include<bits/stdc++.h>
using namespace std;
int n;
int d[200010];
long long suma1,suma3,maxs;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>d[i];
	}
	for(int i=0,j=n-1;i<=j;){
		if(suma1<=suma3){ 
			suma1=suma1+d[i++];
		}
		else suma3=suma3+d[j--];
		if(suma1==suma3){
			maxs=suma1;
		}
	}
	cout<<maxs;
	return 0;
}
