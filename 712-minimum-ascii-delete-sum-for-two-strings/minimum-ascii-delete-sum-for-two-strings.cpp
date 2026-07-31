class Solution {
public:
    int dp[1001][1001];
    int helper(string &s1, string &s2, int i, int j){
        if(i == (int)s1.length() || j == (int)s2.length()){
            return 0;
        }
        
        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]){
            return dp[i][j] = (int)s1[i] + helper(s1, s2, i + 1, j + 1);
        }
        
        return dp[i][j] = max(helper(s1, s2, i + 1, j), helper(s1, s2, i, j + 1));
    }
    int minimumDeleteSum(string s1, string s2) {
        
        memset(dp, -1, sizeof(dp));
        
        int ans = 0;
        for(int i = 0; i < (int)s1.length(); i++){
            ans += s1[i];
        }

        for(int i = 0; i < (int)s2.length(); i++){
            ans += s2[i];
        }

        return ans - (2*helper(s1, s2, 0, 0));
    }
};