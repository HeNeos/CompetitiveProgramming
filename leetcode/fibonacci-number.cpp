class Solution {
public:
    int fib(int n) {
        int a = 0;
        int b = 1;
        while(n--){
            b = a+b;
            a = b-a;
        }
        return a;
    }
};