class Solution {
public:
    bool helper(string s, int st, int e, unordered_map<string, bool>&words, vector<vector<int>>& dp){
        if(st == s.length()) return true;
        if(e == s.length()) return false;
        if(dp[st][e] != -1) return dp[st][e];
        bool ans = false;

        string curr = s.substr(st, e - st + 1);

        if (words.find(curr) != words.end()) {
            ans = helper(s, e + 1, e + 1, words, dp);
        }
        if (!ans) {
            ans = helper(s, st, e + 1, words, dp);
        }
        return dp[st][e] = ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_map<string, bool> words;
        vector<vector<int>> dp(n + 1, vector<int>(n+1, -1));
        for(auto word : wordDict){
            words[word] = true;
        }
        //return dp[n][n];
        return helper(s, 0, 0, words, dp);
    }
};