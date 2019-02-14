#include<bits/stdc++.h>
using namespace std;
int N;
long long cont=0;
bool posic[2002][2002];
int main(){
	cin>>N;
	long long vecx[N+1];
	long long vecy[N+1];
	for(int i=1; i<=N; i++){
		cin>>vecx[i]>>vecy[i];
		vecx[i]=vecx[i]+1000;
		vecy[i]=vecy[i]+1000;
		posic[vecx[i]][vecy[i]]=1;
	}
	for(int i=1; i<=N-1; i++){
		for(int j=i+1; j<=N; j++){
			if((vecx[i]+vecx[j])%2==0 &&(vecy[i]+vecy[j])%2==0){
				cont=cont+posic[(vecx[i]+vecx[j])/2][(vecy[i]+vecy[j])/2];
			}
		}
	}
	cout<<cont<<endl;
}
