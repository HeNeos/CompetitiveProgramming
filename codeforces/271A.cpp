#include <bits/stdc++.h>
using namespace std;
int anio;

int main() {
cin>>anio;
for(int i=anio+1; i<=10000; i++){
int mill=(i)/1000;
int cent=(i%1000)/100;
int dec=(i%100)/10;
int ent=(i%10);
if(mill!=cent && (mill!=dec && (mill!=ent && (cent!=dec && (cent!=ent && dec!=ent))))){
	cout<<i;
	break;
}
}
	return 0;
}
