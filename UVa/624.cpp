#include <bits/stdc++.h>
using namespace std;
int main(){
	int N;
	while(cin>>N){
		int numbsong;
		int answ=-1;
		int answ2=-1;
		cin >> numbsong;
		int arr[numbsong];
		for(int i=0; i<numbsong; i++) cin >> arr[i];
		for(int j=0; j<(2<<numbsong); j++){
			int record = 0;
			for(int k=0; k<numbsong; k++){
				if((j>>k)&1) record += arr[k];
			}
			if(record <= N){
				if(answ <= record){
					answ = max(answ,record);
					answ2 = j;
				}
			}
		}
		for(int k=0; k<numbsong; k++){
			if((answ2>>k)&1) cout << arr[k] << " ";
		}
		cout << "sum:" << answ << endl;
	}
	return 0;
}
