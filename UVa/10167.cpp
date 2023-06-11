#include<bits/stdc++.h>
using namespace std;
int X[150],Y[150];
int main(){
    int n;
    while(cin>>n){
        if(n==0) break;
        int A,B,i;
        for(i=0;i<2*n;i++){
            cin>>X[i]>>Y[i];
        }
        for(A=-500;A<=500;A++){
            for(B=-500;B<=500;B++){
                int verif=1;
                int arriba=0;
                int abajo=0;
                int iguales=0;
                    for(i=0;i<2*n;i++){
                        int m=A*X[i]+B*Y[i];
                        if(m>0) arriba++;
                        else if(m<0) abajo++;
                        else iguales++;
                        if(arriba>n || abajo>n || iguales>0){
                            verif=0;break;
                        }         
                    }
                if(verif && abajo==arriba)
                goto salir;
            }
        }
        salir:;
        cout<<A<<" "<<B<<endl;
    }
    return 0;
}
