#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
string borze;
int main() {
cin>>borze;
for(int i=0; i<borze.size(); i++){
	if(borze[i]=='.'){
		cout<<0;
	}
	else{
		if(borze[i]=='-'){
    /*
    * Suponemos entrabas buenas, es decir
    * que si se ingreso un '-' debe ingresarse
    * inmediatamente después otro carácter.
    * 
    * No puede ingresarse un '-' y terminar el string
    * pues borze[i+1] no estaría definido.
    */
			if(borze[i+1] == '-') cout<<2;
			else cout<<1;
			i++;
		}
	}
}
return 0;
}
