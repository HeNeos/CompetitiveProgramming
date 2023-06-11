#include <bits/stdc++.h>
using namespace std;
vector <int> numb;
int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        numb.push_back(a);
    }
    int aux = -1;
    int aux2 = 1;
    for(int j=1; j<n; j++){
        if(numb[j] > numb[j-1]) aux2++;
           else{
            aux = max(aux,aux2);
            aux2=1;
        }
    }
    cout << max(aux,aux2);
    return 0;
}
