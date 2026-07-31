class Solution {
public:
    int dp[101][101];
    bool helper(string s1, string s2, string s3, int i, int j){
        if(i == s1.length() && j == s2.length()) return true;

        if(dp[i][j] != -1) return dp[i][j];

        bool ans = false;

        if(i < (int)s1.length() && s1[i] == s3[i + j]){
            ans |= helper(s1, s2, s3, i + 1, j);
        }

        if(j < (int)s2.length() && s2[j] == s3[i + j]){
            ans |= helper(s1, s2, s3, i, j + 1);
        }
        return dp[i][j] = ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length()) return false;
        memset(dp, -1, sizeof(dp));
        return helper(s1, s2, s3, 0, 0);
    }
};