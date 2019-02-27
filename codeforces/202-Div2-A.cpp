#include <bits/stdc++.h>
using namespace std;
int main (){
    string s; 
    cin >> s;
    char aux;
    for(int i = 0; i < s.size (); i++) aux = max(aux, s[i]);
    for(int i = 0; i < s.size (); i++) if (s[i] == aux) cout << aux;
    return 0;
}
