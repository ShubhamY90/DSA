class Solution {
public:
    bool helper(vector<int>& nums, int s, int i, int& total, vector<vector<int>>& dp){
        if(i == nums.size() && s == (total)/2) return true;
        else if(i == nums.size()) return false;
        if(dp[i][s] != -1) return dp[i][s];
        return (dp[i][s] = (helper(nums, s + nums[i], i + 1, total, dp) || helper(nums, s, i + 1, total, dp)));
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        if(sum % 2 != 0) return false;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return helper(nums, 0, 0, sum, dp);
    }
};