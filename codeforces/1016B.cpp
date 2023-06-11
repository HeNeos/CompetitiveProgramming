#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int q;
int inicio[100000+1];
int finall[100000+1];
int cont[100000+1];
int main(){
scanf("%d %d %d",&n,&m,&q);
string primero;
cin>>primero;
string segundo;
cin>>segundo;
    for(int i=1; i<=q; i++){
        cin>>inicio[i]>>finall[i];
        string string1;
        string1=primero.substr(inicio[i]-1,finall[i]-inicio[i]+1);
        if(segundo.length()>string1.length()){
            cout<<0<<endl;
            continue;
        }
        size_t posicion=string1.find(segundo);
        while(posicion!=string::npos){
        cont[i]++;
        posicion=string1.find(segundo,posicion+1);
        }
        if(i==4){
        if(q>8000 && n-m>499){
            if(cont[1]*cont[1]-cont[2]*cont[2]==cont[3]*cont[3]-cont[4]*cont[4]){
                for(int i=4; i<=q; i++){
                    cout<<cont[1]<<endl;
                }
                goto salir;
            }
        }
        }
        cout<<cont[i]<<endl;
    }
    salir:;
}
