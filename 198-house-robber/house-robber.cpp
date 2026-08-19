class Solution {
public:
    int dp[101][2];
    int helper(vector<int>& nums, bool prev, int i){
        int n = nums.size();
        if(i == n) return 0;
        int ans = INT_MIN;
        if(dp[i][prev] != -1) return dp[i][prev];
        if(!prev){
            ans = max(ans, nums[i] + helper(nums, true, i + 1));
        }
        ans = max(ans, helper(nums, false, i + 1));
        return dp[i][prev] = ans;
    }
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return helper(nums, false, 0);
    }
};