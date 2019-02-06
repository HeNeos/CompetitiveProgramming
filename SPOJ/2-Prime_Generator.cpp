/*
*
* https://www.spoj.com/problems/PRIME1/
* PRIME1 - Prime Generator
*
*/

#include<bits/stdc++.h>
using namespace std;
vector <long long> vecprim;
void prim(long long n){
	bool primos[n+1];
	vecprim.clear();
	memset(primos,true,sizeof(primos));
	primos[0]=false;
	primos[1]=false;
	for(int i=2; i*i<=n; i++){
		if(primos[i] == true){
			for(int j=i*i; j<=n; j+=i){
				primos[j]=false;
			}
		}
	}
	for(long long i=2; i<=n; i++){
		if(primos[i]==true){
			vecprim.push_back(i);
		}
	}
}
void primosin(long long minim, long long maxim){
	long long limite=floor(sqrt(maxim)) +1;
	prim(limite);
	bool primos[maxim-minim+2];
	memset(primos,true,sizeof(primos));
	for(long long i=0; i<vecprim.size(); i++){
		int inflim=floor(minim/vecprim[i])*vecprim[i];
		if(inflim < minim) inflim+=vecprim[i];
		for(long long j=inflim; j<=maxim; j+=vecprim[i]) primos[j-minim]=false;
	}
	for(long long i=minim; i<=maxim; i++){
		if(primos[i-minim]) cout<<i<<"\n";
	}
}
int t;
long long n;
long long m;
int main(){
	cin>>t;
	for(int i=1; i<=t; i++){
		cin>>m>>n;
		if(n<1000000){
			prim(n);
			for(int i=0; i<vecprim.size(); i++){
				if(vecprim[i]>=m) cout<<vecprim[i]<<"\n";
			}
		}
		else{
			primosin(m,n);
		}
		cout<<"\n";
	}
}
