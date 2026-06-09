class Solution {
public:
    int helper(string& s, int i, vector<int>& dp){
        if(i == s.length()) return 1;
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];
        if(i == s.length() - 1) return helper(s, i + 1, dp);
        int ans = helper(s, i + 1, dp);
        if((s[i] - '0')*10 + (s[i + 1] - '0') >= 10 && (s[i] - '0')*10 + (s[i + 1] - '0') <= 26) ans += helper(s, i + 2, dp);
        return dp[i] = ans;
    }
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n + 1, 0);
        dp[n] = 1;
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == '0'){
                dp[i] = 0;
                continue;
            }
            dp[i] = dp[i + 1];
            if(i == n - 1){
                continue;
            }
            if((s[i] - '0')*10 + (s[i + 1] - '0') >= 10 && (s[i] - '0')*10 + (s[i + 1] - '0') <= 26){
                dp[i] += dp[i + 2];
            }
        }
        return dp[0];
        //return helper(s, 0, dp);
    }
};