#include<bits/stdc++.h>
using namespace std;
vector <int> pos;
long long N;
int main(){
    long long aux;
    while(cin>>N,N){
        pos.clear();
        long long auxN=N;
        long long an=0;
        long long bn=0;
        //int cont=0;
        int cont=1;
        int i=0;
         while(auxN > 0){
            if(auxN & 1){
                if(cont & 1) an |= (1 << i);
                else bn |= (1 << i);
                cont++;
            }
            auxN >>= 1;
            i++;
        }
        //for(int i=1; i<=52; i++){
        //    aux=__builtin_ctz(N);
        //    if(cont!=0 && aux==0) break;
        //    pos.push_back(aux);
        //    N=N-(1<<aux);
        //    if(i%2==1) an=an+(1<<aux);
        //    if(i%2==0) bn=bn+(1<<aux);
        //    cont++;
        //}
        cout<<an<<" "<<bn<<endl;
    }
}
//__builtin not work? :(
