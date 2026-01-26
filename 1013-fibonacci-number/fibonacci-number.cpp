class Solution {
public:
    int fib(int n) {
        
        int pi2 = 0;
        int pi1 = 1;
        if(n == 0) return pi2;
        if(n == 1) return pi1;
        for(int i = 2; i <= n; i++){
            int temp = pi1;
            pi1 = pi1 + pi2;
            pi2 = temp;
            //dp[i] = dp[i - 1] + dp[i - 2]; 
        }
        return pi1;
    }
};