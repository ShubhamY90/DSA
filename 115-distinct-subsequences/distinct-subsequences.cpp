class Solution {
public:
    int helper(string& s, string& t, int i, int j, int ans, vector<vector<int>>& dp){
        if(j == t.length()) return 1;
        if(i == s.length()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int take = 0;
        int skip = 0;
        if(s[i] == t[j]){
            take = helper(s, t, i + 1, j + 1, ans, dp);
        }
        skip = helper(s, t, i + 1, j, ans, dp);
        return dp[i][j] = skip + take;

    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.length(), vector<int>(t.length(), -1));
        return helper(s, t, 0, 0 ,0, dp);
    }
};