/*
*
* Time and Space Complexity:
*   https://bit.ly/2TMQrom 
*
*/
#include<bits/stdc++.h>
using namespace std;
long long t;
int main(){
    string entrada;
    cin>>t;
    while(t>0){
    cin>>entrada;
    long long contg=0;
    long long contv=0;
    long long posicv[100001];
    for(long long i=0; i<=entrada.length()-1;i++){
       if(entrada[i]=='a'||entrada[i]=='e'||entrada[i]=='i'||entrada[i]=='o'||entrada[i]=='u'||entrada[i]=='A'||entrada[i]=='E'||entrada[i]=='I'||entrada[i]=='O'||entrada[i]=='U'){
           contv++;
           posicv[contv]=i+1;
       }
    }
    for(long long i=1; i<contv; i++){
        for(long long j=posicv[i]; j<=posicv[i+1]-1; j++){
            contg=contg+1*i;
        }
    }
    contg=contg+contv*(entrada.length()-posicv[contv]+1);
    long long vocalpos[contv+1];
    vocalpos[0]=contg;
    for(long long i=1; i<=contv-1;i++){
        vocalpos[i]=vocalpos[i-1]-(entrada.length()-posicv[i]+1);
    }
    for(long long i=1; i<=contv-1;i++){
        vocalpos[i]=vocalpos[i]*(posicv[i+1]-posicv[i]);
    }
    contg=contg*posicv[1];
    for(long long i=1; i<=contv-1;i++){
        contg=contg+vocalpos[i];
    }
    cout<<contg<<endl;
    t--;
    }
}
