class Solution {
public:
    int dp[501][501];
    int helper(string &s, int i, int j){
        if(i > j) return 0;

        //if odd
        if(i == j) return 1;

        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j]){
            return dp[i][j] = 2 + helper(s, i + 1, j - 1);
        }

        return dp[i][j] = max(helper(s, i + 1, j), helper(s, i, j - 1));
    }
    int minInsertions(string s) {
        memset(dp, -1, sizeof(dp));
        return (int)s.length() - helper(s, 0, (int)s.length() - 1);
    }
};