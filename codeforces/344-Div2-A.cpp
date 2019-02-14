#include<bits/stdc++.h>
long long n;
long long grupos=1;
long long elementos[200001];
using namespace std;
int main(){
	cin>>n;
	for(int i=1; i<=2*n; i=i+2){
		scanf("%1d %1d", &elementos[i], &elementos[i+1]); 
	}
	for(int i=2; i<=2*n-2; i=i+2){
		if(elementos[i]==elementos[i+1]){
			grupos++;
		}
	}
	cout<<grupos;
}
