#include <bits/stdc++.h>
using namespace std;
bool letter[26];
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(n<26){
        cout<<"NO";
        return 0;
    }
    for(int i=0; i<n; i++){
        if(s[i]=='a' || s[i]=='A') letter[0]=1;
        if(s[i]=='b' || s[i]=='B') letter[1]=1;
        if(s[i]=='c' || s[i]=='C') letter[2]=1;
        if(s[i]=='d' || s[i]=='D') letter[3]=1;
        if(s[i]=='e' || s[i]=='E') letter[4]=1;
        if(s[i]=='f' || s[i]=='F') letter[5]=1;
        if(s[i]=='g' || s[i]=='G') letter[6]=1;
        if(s[i]=='h' || s[i]=='H') letter[7]=1;
        if(s[i]=='i' || s[i]=='I') letter[8]=1;
        if(s[i]=='j' || s[i]=='J') letter[9]=1;
        if(s[i]=='k' || s[i]=='K') letter[10]=1;
        if(s[i]=='l' || s[i]=='L') letter[11]=1;
        if(s[i]=='m' || s[i]=='M') letter[12]=1;
        if(s[i]=='n' || s[i]=='N') letter[13]=1;
        if(s[i]=='o' || s[i]=='O') letter[14]=1;
        if(s[i]=='p' || s[i]=='P') letter[15]=1;
        if(s[i]=='q' || s[i]=='Q') letter[16]=1;
        if(s[i]=='r' || s[i]=='R') letter[17]=1;
        if(s[i]=='s' || s[i]=='S') letter[18]=1;
        if(s[i]=='t' || s[i]=='T') letter[19]=1;
        if(s[i]=='u' || s[i]=='U') letter[20]=1;
        if(s[i]=='v' || s[i]=='V') letter[21]=1;
        if(s[i]=='w' || s[i]=='W') letter[22]=1;
        if(s[i]=='x' || s[i]=='X') letter[23]=1;
        if(s[i]=='y' || s[i]=='Y') letter[24]=1;
        if(s[i]=='z' || s[i]=='Z') letter[25]=1;
    }
    int count=0;
    for(int i=0; i<26; i++){
        count=count+letter[i];
    }
    if(count == 26) cout<<"YES";
    else cout<<"NO";
    return 0;
}
