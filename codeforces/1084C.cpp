#include <bits/stdc++.h>
using namespace std;
int prim = 1000000007;
int main(){
	string s1;
	cin >> s1;
	int aux=0;
	int answ=0;
	for(int i=0; i<s1.size(); i++){
		if(s1[i]=='a'){
			answ += aux+1;
			answ %= prim;
		}
		if(s1[i]=='b') aux=answ;
	}
	cout << answ;
	return 0;
}
