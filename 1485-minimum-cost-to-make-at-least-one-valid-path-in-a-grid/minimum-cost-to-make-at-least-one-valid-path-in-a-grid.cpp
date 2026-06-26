class Solution {
public:
    int minCost(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        // !! saw hints !!
        // using grid as graph with the direction edge weight 0 and 1 otherwise 
        // doing dijkstra to count the min changes required
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        dist[0][0] = 0;

        while(!pq.empty()){
            auto [cost, p] = pq.top();
            auto [i, j] = p;
            pq.pop();

            if(cost > dist[i][j]) continue;

            // Right
            if(j + 1 < n){
                int newCost = cost + (grid[i][j] != 1);
                if(newCost < dist[i][j + 1]){
                    dist[i][j + 1] = newCost;
                    pq.push({newCost, {i, j + 1}});
                }
            }

            // Left
            if(j - 1 >= 0){
                int newCost = cost + (grid[i][j] != 2);
                if(newCost < dist[i][j - 1]){
                    dist[i][j - 1] = newCost;
                    pq.push({newCost, {i, j - 1}});
                }
            }

            // Down
            if(i + 1 < m){
                int newCost = cost + (grid[i][j] != 3);
                if(newCost < dist[i + 1][j]){
                    dist[i + 1][j] = newCost;
                    pq.push({newCost, {i + 1, j}});
                }
            }

            // Up
            if(i - 1 >= 0){
                int newCost = cost + (grid[i][j] != 4);
                if(newCost < dist[i - 1][j]){
                    dist[i - 1][j] = newCost;
                    pq.push({newCost, {i - 1, j}});
                }
            }
        }
        return dist[m - 1][n - 1];
    }
};