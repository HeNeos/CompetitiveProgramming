#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a;
    long long b;
    int cont=0;
    cin>>a>>b;
    if(a==b){
        cout<<"infinity";
        return 0;
    }
    else{
        for(int k=1; k*k<=(a-b); k++){
            if((a-b)%k==0){
                if(((a-b)/k)>b){
                    if(k>b) cont=cont+2;
                    else cont=cont+1;
                }
            }    
        }
    }
    if(floor(sqrt(a-b))*floor(sqrt(a-b))==(a-b) && floor(sqrt(a-b))>b){
        cont=cont-1;
    }
    cout<<cont;
    return 0;
}
