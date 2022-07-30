#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	vector <string> answ = {"", "G", "GB", "OGB", "ROGB", "ORYGB", "ORYIGB"};  
	cin >> n;
	for(int i=1; i<= n/7; i++) cout << "ROYGBIV";
	cout << answ[n%7];
	return 0;
}
