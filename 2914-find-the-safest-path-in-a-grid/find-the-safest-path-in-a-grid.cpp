class Solution {
public:
    /*
        had the idea of creating te near array but how took hints
        had in mind of taking max greedily as iterating from start 
        BUT WILL NOT WORK
        INSTEAD
        took hints for binary search over safeness factor
        now from my approach discussed and got to know that i had to take global highest same to DIJKSTRA using pq
    */
    bool bfs(vector<vector<int>>& grid, vector<vector<int>>& near, int k){
        int n = grid.size();

        // If start/end themselves are unsafe, no valid path exists.
        if(near[0][0] < k || near[n - 1][n - 1] < k) return false;

        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        q.push({0,0});
        vis[0][0] = true;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while(!q.empty()){
            auto [i, j] = q.front();
            q.pop();

            if(i == n - 1 && j == n - 1) return true;

            for(int x = 0; x < 4; x++){
                int nx = i + dx[x];
                int ny = j + dy[x];

                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny]){
                    if(near[nx][ny] >= k){
                        q.push({nx, ny});
                    }
                    vis[nx][ny] = true;
                }
            }
        }

        return false;
    }

    // Priority Queue (Maximum Bottleneck Path) Approach
    int dijkstra(vector<vector<int>>& near){
        int n = near.size();

        // {current path safeness, row, col}
        priority_queue<vector<int>> pq;

        // best[i][j] = maximum safeness with which we have reached (i,j)
        vector<vector<int>> best(n, vector<int>(n, -1));

        pq.push({near[0][0], 0, 0});
        best[0][0] = near[0][0];

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();

            int safe = cur[0];
            int x = cur[1];
            int y = cur[2];

            if(x == n - 1 && y == n - 1)
                return safe;

            if(safe < best[x][y]) continue;

            for(int k = 0; k < 4; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx >= 0 && nx < n && ny >= 0 && ny < n){

                    // Safeness of a path is the minimum value encountered.
                    int newSafe = min(safe, near[nx][ny]);

                    if(newSafe > best[nx][ny]){
                        best[nx][ny] = newSafe;
                        pq.push({newSafe, nx, ny});
                    }
                }
            }
        }

        return 0;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return 0;

        vector<vector<int>> near(n, vector<int>(n, -1));
        queue<pair<int, int>> q;

        // Multi-source BFS from every thief to compute
        // distance of every cell from its nearest thief.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    near[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        int maxE = INT_MIN;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && nx < n && ny >= 0 && ny < n && near[nx][ny] == -1) {
                    near[nx][ny] = near[x][y] + 1;
                    maxE = max(maxE, near[nx][ny]);
                    q.push({nx, ny});
                }
            }
        }

        // ---------------- Binary Search + BFS ----------------
        // int l = 0;
        // int r = maxE;
        // int ans = 0;

        // while(l <= r){
        //     int mid = l + (r - l)/2;

        //     if(bfs(grid, near, mid)){
        //         ans = mid;
        //         l = mid + 1;
        //     }
        //     else{
        //         r = mid - 1;
        //     }
        // }

        // return ans;

        // ---------------- Priority Queue Approach ----------------
        return dijkstra(near);
    }
};