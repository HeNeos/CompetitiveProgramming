#include<bits/stdc++.h>
using namespace std;
int limak;
int bob;
int main(){
	cin>>limak>>bob;
	for(int i=1;i<=10;i++){
		limak=limak*3;
		bob=bob*2;
		if(limak>bob){
			cout<<i;
			break;
		}
	}
}
