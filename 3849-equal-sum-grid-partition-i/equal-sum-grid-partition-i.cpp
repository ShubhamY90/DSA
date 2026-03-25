class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<long long> vert(m);
        vector<long long> hori(n);
        for(int i = 0; i < n; i++){
            long long temp = 0;
            for(int j = 0; j < m; j++){
                temp += grid[i][j];
            }
            if(i == 0) hori[0] = temp;
            else hori[i] = hori[i - 1] + temp;
        }
        for(int i = 0; i < m; i++){
            long long temp = 0;
            for(int j = 0; j < n; j++){
                temp += grid[j][i];
            }
            if(i == 0) vert[0] = temp;
            else vert[i] = vert[i - 1] + temp;
        }
        for(int i = 0; i < n - 1; i++){
            if(hori[i] == hori[n - 1] - hori[i]) return true;
        }
        for(int i = 0; i < m - 1; i++){
            if(vert[i] == vert[m - 1] - vert[i]) return true;
        }
        return false;
    }
};