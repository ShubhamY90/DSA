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
        vector<vector<int>> dp(n + 1, vector<int>(2001, 0));
        dp[n][target + 1000] = 1;
        for(int i = n - 1; i >= 0; i--){
            for(int s = -1000; s <= 1000; s++){
                int temp = 0;
                if(s + nums[i] + 1000 <= 2000){
                    temp += dp[i + 1][s + nums[i] + 1000];
                }
                if(s - nums[i] + 1000 >= 0){
                    temp += dp[i + 1][s - nums[i] + 1000];
                }
                dp[i][s+1000] = temp;
            }
        }
        return dp[0][1000];
        return helper(nums, target, 0, 0, dp);
    }
};