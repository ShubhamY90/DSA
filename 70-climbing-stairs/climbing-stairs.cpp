class Solution {
public:
    int helper(int n, int i, vector<int>& dp){
        if(i == n) return 1;
        if(i > n) return 0;
        
        if(dp[i] != - 1) return dp[i];

        return dp[i] = helper(n, i + 1, dp) + helper(n, i + 2, dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n + 2, -1);
        dp[n + 1] = 0;
        dp[n] = 1;
        for(int i = n - 1; i >= 0; i--){
            dp[i] = dp[i + 1] + dp[i + 2];
        }
        return dp[0];

        return helper(n, 0, dp);
    }
};