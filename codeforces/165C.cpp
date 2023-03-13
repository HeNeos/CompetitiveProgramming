#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	int k;
	cin >> k;
	cin >> s;
	int onev[s.size()];
	onev[0] = 0;
	long long answ = 0;
	int p = 1;
	int pos1 = 0, pos2 = s.size()+1, pos3 = s.size()+1, pos4 = s.size()+1;
	if(k!= 0){
		for(int i=1; i<=s.size(); i++){
			if(s[i-1] == '1') onev[i]=onev[i-1]+1;
			else onev[i] = onev[i-1];
			if(onev[i] == p-1) pos1 = min(pos1, i);
			if(onev[i] == p) pos2 = min(pos2,i);
			if(onev[i] == p+k-1) pos3 = min(pos3,i);
			if(onev[i] == p+k or (s[s.size()-1] == '0' and i==s.size())){
				pos4 = i;
				if(s[i-1] == '0') pos4++;
				answ = answ + 1LL*(pos4-pos3)*(pos2-pos1);
				pos1 = pos2;
				pos3 = pos4;
				p++;
				while(onev[pos2]<p and pos2 < pos3) pos2++;
			}
		}
		if(onev[s.size()] < k){
			cout << 0;
			return 0;
		}
		if(s[s.size()-1] == '1') answ += 1LL*(pos2-pos1);
	}
	if(k == 0){
		int cont = 0;
		for(int i=0; i<s.size(); i++){
			if(s[i] == '0') cont++;
			else{
				answ = answ + 1LL*(1LL*cont*(cont+1))/2;
				cont = 0;
			}
		}
		if(s[s.size()-1] == '0') answ = answ + 1LL*(1LL*cont*(cont+1))/2;
	}
	cout << answ;
	return 0;
}
