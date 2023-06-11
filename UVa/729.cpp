#include <bits/stdc++.h>
using namespace std;
int main() {
    int test;
    cin>>test;
    for(int i=1; i<=test; i++){
        int hdist;
        int cntbits;
        cin >> cntbits >> hdist;
        int numbits[cntbits];
        bitset <16> numbers((1<<hdist)-1);
        for(int i=0; i<cntbits; i++) numbits[i]=numbers[cntbits-i-1];
        do{
        for(int i=0; i<cntbits; i++) cout<<numbits[i];
        cout<<"\n";
        }while(next_permutation(numbits,numbits+cntbits));
        if(i!=test) cout<<"\n";
    }
    return 0;
}
