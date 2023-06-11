/*
*
*
* 87: Prime power triples
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
bool arr[5*1000*1000*10];
int main(){
    long long contpr=0;
        long long m;
        cin>>m;
        int nam=sqrt(m)+1;
        isprime(nam);
        for(int i=0; i<cont;i++){
            for(int j=0; j<cont; j++){
                for(int k=0; k<cont; k++){
                    if(numpr[i]*numpr[i]+numpr[j]*numpr[j]*numpr[j]+numpr[k]*numpr[k]*numpr[k]*numpr[k]>=m) break;
                    if(arr[numpr[i]*numpr[i]+numpr[j]*numpr[j]*numpr[j]+numpr[k]*numpr[k]*numpr[k]*numpr[k]]==1) continue;
                    //cout<<numpr[i]*numpr[i]+numpr[j]*numpr[j]*numpr[j]+numpr[k]*numpr[k]*numpr[k]*numpr[k]<<endl;
                    //cout<<numpr[i]<<" "<<numpr[j]<<" "<<numpr[k]<<endl;
                    contpr++;
                    arr[numpr[i]*numpr[i]+numpr[j]*numpr[j]*numpr[j]+numpr[k]*numpr[k]*numpr[k]*numpr[k]]=1;
                }
            }
        }
    cout<<"\n"<<contpr<<endl;
}
