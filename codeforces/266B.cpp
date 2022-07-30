#include <bits/stdc++.h>
#include <string.h>
using namespace std;
int vect[50];
int n;
int t;

int main() {
cin>>n;
cin>>t;
string texto;
cin>>texto;
	for(int i=0; i<n; i++){
		if(texto[i] == 'B'){
			vect[i]=0;
		}else vect[i]=1;
	}
	for(int j=1; j<=t; j++){
		for(int i=0; i<=n-1; i++){
			if(vect[i]<vect[i+1]){
			swap(vect[i],vect[i+1]);
			i++;
			}	
		}
	}
	for(int i=0; i<=n-1; i++){
		if(vect[i]==0) cout<<"B";
		if(vect[i]==1) cout<<"G";
	}
	return 0;
}
