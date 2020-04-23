#include<bits/stdc++.h>
using namespace std;
int sumcf(int numm){
	int sumcff=0;
	for(int i=1; i<=99; i++){
		sumcff=sumcff+numm%10;
		int aux=numm;
		numm=numm/10;
		if(aux==numm){
			return sumcff;
		}
	}
}
int prof(long long num){
	if(num%9!=0) return 0;
	else{
		if(num==9) return 1;
		else{
			return 1+prof(sumcf(num));
		}
	}
}
int main(){
	while(true){
		int cont1=0;
		long long sum=0;
		string numb;
		cin>>numb;
		if(numb=="0") break;
		if(numb[0]=='9' && numb.size()==1){
			cout<<"9 is a multiple of 9 and has 9-degree 1."<<endl;
			continue;
		}
		for(int i=0; i<numb.size(); i++){
			sum=sum+numb[i]-'0';
		}
		if(sum%9!=0){
			cout<<numb<<" is not a multiple of 9."<<endl;
			continue;
		}
		else{
			cout<<numb<<" is a multiple of 9 and has 9-degree "<<prof(sum)<<"."<<endl;
		}
	}
	return 0;
}
