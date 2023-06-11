/*
*
*
* Largest prime factor
*
*
*/

#include<bits/stdc++.h>
using namespace std;
long long N;
int cont=0;
vector <long long> numpr; 
void isprime(long long number){
    bool primo[number+1];
    memset(primo, true, sizeof(primo));
    for(int i=2; i*i<=number; i++){
        if(primo[i]==true){
            for(int j=i*i; j<=number; j=j+i){
                primo[j]=false;
            }
        }
    }
    for(int i=2; i<=number; i++){
        if(primo[i]){
            cont++;
            numpr.push_back(i);
            //cout<<numpr[cont-1]<<" ";
        }
    }
}

int main(){
    cin>>N;
    int nam=sqrt(N)+1;
    isprime(nam);
    for(int i=0; i<=cont-1; i++){
        if(N%numpr[i]==0){
            cout<<numpr[i]<<" "<<N/numpr[i]<<endl;
        }
    }
    return 0;
}
