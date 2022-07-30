#include<bits/stdc++.h>
using namespace std;
int n;
int infhombres[5001];
int suphombres[50001];
int supmujeres[5001];
int infmujeres[5001];
char gen;
int maxim=-1;
int contH=0;
int contM=0;
int contxh=0;
int contxm=0;
int resp[366];
int main(){
cin>>n;
	for(int i=1; i<=n; i++){
		cin>>gen;
		if(gen=='M'){
		contH++;
		cin>>infhombres[contH]>>suphombres[contH];
		}
		if(gen=='F'){
		contM++;
		cin>>infmujeres[contM]>>supmujeres[contM];
		}
	}
	for(int diax=1; diax<=366; diax++){
		contxh=0;
		contxm=0;
		for(int i=1; i<=contH; i++){
			if(diax>=infhombres[i] && diax<=suphombres[i]){
				contxh++;
			}
		}
		for(int i=1; i<=contM; i++){
			if(diax>=infmujeres[i] && diax<=supmujeres[i]){
				contxm++;
			}
		}
		resp[diax]=min(contxm,contxh);
	}
	
	for(int i=1; i<=366; i++){
		if(resp[i]>=maxim){
			maxim=resp[i];
		}
	}
	cout<<2*maxim<<endl; 
	
}
