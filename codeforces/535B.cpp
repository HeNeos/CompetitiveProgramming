#include<bits/stdc++.h>
using namespace std;
long long N;
int i=0;
int s=0;
int main(){
	cin>>N;
	while(N>0){
		if(N & 1) s+=1<<(i+1);
		else s+=1<<i;
		i++;
		N=N/10;
	}
	cout<<s;
}
