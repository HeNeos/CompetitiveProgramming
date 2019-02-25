#include <bits/stdc++.h>
using namespace std;
vector< vector<int> > solutions;
bool safe(vector <int> &table,int row2){
	for(int i=0; i<table.size(); i++){
		if(row2==table[i] or abs(i-(int)table.size())==abs(table[i]-row2)) return false;
	}
	return true;
}
void solve(vector <int> &table, int col){
	if(col==9){
		solutions.push_back(table);
		return;
	}
	for(int row=1; row<=8; row++){
		if(safe(table,row)){
			table.push_back(row);
			solve(table, col+1);
			table.pop_back();
		}
	}
}
int main() {
	vector <int> board;
	solve(board, 1);
	int test;
	cin >> test;
	for(int i=1; i<=test; i++){
		int row;
		int column;
		cin >> row >> column;
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		int cont=0;
		for(int i=0; i<solutions.size(); i++){
			if(solutions[i][column-1] == row){
				printf("%2d      %d", ++cont, solutions[i][0]);
				for(int j=1; j<8; j++) printf(" %d", solutions[i][j]);
				cout<<"\n";
			}
		}
		if(i!=test) cout<<"\n";
	}
	return 0;
}
