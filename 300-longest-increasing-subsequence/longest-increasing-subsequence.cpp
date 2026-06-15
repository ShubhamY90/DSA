class Solution {
public:
    // int helper(vector<int>& nums, int i, vector<int>& dp){
    //     if(i == nums.size()) return 0;
    //     //if(i == 0) return 1;
    //     int m = 1;
    //     if(dp[i] != -1) return dp[i];
    //     for(int j = i - 1; j >= 0; j--){
    //         if(nums[j] < nums[i]){
    //             m = max(m, 1 + helper(nums, j, dp));
    //         }
    //     }
    //     return dp[i] = m;
    // }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        //int ans = 0;
        vector<int> dp(n, 1);
        dp[0] = 1;
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i - 1; j >= 0; j--){
                if(nums[j] < nums[i]) dp[i] = max(dp[i], 1 + dp[j]);
            }
            ans = max(ans, dp[i]);
        }
        
        return ans;
        // for(int i = 0; i < n; i++){
        //     ans = max(ans, helper(nums, i, dp));
        // }
        // return ans;
    }
};