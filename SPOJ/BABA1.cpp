/*
*
* ARE YOU GOOD IN MATHS?
* https://www.spoj.com/problems/BABA1/
*
/*

#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    for(int i=1; i<=T; i++){
        double A;
        double H;
        cin>>H>>A;
        if(H*H-4.0*A<0){
            cout<<"-1"<<endl;
        }
        else{
            double sum=sqrt(H*H+4.0*A);
            double resta=sqrt(H*H-4.0*A);
            double lado1=(sum-resta)/2.0;
            double lado2=sum-lado1;
            if(lado1>lado2) swap(lado1,lado2);
            printf("%.6lf %.6lf %.6lf \n",lado1,lado2,H);
        }
    }
}
