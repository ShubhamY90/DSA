class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> diff(n, vector<int>(m, 0));
        vector<vector<int>> xCnt(n, vector<int>(m, 0));

        // values
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'X') {
                    diff[i][j] = 1;
                    xCnt[i][j] = 1;
                }
                else if (grid[i][j] == 'Y') {
                    diff[i][j] = -1;
                }
            }
        }

        // 2D prefix sums
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (i) {
                    diff[i][j] += diff[i-1][j];
                    xCnt[i][j] += xCnt[i-1][j];
                }
                if (j) {
                    diff[i][j] += diff[i][j-1];
                    xCnt[i][j] += xCnt[i][j-1];
                }
                if (i && j) {
                    diff[i][j] -= diff[i-1][j-1];
                    xCnt[i][j] -= xCnt[i-1][j-1];
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (diff[i][j] == 0 && xCnt[i][j] > 0)
                    ans++;
            }
        }

        return ans;
    }
};