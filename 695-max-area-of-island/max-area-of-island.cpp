class Solution {
public:
    void dfs(vector<vector<int>>& grid, int r, int c, int i, int j, int& area){
        if(i < 0 || j < 0 || i >= r || j >= c){
            return;
        }
        if(grid[i][j] == 0) return;

        grid[i][j] = 0;
        area++;
        vector<vector<int>> ch = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        for(int k = 0; k < 4; k++){
            dfs(grid, r, c, i + ch[k][0], j + ch[k][1], area);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    int area = 0;
                    dfs(grid, m, n, i, j, area);
                    //cout << i << ", " << j << " : " << area << endl;
                    ans = max(area, ans);
                }
            }
        }
        return ans;
    }
};