class Solution {
public:
    // 1. Thought Dijkstra first
    // 2. Thought 0/1 BFS after hint
    bool helper(vector<vector<int>>& grid, int health){
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<pair<int, pair<int,int>>,vector<pair<int, pair<int,int>>>,greater<pair<int, pair<int,int>>>> pq;
        vector<vector<int>> dist(m, vector<int>(n, -1));
        pq.push({grid[0][0], {0, 0}});
        // queue<pair<int, int>> q;
        //q.push({0, 0});
        dist[0][0] = grid[0][0];
        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};

        while(!pq.empty()){
            auto [c, temp] = pq.top();
            auto [i, j] = temp;
            pq.pop();
            if (c > dist[i][j]) continue;
            for(int k = 0; k < 4; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(nx >= 0 && ny >= 0 && nx < m && ny < n){
                    int nc = c + grid[nx][ny];
                    if(dist[nx][ny] == -1 || nc < dist[nx][ny]){
                        dist[nx][ny] = nc;
                        pq.push({nc, {nx, ny}});
                    }
                }
            }
        }


        /*
        <----- 0/1 BFS ----->

        while(!q.empty()){
            auto [i, j] = q.front();
            q.pop();
            for(int k = 0; k < 4; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(nx >= 0 && ny >= 0 && nx < m && ny < n){
                    int nc = dist[i][j] + grid[nx][ny];
                    if(dist[nx][ny] == -1 || nc < dist[nx][ny]){
                        dist[nx][ny] = nc;
                        q.push({nx, ny});
                    }
                }
            }
        } */
        return (dist[m - 1][n - 1] < health);
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        return helper(grid, health);
    }
};