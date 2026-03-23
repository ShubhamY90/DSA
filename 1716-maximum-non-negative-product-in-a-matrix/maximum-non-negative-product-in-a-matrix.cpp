class Solution {
private:
    using ll = long long;
    int mod = 1e9 + 7;
    vector<vector<pair<ll,ll>>> dp;
    vector<int> drow = {1, 0};
    vector<int> dcol = {0, 1};
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        dp.assign(n,vector<pair<ll,ll>>(m,{0,0}));
        //Tabulation
        dp[n-1][m-1] = make_pair(grid[n-1][m-1],grid[n-1][m-1]);
        for(int r = n-1; r >= 0; r--){
            for(int c = m-1; c >= 0; c--){
                if(r == n-1 && c == m-1) continue;
                ll currVal = grid[r][c];
                ll maxi = -1e9, mini = 1e9;
                for(int i = 0; i < 2; i++){
                    int newr = r + drow[i];
                    int newc = c + dcol[i];
                    if(newr >= 0 && newr < n && newc >= 0 && newc < m){
                        auto nextData = dp[newr][newc];
                        maxi = max({maxi,nextData.first*currVal,nextData.second*currVal});
                        mini = min({mini,nextData.first*currVal,nextData.second*currVal});
                    }
                }
                dp[r][c] = {maxi,mini};
            }
        }
        auto result = dp[0][0];
        if(result.first < 0) return -1;
        return result.first%mod;
    }
};