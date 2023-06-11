/*
*
* First solution
* use 'binary search'
*
*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    int cont=1;
    while(true){
        long long N;
        long long Q;
        cin >> N >> Q;
        if(N==0 && Q==0) break;
        vector <long long> numb;
        for(long long i=1; i<=N; i++){
            long long a;
            cin >> a;
            numb.push_back(a);
        }
        sort(numb.begin(), numb.end());
        vector <long long> quer;
        cout << "CASE# " << cont << ":\n";
        for(long long i=1; i<=Q; i++){
            long long b;
            cin >> b;
            long long lo = 0;
            long long hi = numb.size()-1;
            while(lo < hi){
                long long me = lo + (hi-lo)/2;
                if(numb[me] < b) lo = me + 1;
                else hi = me;
            }
            if(numb[lo] != b) cout << b << " not found" << "\n";
            else cout << b << " found at " << lo+1 << "\n";        
        }
        numb.clear();
        cont++;
    }
    return 0;
}

/*
*
* Second solution
* use 'lower_bound'
*
*
*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    int cont=1;
    while(true){
        long long N;
        long long Q;
        cin >> N >> Q;
        if(N==0 && Q==0) break;
        vector <long long> numb;
        for(long long i=1; i<=N; i++){
            long long a;
            cin >> a;
            numb.push_back(a);
        }
        sort(numb.begin(), numb.end());
        vector <long long> quer;
        cout << "CASE# " << cont << ":\n";
        for(long long i=1; i<=Q; i++){
            long long b;
            cin >> b;
            vector <long long>::const_iterator itr=lower_bound(numb.begin(),numb.end(),b);                        
            if(*itr != b) cout << b << " not found" << "\n";
            else cout << b << " found at " << itr-numb.begin() + 1 << "\n";        
        }
        numb.clear();
        cont++;
    }
    return 0;
}
