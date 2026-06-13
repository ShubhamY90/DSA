class Solution {
public:
    int MOD = 1e9 + 7;

    int helper(int i, int members, int prof, int n, int minProfit,
               vector<int>& group, vector<int>& profit,
               vector<vector<vector<int>>>& dp) {

        if(i == group.size())
            return prof == minProfit;

        if(dp[i][members][prof] != -1)
            return dp[i][members][prof];

        long long take = 0, notTake = 0;

        notTake = helper(i + 1, members, prof,
                         n, minProfit, group, profit, dp);

        if(members + group[i] <= n) {
            take = helper(i + 1,
                          members + group[i],
                          min(minProfit, prof + profit[i]),
                          n, minProfit, group, profit, dp);
        }

        return dp[i][members][prof] = (take + notTake) % MOD;
    }

    int profitableSchemes(int n, int minProfit,
                          vector<int>& group, vector<int>& profit) {

        int m = group.size();

        vector<vector<vector<int>>> dp(
            m,
            vector<vector<int>>(n + 1,
            vector<int>(minProfit + 1, -1))
        );

        return helper(0, 0, 0, n, minProfit, group, profit, dp);
    }
};