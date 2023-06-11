#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin>>N;
    string si;
    cin>>si;
    int vecc[3]={0,1,2};
    string bse="RBG";
    int minm=INT_MAX;
    string strr;
    do{
        string comp;
        int cont=0;
        for(int i=0;i<N;i++){
            comp+=bse[vecc[i%3]];
            if(comp[i]!=si[i]){
                cont++;
            }
        }
        if(minm>cont){
            minm=cont;
            strr=comp;
        }
    }while(next_permutation(vecc,vecc+3));
    cout<<minm<<endl;
    cout<<strr;
    return 0;
}
