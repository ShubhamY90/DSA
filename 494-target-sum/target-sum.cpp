class Solution {
public:
    // void helper(vector<int>& nums, int target, int curr, int i, int& count){
    //     if(i == nums.size()){
    //         if(curr == target){
    //             count += 1;
    //         }
    //         return;
    //     }
    //     helper(nums, target, curr + nums[i], i + 1, count);
    //     helper(nums, target, curr - nums[i], i + 1, count);
    // }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int maxSum = 0;
        for (int i = 0; i < n; i++) {
            maxSum += nums[i];
        }

        // If target is outside possible sum range
        if (target > maxSum || target < -maxSum) return 0;

        int OFFSET = maxSum;

        // dp[i][s] = number of ways to get sum (s - OFFSET) using first i elements
        vector<vector<int>> dp(n + 1, vector<int>(2 * maxSum + 1, 0));

        // Base case: 1 way to make sum 0 using 0 elements
        dp[0][OFFSET] = 1;

        for (int i = 1; i <= n; i++) {
            for (int s = -maxSum; s <= maxSum; s++) {
                if (dp[i - 1][s + OFFSET] > 0) {
                    dp[i][s + nums[i - 1] + OFFSET] += dp[i - 1][s + OFFSET];
                    dp[i][s - nums[i - 1] + OFFSET] += dp[i - 1][s + OFFSET];
                }
            }
        }

        return dp[n][target + OFFSET];

        // int count = 0;
        // helper(nums, target, 0, 0, count);
        // return count;
    }
};