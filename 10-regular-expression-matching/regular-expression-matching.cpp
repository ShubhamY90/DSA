class Solution {
public:
    int dp[21][21];
    bool helper(string &s, string& p, int i, int j){
        if (j == p.length())
            return i == s.length();

        if(dp[i][j] != -1) return dp[i][j];
        bool first = (i < s.length() && (s[i] == p[j] || p[j] == '.'));

        if(j + 1 < p.length() && p[j + 1] == '*'){
            //if x* then i am either skipping x* together or i am using x any no. of times (*) only if the curr chars match otherwise false
            return dp[i][j] = (helper(s, p, i, j + 2) || (first && helper(s, p, i + 1, j)));
        }
        //normal char i am using 1, 1 of both as they are same
        //if not equal then i just return false as both must match completely
        return dp[i][j] = (first && helper(s, p, i + 1, j + 1));
    }
    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof(dp));
        return helper(s, p, 0, 0);
    }
};