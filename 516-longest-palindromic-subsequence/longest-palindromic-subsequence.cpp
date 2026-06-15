class Solution {
public:
    int helper(string& s, int i, int j, vector<vector<int>>& dp){
        if(j < i) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j] && i == j){
            return dp[i][j] = 1 + helper(s, i + 1, j - 1, dp);
        }
        if(s[i] == s[j] && i != j){
            return dp[i][j] = 2 + helper(s, i + 1, j - 1, dp);
        }
        return dp[i][j] = max(helper(s, i, j - 1, dp), helper(s, i + 1, j, dp));
    }
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.length() + 1, vector<int>(s.length() + 1, -1));
        return helper(s, 0, s.length() - 1, dp);
    }
};