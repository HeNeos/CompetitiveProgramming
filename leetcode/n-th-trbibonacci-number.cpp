class Solution {
public:
    int tribonacci(int n) {
        long long a = 0;
        long long b = 1;
        long long c = 1;
        while(n--){
            long long aux = a;
            a = b;
            b = c;
            c = a+b+aux;
        }
        return a;
    }
};