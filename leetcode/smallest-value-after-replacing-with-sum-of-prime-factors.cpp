class Solution {
public:
    int solve(int n){
        int ans = 0;
        for(int i=2; 1LL*i*i<=n; i++){
            while(n%i == 0){
                n /= i;
                ans += i;
            }
        }
        if(n != 1) ans += n;
        return ans;
    }

    int smallestValue(int n) {
        int prev_val = -1;
        while(n != prev_val){
            prev_val = n;
            n = solve(n);
        }
        return n;
    }
};