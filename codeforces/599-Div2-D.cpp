#include<bits/stdc++.h>
using namespace std;
long long m;
long long hx;
long long cuad;
long long vech[2000000];
long long vecm[2000000];
int cont=0;
int cont2=0;
int main(){
cin>>cuad;
	for(m=1; m*m*m<=8*cuad; m++){
			if((6*cuad+(m*m*m)-m) % (3*m*m+3*m) == 0){
			hx=(6*cuad+(m*m*m)-m)/(3*m*m+3*m);
			} else continue;
			if(m>hx) break;
			cont++;
			vech[cont]=hx;
			vecm[cont]=m;
			if(vech[cont]==vecm[cont]) cont2++;
	}
	cout<<2*cont-cont2<<endl;
	for(int i=1; i<=cont; i++){
		cout<<vecm[i]<<" "<<vech[i]<<endl;
	}
	for(int i=2*cont; i>=1+cont; i--){
		if(vecm[i-cont]==vech[i-cont]) continue;
		cout<<vech[i-cont]<<" "<<vecm[i-cont]<<endl;
	}
}
