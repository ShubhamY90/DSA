class Solution {
public:
    void bfs(queue<pair<int,int>>& q,
         vector<vector<bool>>& vis,
         vector<vector<int>>& heights,
         vector<vector<int>>& dirs) {

        int m = heights.size();
        int n = heights[0].size();

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto& d : dirs) {
                int nx = x + d[0];
                int ny = y + d[1];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;

                if (vis[nx][ny])
                    continue;

                if (heights[nx][ny] < heights[x][y])
                    continue;

                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> ans;
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        queue<pair<int, int>> q1, q2;
        for(int i = 0; i < n; i++){
            q1.push({0, i});
            pacific[0][i] = true;
            q2.push({m - 1, i});
            atlantic[m - 1][i] = true;
        }
        for(int i = 0; i < m; i++){
            q1.push({i, 0});
            pacific[i][0] = true;
            q2.push({i, n - 1});
            atlantic[i][n - 1] = true;
        }
        bfs(q1, pacific, heights, dirs);
        bfs(q2, atlantic, heights, dirs);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(atlantic[i][j] && pacific[i][j]) ans.push_back({i, j});
            }
        }
        return ans;
    }
};