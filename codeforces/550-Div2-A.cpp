#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
char texto[100000];
int i=1;
int j=1;
int main(){
	cin.getline(texto,sizeof(texto));
	string texto2(texto);
	size_t posicion1 = texto2.find("AB");
	i=texto2.find("AB");
	size_t posicion2 = texto2.find("BA");
	j=texto2.find("BA");
	int aux=j;
	while(i<=texto2.size()){
		while(j<=texto2.size()){
			if(posicion1+1!=posicion2 && (posicion2+1!=posicion1 && (posicion1!=string::npos && posicion2!=string::npos))){
			cout<<"YES"<<endl;
			goto salir;
			}
			j=j+2;
			posicion2 = texto2.find("BA",posicion2+1);	
			if(posicion2==string::npos){
			break;
			}
		}
		i=i+2;
		posicion2=aux;
		posicion1=texto2.find("AB",posicion1+1);
		if(posicion1==string::npos){
		break;
		}
	}
		cout<<"NO"<<endl;
	salir:;
}
