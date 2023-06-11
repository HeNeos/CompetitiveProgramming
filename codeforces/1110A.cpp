#include<bits/stdc++.h>
using namespace std;
int main(){
    int b;
    int k;
    cin>>b>>k;
    int arr[k];
    int suma=0;
    for(int i=0; i<k; i++){
        cin>>arr[i];
        suma=suma+arr[i];
    }
    if(!(b&1)){
        if((arr[k-1]%2)==0){
            cout<<"even";
            return 0;
        }
        else{
            cout<<"odd";
            return 0;
        }
    }
    else{
        if(suma%2==0){
            cout<<"even";
            return 0;
        }
        else{
            cout<<"odd";
            return 0;
        }
    }
}
