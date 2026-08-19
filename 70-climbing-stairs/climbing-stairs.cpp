class Solution {
public:
    int dp[46];
    int helper(int n, int i){
        if(i > n) return 0;
        if(i == n) return 1;
        if(dp[i] != -1) return dp[i];

        return dp[i] = helper(n, i + 1) + helper(n, i + 2);
    }
    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        return helper(n, 0);
    }
};