class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> grid(n, (vector<int>(n, INT_MAX)));
        for(auto e : edges){
            grid[e[0]][e[1]] = e[2];
            grid[e[1]][e[0]] = e[2];
        }

        for(int i = 0; i < n; i++){
            grid[i][i] = 0;
        }

        for(int via = 0; via < n; via++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(grid[i][via] != INT_MAX && grid[via][j] != INT_MAX){
                        grid[i][j] = min(grid[i][j], grid[i][via] + grid[via][j]);
                    }
                }
            }
        }

        int minE = INT_MAX;
        int minV = INT_MAX;
        for(int i = n - 1; i >= 0; i--){
            int currE = i;
            int currV = 0;
            for(int j = 0; j < n; j++){
                if(grid[i][j] <= distanceThreshold) currV++;
            }
            if(currV < minV){
                minE = currE;
                minV = currV;
            }
        }
        return minE;
    }
};