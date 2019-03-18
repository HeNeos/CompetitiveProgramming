#include <bits/stdc++.h>
using namespace std;
string alph = "";
bool letter(char a){
	for(int i=0; i<26; i++){
		if(a == alph[i]) return true;
	}
	return false;
}
int main(){
	for(int i=0; i<26; i++) alph += 'a' + i; 
	int test;
	cin >> test;
	while(test--){
		string word;
		cin >> word;
		string T = "";
		for(int i=0; i<word.size(); i++){
			if(letter(word[i])){
				T += word[i];
			}
			else{
				int numb = word[i] - '0';
        string aux = T;
				for(int j=1; j<numb; j++) T += aux;
			}
		}
		long long quer;
		cin >> quer;
		while(quer--){
			long long gg;
			cin >> gg;
			if(gg > T.size()) cout << "-1\n";
			else cout << T[gg-1] << '\n';
		}
	}
	return 0;
}
