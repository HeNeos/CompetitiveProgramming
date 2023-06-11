#include <bits/stdc++.h>
using namespace std;
int contq[110];
int main(){
    string s;
    cin >> s;
    int cont = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'Q') contq[i] = contq[i-1]+1;
        else contq[i] = contq[i-1];
    }
    for(int i=1; i<s.size()-1; i++){
        if(s[i] == 'A'){
            cont = cont + contq[i]*(contq[s.size()-1]-contq[i]);
        }
    }
    cout << cont;
    return 0;
}
