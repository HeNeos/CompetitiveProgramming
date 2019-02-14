#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
int N;
int A[20];
int B[20];
int C[20];
int x[20];
int y[20];
int z[20];
int prim[20];
int seg[20];
int terc[20];
int cont[20];
int maximo(int x, int y, int z){
  int maxim=max(x,max(y,z));
  return maxim;
}
int minimo(int x, int y, int z){
  int minm=min(x,min(y,z));
  return minm;
}
int main(){
  cin>>N;
  for(int p=0; p<=N-1; p++){
    cin>>A[p]>>B[p]>>C[p];
    for(x[p]=-100; x[p]<=100; x[p]++){
	   	  for(y[p]=-100; y[p]<=100; y[p]++){
	  	    z[p]=A[p]-x[p]-y[p];
	  	    if(x[p]*y[p]*z[p]==B[p] && (x[p]*x[p]+y[p]*y[p]+z[p]*z[p]==C[p] && (x[p]!=y[p] && (x[p]!=z[p] && y[p]!=z[p])))){
	  		    prim[p]=minimo(x[p],y[p],z[p]);
	  		    seg[p]=x[p]+z[p]+y[p]-minimo(x[p],y[p],z[p])-maximo(x[p],y[p],z[p]);
	  		    terc[p]=maximo(x[p],y[p],z[p]);
	  		    cont[p]=1;
	  		    goto salir;
	  	    }
		    }
    }
    salir:;
  }
  for(int k=0; k<=N-1; k++){
	  if(cont[k]==0) cout<<"No solution."<<endl;
    else cout<<prim[k]<<" "<<seg[k]<<" "<<terc[k]<<endl;
  }
}
