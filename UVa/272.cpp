#include <bits/stdc++.h>
using namespace std;
int main(){
	int cnt=1;
	string s="";
	while(getline(cin,s)){
		for(int i=0; i</*strlen(s)*/s.size(); i++){
			if(s[i] == '"'){
				cnt++;
				if(cnt%2){
					cout << "''";
					continue;
				}
				else{
					cout << "``";
					continue;
				}
			}
			cout<<s[i];
		}
		cout<<'\n';
	}
	return 0;
}
