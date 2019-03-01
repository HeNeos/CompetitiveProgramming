#include <bits/stdc++.h>
using namespace std;
int main(){
    int numb;
    int pairsnumb;
    int answ = 0;
    int answ2;
    vector<string> names;
    vector<int> pairss;
    cin>>numb>>pairsnumb;
    for(int i=0; i<numb; i++){
        string nam;
        cin >> nam;
        names.push_back(nam);
    }
    sort(names.begin(), names.end());
    for(int i=0; i<pairsnumb; i++){
        int pbits = 0;
        int ind = names.size()-1;
        string name;
        cin >> name;
        for(int j=0;j<names.size();j++){
            if(names[j]>name){
                ind = j -1;
                break;
            }
        }
        pbits = 1<<ind;
        cin >> name;
        ind = names.size()-1;
        for(int j=0;j<names.size();j++){
            if(names[j]>name){
                ind = j -1;
                break;
            }
        }
        pbits |= 1<<ind;
        pairss.push_back(pbits);

    }
    for(int i=(1<<numb)-1; i>=0; i--){
        int team=0;
        bool test = true;
        for(int j=0; j<pairsnumb; j++){
            if((i&pairss[j])==pairss[j]) test = false;
        }
        if(test){
            for(int j=0; j<numb; j++){
                if((i>>j)%2==1) team++;
            }
            if(team>answ){
                answ = team;
                answ2 = i;
            }
        }
    }
    cout<<answ<<"\n";
    for(int i=0; i<numb; i++){
        if((answ2>>i)%2==1) {
                cout<<names[i]<<"\n";
        }
    }
    return 0;
}
