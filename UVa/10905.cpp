#include<bits/stdc++.h>
using namespace std;
int N;
string numb;
vector <string> arr;
string aux;
bool cmp(string a, string b){
    string x1=a+b;
    string x2=b+a;
    if(x1>x2) return(true);
    else return(false);
}
int main(){
    vector <string> arr2;
    while(1){
        cin>>N;
        arr.clear();
        if(N==0) break;
        for(int i=1; i<=N; i++){
            cin>>numb;
            arr.push_back(numb);
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<N-1; j++){    
                if(!(cmp(arr[j],arr[j+1]))) swap(arr[j],arr[j+1]);
            }
        }
        for(int i=0; i<N; i++){
            cout<<arr[i];
        }
        cout<<"\n";
    }
    return 0;
}
