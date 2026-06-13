class Solution {
public:
    int helper(vector<int>& nums, int target, int s, int i, vector<vector<int>>& dp){
        if(i == nums.size() && s == target) return 1;
        else if(i == nums.size()) return 0;
        if(dp[i][s+1000] != -1) return dp[i][s+1000];
        return dp[i][s+1000] = helper(nums, target, s + nums[i], i + 1, dp) + helper(nums, target, s - nums[i], i + 1, dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(2001, -1));
        return helper(nums, target, 0, 0, dp);
    }
};