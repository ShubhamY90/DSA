class Solution {
public:
    int helper(vector<int> nums, int i, bool prev, vector<vector<int>>& dp){
        if(i == nums.size()) return 0;
        if(dp[i][prev] != -1) return dp[i][prev];
        if(prev) return dp[i][prev] = helper(nums, i + 1, false, dp);
        int skip = helper(nums, i + 1, false, dp);
        int take = nums[i] + helper(nums, i + 1, true, dp);
        return dp[i][prev] = max(skip, take);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        bool prev = false;
        dp[n][0] = 0;
        dp[n][1] = 0;
        for(int i = n - 1; i >= 0; i--){
            dp[i][1] = dp[i + 1][0];
            
            dp[i][0] = max(dp[i + 1][0], nums[i] + dp[i + 1][1]);
            
        }
        return max(dp[0][0], dp[0][1]);

        return helper(nums, 0, false, dp);
    }
};