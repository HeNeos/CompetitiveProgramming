#include <iostream>
using namespace std;

int main() {
    for(int a=1; a<=9; a++){
        for(int b=0; b<=9; b++){
            for(int c=0; c<=9; c++){
                int x = 10*a+b;
                int y1 = 10*c+a;
                int y2 = 10*b+c;
                if(x < y1){
                    if(x*c == b*y1){
                        cout << x << "/" << y1 << endl;
                    }
                }
                if(x < y2){
                    if(x*c == a*y2){
                        cout << x << "/" << y2 << endl;
                    }
                }
            }
        }
    }
    return 0;
}