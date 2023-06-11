#include<bits/stdc++.h>
using namespace std;
string torre;
int torrey;
int torrex;
string caballo;
int caballoy;
int caballox;
int solx;
int soly;
int sol=0;
int main(){
    cin>>torre;
    cin>>caballo;
    torrey=torre[1]-48;
    caballoy=caballo[1]-48;
    torrex=torre[0]-96;
    caballox=caballo[0]-96;
    for(solx=1; solx<=8; solx++){
        for(soly=1; soly<=8; soly++){
            if(solx==caballox && soly==caballoy) continue;
            if(solx==torrex || soly==torrey) continue;
            if((solx==caballox+1 && (soly==caballoy-2 || soly==caballoy+2)) || (solx==caballox-1 && (soly==caballoy-2 || soly==caballoy+2))) continue;
            if((solx==caballox+2 && (soly==caballoy-1 || soly==caballoy+1)) || (solx==caballox-2 && (soly==caballoy-1 || soly==caballoy+1))) continue;
            if((torrex==solx+1 && (torrey==soly-2 || torrey==soly+2)) || (torrex==solx-1 && (torrey==soly-2 || torrey==soly+2))) continue;
            if((torrex==solx+2 && (torrey==soly-1 || torrey==soly+1)) || (torrex==solx-2 && (torrey==soly-1 || torrey==soly+1))) continue;
            sol++;
        }
    }
    cout<<sol<<endl;
}
