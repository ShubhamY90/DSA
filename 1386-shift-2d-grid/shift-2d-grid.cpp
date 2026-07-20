class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int t = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans[((t + k)/n)% m][(j + k)%n] = grid[i][j];
                t++;
            }
        }
        return ans;
    }
};