#include <bits/stdc++.h>
bool flag = false;
using namespace std;
int cont[100001];
int main(){
    int n;
    cin >> n;
    vector <int> numb;
    for(int i = 0; i<n; i++){
        int a;
        cin >> a;
        cont[a]++;
        numb.push_back(a);
    }
    sort(numb.begin(), numb.end());
    if(cont[numb[n-1]]%2) cout << "Conan";
    else{
        for(int i = 0; i<100001; i++){
            if(cont[i]%2){
                flag = true;
                break;
            }
        }
        if(flag) cout << "Conan";
        else cout << "Agasa";
    }
    return 0;
}
