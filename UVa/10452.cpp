#include <bits/stdc++.h>
using namespace std;
int X;
int Y;
string charinp[9];
int movex[] = {-1, 0, 1};
int movey[] = {0, -1, 0};
string nmove[] = {"left", "forth", "right"};
string word = "IEHOVA#";
string direc[7];
bool answ(int x, int y, int pos){
    if(charinp[y][x] == '#'){
        cout << direc[0];
        for(int i=1; i<pos; i++) cout << ' ' << direc[i];
        cout << "\n";
        return true;
    }
    else{
        if(pos == word.size()) return false;
        for(int moves=0; moves<3; moves++){
            int newx = x + movex[moves];
            int newy = y + movey[moves];
            if(newx >=0 && newx < X && newy >=0 && newy<Y && charinp[newy][newx] == word[pos]){
                direc[pos] = nmove[moves];
                if(answ(newx,newy,pos+1)) return true;
            }
        }
    }
    return false;
}
int main(){
    int test;
    cin >> test;
    while(test--){
        cin >> Y >> X;
        int inx;
        int iny;
        for(int y=0; y<Y; y++){
            cin >> charinp[y];
            for(int x=0; x<X; x++){
                if(charinp[y][x] == '@'){
                    inx = x;
                    iny = y;
                }
            }
        }
        answ(inx,iny,0);
    }    
    return 0;
}
