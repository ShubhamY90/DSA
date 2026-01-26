class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<pair<int, int>> dp(k + 1, {INT_MIN, INT_MIN});
        dp[0].first = 0;
        dp[0].second = 0;
        for(int j = 0; j < prices.size(); j++){
            for(int i = 1; i < k + 1; i++){
                dp[i].first = max(dp[i - 1].second - prices[j], dp[i].first);
                dp[i].second = max(dp[i].first + prices[j], dp[i].second);
            }
        }
        return dp[k].second;
    }
};