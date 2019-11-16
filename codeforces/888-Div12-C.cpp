#include<bits/stdc++.h>
using namespace std;
int answ = 999999;
int main(){
    string word;
    cin >> word;
    for(int i=0;i<26;i++){
        int cont = 1;
        int k = 1;
        for(int j=0; j<word.size(); j++){
            if(word[j] == i+'a') cont = 1;
            else{
                cont++;
                k = max(k,cont);
            }
        }
        answ = min(answ,k);
    }
    cout << answ;
    return 0;
}
