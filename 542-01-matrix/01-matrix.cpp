class Solution {
public:
    int INF = 1e4 + 1;
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dp(m, vector<int> (n, INF));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    dp[i][j] = 0;
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i > 0 && mat[i][j] != 0) dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j]);
                if(j > 0 && mat[i][j] != 0) dp[i][j] = min(dp[i][j - 1] + 1, dp[i][j]);
            }
        }
        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                if(i < m - 1 && mat[i][j] != 0) dp[i][j] = min(dp[i + 1][j] + 1, dp[i][j]);
                if(j < n - 1 && mat[i][j] != 0) dp[i][j] = min(dp[i][j + 1] + 1, dp[i][j]);
            }
        }
        return dp;
    }
};