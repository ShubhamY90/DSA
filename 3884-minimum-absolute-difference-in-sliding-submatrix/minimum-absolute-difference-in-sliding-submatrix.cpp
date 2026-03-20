class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1, 0));
        if(k <= 1) return ans;
        for(int i = 0; i < m - k + 1; i++){
            for(int j = 0; j < n - k + 1; j++){
                set<int> temp;
                for(int x = i; x < i + k; x++){
                    for(int y = j; y < j + k; y++){
                        temp.insert(grid[x][y]);
                    }
                }
                int mini = INT_MAX;
                auto it = temp.begin();
                auto prev = it;
                it++;
                for(; it != temp.end(); it++, prev++){
                    mini = min(mini, abs(*it - *prev));
                }
                if(mini == INT_MAX) mini = 0;
                ans[i][j] = mini;
            }
        }
        return ans;
    }
};