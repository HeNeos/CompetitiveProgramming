#include<bits/stdc++.h>
using namespace std;
int cont=0;
int absol(int a, int b){
	int abso=sqrt((a-b)*(a-b));
	return abso;
}
int main(){
	string nombre;
	cin>>nombre;
	if(nombre[0]-'a' < 'z'-nombre[0]+1){
		cont=cont+nombre[0]-'a';
	}
	else cont=cont+'z'-nombre[0]+1;
	for(int i=1; i<=nombre.length()-1; i++){
		if(absol(nombre[i],nombre[i-1])>26-absol(nombre[i],nombre[i-1])){
			cont=cont+26-absol(nombre[i],nombre[i-1]);
		}
		else{
			cont=cont+absol(nombre[i],nombre[i-1]);
		}
	}
	cout<<cont;
}
