#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int numb;
        cin >> numb;
        if(numb&1){
            cout << "First";
            return 0;
        }
    }
    cout << "Second";
    return 0;
}
