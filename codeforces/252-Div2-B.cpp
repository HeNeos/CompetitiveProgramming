#include<bits/stdc++.h>
using namespace std;
long long n;
long long numb;
vector <long long> ingr;
vector <long long> crec;
vector <long long> decr;
int main(){
	cin>>n;
	for(int i=1; i<=n;i++){
		cin>>numb;
		ingr.push_back(numb);
	}
	crec=ingr;
	decr=ingr;
	sort(begin(crec),end(crec));
	sort(begin(decr),end(decr),greater<long long>());
	
	for(int i=1; i<n; i++){
		if(ingr[i]!=ingr[i-1]){
			swap(ingr[i],ingr[i-1]);
			if(ingr==crec || ingr==decr){
				swap(ingr[i],ingr[i-1]);
			}
			else{
				cout<<(i-1)+1<<" "<<i+1<<" \n";
				goto salir;
			}
		}
	}
	cout<<-1<<" \n";
	salir:;
}
