#include <bits/stdc++.h>
using namespace std;
int cntbit(long long a){
        int cnt = 0;
        if(a == 0) return 1;
        for(int i=1; i<33; i++){
                if(a==0) break;
                a /= 2;
                cnt++;
        }
        return cnt;
}
long long fstexpo(int a){
        if(a==0) return 1;
        if(a==1) return 2;
        if(a%2==0) return fstexpo(a/2)*fstexpo(a/2);
        else return fstexpo((a-1)/2)*fstexpo((a-1)/2)*2; 
}
int main(){
        long long a;
        long long b;
        while(cin >> a >> b){
                int cnta = cntbit(a);
                int cntb = cntbit(b);
                long long newa = fstexpo(max(cnta,cntb)) - 1 - a;
                long long newb = fstexpo(max(cnta,cntb)) - 1 - b;
                //cout << cnta << " " << cntb << " " << newa << " " << newb << endl;
                cout << ((a & newb) | (b & newa)) << "\n";
        }
        return 0;
}
