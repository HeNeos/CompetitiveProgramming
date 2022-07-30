#include<bits/stdc++.h>
using namespace std;
int n;
int cubos[101];
int aumentos;
int main(){
	cin>>n;
	for(int i=1; i<=n;i++){
		cin>>cubos[i];
	}
	for(int j=1; j<=n; j++){
	for(int i=n-1; i>=1; i--){
		if(cubos[i]>cubos[i+1]){
			aumentos=cubos[i]-cubos[i+1];
			cubos[i+1]=cubos[i+1]+aumentos;
			cubos[i]=cubos[i]-aumentos;
		}
	}
	}
	for(int i=1; i<=n; i++){
		cout<<cubos[i]<<" ";
	}
}
