class Solution {
public:
    long long lcm(int a, int b){
        return 1LL*a*b/__gcd(a, b);
    }

    int nthMagicalNumber(int n, int a, int b) {
        // x -> x/a + x/b - x/(lcm(a, b)) = n
        long long lo = 1;
        long long hi = (1LL<<60);
        while(lo < hi){
            long long me = lo + (hi - lo)/2;
            if(me/a + me/b - me/lcm(a, b) >= n) hi = me;
            else lo = me+1;
        }
        return lo%(1000000007);
    }
};