class Solution {
public:
    int lcs(string& a, string& b, int i, int j,
            vector<vector<int>>& dp) {

        if (i == a.size() || j == b.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (a[i] == b[j])
            return dp[i][j] = 1 + lcs(a, b, i + 1, j + 1, dp);

        return dp[i][j] = max(
            lcs(a, b, i + 1, j, dp),
            lcs(a, b, i, j + 1, dp)
        );
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        lcs(str1, str2, 0, 0, dp);

        string ans;
        int i = 0, j = 0;

        while (i < n && j < m) {

            if (str1[i] == str2[j]) {
                ans += str1[i];
                i++;
                j++;
            }
            else {
                int down = (i + 1 < n)
                    ? dp[i + 1][j]
                    : 0;

                int right = (j + 1 < m)
                    ? dp[i][j + 1]
                    : 0;

                if (down >= right) {
                    ans += str1[i];
                    i++;
                } else {
                    ans += str2[j];
                    j++;
                }
            }
        }

        while (i < n)
            ans += str1[i++];

        while (j < m)
            ans += str2[j++];

        return ans;
    }
};