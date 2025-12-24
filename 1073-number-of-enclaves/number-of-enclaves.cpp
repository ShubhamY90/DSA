class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, bool& touches, int& count, int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        visited[i][j] = true;
        count += 1;
        if(i == m - 1 || j == n - 1 || i == 0 || j == 0){
            touches = true;
        }
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        for(int l = 0; l < dx.size(); l++){
            int ni = i + dx[l];
            int nj = j + dy[l];
            if(ni >= 0 && ni < m && nj >= 0 && nj < n){
                if(!visited[ni][nj] && grid[ni][nj] == 1){
                    dfs(grid, visited, touches, count, ni, nj);
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid[0].size();
        int m = grid.size();
        int ans = 0;
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    //cout << "visited at " << i << " ," << j << " time " << endl;
                    bool touches = false;
                    int count = 0;
                    dfs(grid, visited, touches, count, i, j);
                    if(!touches){
                        ans += count;
                    }
                }
            }
        }
        return ans;
    }
};