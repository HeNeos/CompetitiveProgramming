#include <bits/stdc++.h>
using namespace std;
int mat[5][5];
int x;
int y;

int absoluto(int a, int b){
	return sqrt((a-b)*(a-b));
}

int main() {
	for(int i=0; i<=4; i++){
		for(int j=0; j<=4; j++=){
			cin>>mat[i][j];
			if(mat[i][j]==1){
				x=j+1;
				y=i+1;
			}
		}
	}
cout<<absoluto(x,3)+absoluto(y,3);
}
