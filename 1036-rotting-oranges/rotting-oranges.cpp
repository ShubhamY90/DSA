class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        bool xyz = true;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    xyz = false;
                    break;
                }
            }
        }
        if(xyz) return 0;
        int ans = 0;
        while(!q.empty()){
            vector<pair<int, int>> temp;
            while(!q.empty()){
                 temp.push_back(q.front());
                 q.pop();
            }
             for(int t = 0; t < temp.size(); t++){
                int i = temp[t].first;
                int j = temp[t].second;
                //q.pop();
                if(i > 0 && grid[i - 1][j] == 1){
                    grid[i - 1][j] = 2;
                    q.push({i-1, j});
                }
                if(j > 0 && grid[i][j - 1] == 1){
                    grid[i][j - 1] = 2;
                    q.push({i, j-1});
                }
                if(j < n - 1 && grid[i][j + 1] == 1){
                    grid[i][j + 1] = 2;
                    q.push({i, j + 1});
                }
                if(i < m - 1 && grid[i + 1][j] == 1){
                    grid[i + 1][j] = 2;
                    q.push({i + 1, j});
                }
            }
            ans++;
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return ans - 1;
    }
};