class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j, int n, int m, vector<vector<bool>>& visited){
        visited[i][j] = true;
        if(i > 0){
            if(grid[i - 1][j] == '1' && !visited[i - 1][j]) dfs(grid, i - 1, j, n, m, visited);
        }

        if(i < n - 1) {
            if(grid[i + 1][j] == '1' && !visited[i + 1][j]) {
                dfs(grid, i + 1, j, n, m, visited);
            }
        }

        // left
        if(j > 0) {
            if(grid[i][j - 1] == '1' && !visited[i][j - 1]) {
                dfs(grid, i, j - 1, n, m, visited);
            }
        }

        // right
        if(j < m - 1) {
            if(grid[i][j + 1] == '1' && !visited[i][j + 1]) {
                dfs(grid, i, j + 1, n, m, visited);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, (vector<bool>(m, false)));
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    ans++;
                    dfs(grid, i, j, n, m, visited);
                }
            }
        }
        return ans;
    }
};