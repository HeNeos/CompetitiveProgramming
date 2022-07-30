#include <bits/stdc++.h>
using namespace std; 
int main(){
	int t;
	cin >> t;
	for(int p=1; p<=t; p++){
    	int n;
    	cin >> n;
    	if(n==0 or n==1){
    		cout<<1<<'\n';
    		continue;
    	}
    	vector <int> answ;
    	answ.push_back(1);
    	vector <int> :: iterator itr;
    	for(int i = 2 ; i <= n ; i++){
    	    for(itr = answ.begin(); itr != answ.end(); itr++) *itr *= i;
    	    for(int j = 0; j < answ.size(); j++){
    	        if(answ[j] >= 10){
    	            if(j == answ.size() - 1) answ.push_back(0);
    	            answ[j+1] = answ[j+1] + (answ[j]/10);
    	            answ[j] = answ[j]%10;
    	        }
    	    }
    	}
    	for(int i = answ.size() - 1; i > -1; i--) cout << answ[i];
    	cout << '\n';
	}
    return 0;
}
