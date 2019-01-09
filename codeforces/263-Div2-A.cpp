/*
*
*		Beautiful Matrix V2.
*
*/

#include <bits/stdc++.h>
using namespace std;
int vect[5];
int x;
int y;

int absoluto(int a, int b){
	return sqrt((a-b)*(a-b));
}

int main(){
	for(int j=1; j<=5; j++){
		y=j;
		for(int i=0; i<=4; i++){
			cin>>vect[i];
			if(vect[i]==1){
				x=i+1;
				goto salir;
			}
		}
	}
salir:;
cout<<absoluto(x,3)+absoluto(y,3);
}


/*
*
*		Beautiful Matrix V1.
*
*/

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
