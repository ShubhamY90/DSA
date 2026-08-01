class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        pq.push({grid[0][0], 0, 0});
        dist[0][0] = grid[0][0];
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};
        while(!pq.empty()){
            auto [wt, i, j] = pq.top();
            pq.pop();
            for(int k = 0; k < 4; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(nx >= 0 && nx < n && ny >= 0 && ny < n){
                    int newCost = max(wt, grid[nx][ny]);
                    if(newCost < dist[nx][ny]) {
                        dist[nx][ny] = newCost;
                        pq.push({newCost, nx, ny});
                    }
                }
            }
        }
        return dist[n - 1][n - 1];
    }
};