class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pr(n + 1, 0);
        vector<int> dp(n + 1, INT_MAX);
        dp[1] = 0;
        for(int i = 1; i <= n; i++){
            pr[i] = pr[i - 1] + nums[i - 1];
            if(i == 1) continue;
            dp[i] = min(pr[i - 1], dp[i - 1]);
            cout << dp[i] << " ";
        }
        
        int ans = INT_MIN;
        for(int i = 1; i <= n; i++){
            ans = max(pr[i] - dp[i], ans);
        }
        return ans;
    }
};