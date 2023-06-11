#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int art1=0; // 1 1
    int art2=0; // 1 0
    int art3=0; // 0 1
    int art4=0; // 0 0
    cin >> n;
    int clow[n];
    int acrob[n];
    vector <int> art[5];
    string string1;
    cin >> string1;
    string string2;
    cin >> string2;
    for(int i=0; i<n; i++){
        if(string1[i] == '1' && string2[i] == '1'){
            art[1].push_back(i+1);
            art1++;
        }
        if(string1[i] == '1' && string2[i] == '0'){
            art[2].push_back(i+1);
            art2++;    
        }
        if(string1[i] == '0' && string2[i] == '1'){
            art[3].push_back(i+1);
            art3++;
        }
        if(string1[i] == '0' && string2[i] =='0'){
            art[4].push_back(i+1);
            art4++;
        }
    }
    for(int a = 0; a <= art1; a++){
        int aux = art3 + art1 - 2*a;
        int d = n/2 - a - aux;
        if(aux >= 0 and aux <= art2 + art3 and d >= 0 and d <= art4){
            for(int i=0; i<a; i++) cout << art[1][i] << " ";
            for(int i=0; i<d; i++) cout << art[4][i] << " ";
            if(n/2 - a - d <= art2){
                for(int i=0; i<(n/2-a-d); i++) cout << art[2][i] << " ";
            }
            else{
                for(int i=0; i<art2; i++) cout << art[2][i] << " ";
                for(int i=0; i<(n/2 - a - d -art2); i++) cout << art[3][i] << " ";
            }
            return 0;
        }
    }
    cout << -1;
    return 0;
}
