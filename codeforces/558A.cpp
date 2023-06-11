#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
int n;
int manz[100];
int posicion[100];
int vector[200001];
int a=0;
int b=0;

int hallaab(){
    for(int i=0;i<=100000;i++){
        if(vector[i]!=0){
            a=a+1;
        }
    }
    for(int i=200000; i>=100000; i--){
        if(vector[i]!=0){
            b=b+1;
        }
    }
return a;
return b;
}

int suma(int a,int b){
    int sumanza1=0;
    int cont=0;
    if(b>a){
        for(int i=100000; i<=200000; i++){
            sumanza1=sumanza1+vector[i];
            if(vector[i]!=0){
            cont++;
            }
            if(cont>=a+1){
            break;
            }
        }
        cont=0;
        for(int i=100000; i>=0; i--){
        sumanza1=sumanza1+vector[i];
        if(vector[i]!=0){
            cont++;
            }
            if(cont>=a){
            break;
            }
        }
    }
    cont=0;
    if(b<a){
        for(int i=100000; i>=0; i--){
        sumanza1=sumanza1+vector[i];
        if(vector[i]!=0){
            cont++;
            }
            if(cont>=b+1){
            break;
            }
        }
        cont=0;
        for(int i=100000; i<=200000; i++){
        sumanza1=sumanza1+vector[i];
        if(vector[i]!=0){
            cont++;
            }
            if(cont>=b){
            break;
            }
        }
    }
    if(b==a){
        for(int i=100000; i<=200000; i++){
            sumanza1=sumanza1+vector[i];
            if(vector[i]!=0){
            cont++;
            }
            if(cont>=a){
            break;
            }
        }
        cont=0;
        for(int i=100000; i>=0; i--){
        sumanza1=sumanza1+vector[i];
        if(vector[i]!=0){
            cont++;
            }
            if(cont>=a){
            break;
            }
        }
    }
return sumanza1;
}

int main(){
    cin>>n;
    for(int i=0; i<=n-1; i++){
    cin>>posicion[i]>>manz[i];
    vector[100000+posicion[i]]=manz[i];
    }
    hallaab();
    cout<<suma(a,b)<<endl;
}
