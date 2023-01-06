#include <iostream>
#include <vector>
using namespace std;

int main(){
    int a, b; cin >> a >> b;
    bool found = false;
    vector <int> seq;
    seq.push_back(b);
    while(b > 0){
        if(b%2 != 0 and b%10 != 1) break;
        while(b%2 == 0 && b != a){
            b /= 2;
            seq.push_back(b);
            if(b == a){
                found = true;
                break;
            }
        }
        while(b%10 == 1 && b != a){
            b -= 1;
            b /= 10;
            seq.push_back(b);
            if(b == a){
                found = true;
                break;
            }
        }
        if(found) break;
    }
    if(found){
        cout << "YES\n";
        cout << seq.size() << '\n';
        for(int i=seq.size()-1; i>=0; i--) cout << seq[i] << " ";
    }
    else cout << "NO";
    cout << '\n';
    return 0;
}