#include <bits/stdc++.h>
using namespace std;
int main(){
	string answ;
	cin >> answ;
	for (int i=1; i <=5; i++){
		string answ2;
		cin >> answ2;
		if(answ2[0] == answ[0] || answ2[1] == answ[1]){
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}
