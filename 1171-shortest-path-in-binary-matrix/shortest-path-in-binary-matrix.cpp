class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;

        queue<pair<int,int>> q;
        q.push({0,0});
        q.push({-1,-1});

        grid[0][0] = 1;
        int ans = 1;

        int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[8] = {-1,  0,  1, -1, 1, -1, 0, 1};

        while (!q.empty()) {
            auto [r,c] = q.front();
            q.pop();

            if (r == -1 && c == -1) {
                ans++;
                if (!q.empty()) q.push({-1,-1});
                continue;
            }

            if (r == n-1 && c == n-1) return ans;

            for (int i = 0; i < 8; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                    q.push({nr, nc});
                    grid[nr][nc] = 1;
                }
            }
        }

        return -1;
    }
};