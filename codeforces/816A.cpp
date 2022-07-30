#include <bits/stdc++.h>
using namespace std;
int main(){
	string time;
	cin >> time;
	string aux = time;
	for(int i=0; i<=60*24; i++){
		if(aux[4] == aux[0] && (aux[3] == aux[1] && (aux[1] == aux[3] && aux[0] == aux[4]))){
			//cout << aux << endl;
			cout << i;
			return 0;
		}
		if(aux[4] - '0' + 1 == 10){
			aux[3] = aux[3] + 1;
			aux[4] = '0';
		}
		else aux[4] = aux[4]  + 1;
		if(aux[3] == '6'){
			if(aux[1] - '0' + 1 == 10){
				aux[0] = aux[0] + 1;
				aux[1] = '0';
				aux[3] = '0';
			}
			else{
				aux[1] = aux[1] + 1;
				aux[3] = '0';
			}
		}
		if(aux[0] == '2' && aux[1] == '4'){
			aux[0] = '0';
			aux[1] = '0';
			aux[4] = '0';
			aux[3] = '0';
		}
	}
	return 0;
}
