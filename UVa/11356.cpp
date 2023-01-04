#include <bits/stdc++.h>
using namespace std;
int dias[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string meses[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
int mes(const string &m){
    for (int i = 0; i < 12; i++){
        if (m == meses[i]) return i+1;
    }
}
bool bisiesto(int year){
    return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}
int main(){
    int tests,yy,dd,mm,add,l,y,cs=0;
    bool yabastafreezer;
    string s;
    cin >> tests;
    for(int i=1; i<=tests; i++){
        yabastafreezer=false;
        cin >> yy;
        cin.ignore();
        getline(cin,s, '-');
        cin >> dd >> add;
        mm = mes(s);
        for(y=yy;; y++){
            for(int j=mm; j<=12; j++){
                l=dias[j-1];
                if(bisiesto(y) && j==2) l++;
                for(int k=dd+1; k<=l; k++){
                    add--;
                    if(add==0){
                        yabastafreezer=true;
                        cout<<"Case "<< i <<": "<<y<<"-"<<meses[j-1]<<"-";
                        printf("%.2d\n",k);
                    }
                }
                if(yabastafreezer) break;
                dd=0;
            }
            if(yabastafreezer) break;
            mm=1;
        }
    }
    return 0;
}