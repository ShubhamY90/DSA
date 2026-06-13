class Solution {
public:
    int helper(vector<int>& nums, int i, int s, vector<vector<int>>& dp, int& sum){
        if(i == nums.size()) return s;
        if(dp[i][s + sum] != -1) return dp[i][s + sum]; 
        return dp[i][s + sum] = min(abs(helper(nums, i + 1, s - nums[i], dp ,sum)), abs(helper(nums, i + 1, s + nums[i], dp, sum)));
    }
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += stones[i];
        }
        vector<vector<int>> dp(n, vector<int>(2*sum + 1, -1));
        return helper(stones, 0, 0, dp, sum);
    }
};