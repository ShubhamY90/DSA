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
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if(n == 2){
            return max(nums[0], nums[1]);
        }
        memset(dp, -1, sizeof(dp));
        int ans1 = helper(nums, false, 1);
        nums.pop_back();
        memset(dp, -1, sizeof(dp));
        int ans2 = helper(nums, false, 0);
        return max(ans1, ans2);
    }
};