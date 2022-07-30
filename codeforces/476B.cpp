#include<bits/stdc++.h>
using namespace std;
long double facto(int n){
    if(n<=1) return 1.0;
    else return n*facto(n-1);
}
long double comb(int n, int r){
    return facto(n) / (facto(r) * facto(n - r));
}
int main(){
    string s1;
    string s2;
    cin >> s1 >> s2;
    int a1=0;
    int b1=0;
    int a2=0;
    int b2=0;
    int q=0;
    for(int i=0; i<s1.size(); i++){
        if(s1[i]=='+') a1++;
        if(s1[i]=='-') b1++;
        if(s2[i]=='+') a2++;
        if(s2[i]=='-') b2++;
        if(s2[i]=='?') q++;
    }
    if(a1 == a2 && b1 == b2) cout << 1 << endl;
    else{
    	if(q + a2 < a1 || q + b2 < b1) cout<<0<<endl;
    	else{
        	a1 -= a2;
        	long double cases = comb(q, a1);
        	double answ = cases/pow(2.0,q);
        	printf("%.9f",answ);
    	}
    }
    return 0;
}
