#include <bits/stdc++.h>
using namespace std;
vector<vector<bool> > chess;
int n;
int movex[8]={2,-2,2,-2,1,-1,1,-1};
int movey[8]={1,1,-1,-1,2,2,-2,-2};
void backtrack(int sti,int stj, int temp , int &answ){
    answ=max(answ,temp);
    for(int i=0;i<8;i++){
        int auxx = sti+movex[i];
        int auxy = stj+movey[i];
        if(auxx>=0 && auxx<10 && auxy>=0 && auxy<10 && chess[auxx][auxy]==1){
            chess[auxx][auxy]=0;
            backtrack(auxx,auxy,temp+1,answ);
            chess[auxx][auxy]=1;
        }
    }
}
int main(){
    int c=0;
    while(true){
        c++;
        int countansw = 0;
        cin >> n;
        if(n==0) break;
        chess = vector<vector<bool> > (10,vector<bool> (10,0));
        int startj;
        for(int i=0;i<n;++i){
            int tab;
            int value;
            scanf("%d %d",&tab,&value);
            countansw += value;
            if(i==0) startj = tab;
            for(int j=0;j<value;++j) chess[i][tab+j] = 1;
        }
        int ans=0;
        chess[0][startj] = 0;
        backtrack(0,startj,1,ans);
        if((countansw-ans)==1) printf("Case %d, %d square can not be reached.\n",c,countansw-ans);
        else printf("Case %d, %d squares can not be reached.\n",c,countansw-ans);
    }
    return 0;
}
