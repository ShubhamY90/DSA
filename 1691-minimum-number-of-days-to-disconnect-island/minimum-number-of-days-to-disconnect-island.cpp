class Solution {
public:
    // any two at max in diagnols can be deleted to make a single component
    /*
        1 1 1 1        1 0 1 1
        1 1 1 1   ->   0 1 1 1
        1 1 1 1        1 1 1 1

        now check if already there are disconnected componentes exist if so return 0
        check if removing any 1 causes disconnected component then return 1
        otherwise return 2
    */
    int m;
    int n;

    bool valid(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j){
        m = grid.size();
        n = grid[0].size();
        if(i < 0 || j < 0 || i >= m || j >= n || vis[i][j] || !grid[i][j]){
            return;
        }
        vis[i][j] = true;
        dfs(grid, vis, i, j - 1);
        dfs(grid, vis, i, j + 1);
        dfs(grid, vis, i - 1, j);
        dfs(grid, vis, i + 1, j);
    }
    int minDays(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // checking if there exist only one connected component
        vector<vector<bool>> vis1(m, vector<bool>(n, false));
        int a1 = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] && !vis1[i][j]){
                    dfs(grid, vis1, i, j);
                    a1++;
                }
            }
        }
        if(a1 > 1 || a1 < 1) return 0; 

        //trying to remove single block of 1 and checking

        int dx[] = {0, 0, -1, 1};
        int dy[] = {1, -1, 0, 0};
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    vector<vector<bool>> vis(m, vector<bool>(n, false));
                    grid[i][j] = 0;

                    int sx = -1, sy = -1;

                    // Find one adjacent land cell
                    for (int k = 0; k < 4; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];

                        if (valid(nx, ny) && grid[nx][ny]) {
                            sx = nx;
                            sy = ny;
                            break;
                        }
                    }

                    if (sx != -1) {
                        dfs(grid, vis, sx, sy);

                        bool disconnected = false;

                        // Check if any adjacent land wasn't reached
                        for (int k = 0; k < 4; k++) {
                            int nx = i + dx[k];
                            int ny = j + dy[k];

                            if (valid(nx, ny) && grid[nx][ny] && !vis[nx][ny]) {
                                disconnected = true;
                                return 1;
                            }
                        }
                    }
                    else{
                        return 1;
                    }
                    grid[i][j] = 1; 
                }
            }
        }
        return 2;
    }
};