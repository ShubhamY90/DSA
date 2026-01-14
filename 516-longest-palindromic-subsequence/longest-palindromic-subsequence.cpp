class Solution {
public:
    int longestPalindromeSubseq(string s) {
        //reverse string as s1 and then find common subsequence
        vector<vector<int>> dp(s.length() + 1, vector<int>(s.length() + 1, 0));
        string s1 = s;
        reverse(s1.begin(), s1.end());
        for(int i = 1; i <= s.length(); i++){
            for(int j = 1; j <= s.length(); j++){
                if(s[i - 1] == s1[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[s.length()][s.length()];
    }
};