class Solution {
public:
    bool dfs(vector<vector<char>>& board, vector<vector<int>>& row, vector<vector<int>>& col, vector<vector<int>>& box, int i, int j) {
        if(i == 9) return true;
        if(j == 9) return dfs(board, row, col, box, i + 1, 0);

        if(board[i][j] != '.'){
            return dfs(board, row, col, box, i, j + 1);
        }

        for(int num = 1; num < 10; num++){
            if(row[i][num] || col[j][num] || box[(i/3)*3 + j/3][num]) continue;
            board[i][j] = num + '0';
            row[i][num] = 1;
            col[j][num] = 1;
            box[(i/3)*3 + j/3][num] = 1;
            if(dfs(board, row, col, box, i, j + 1)) return true;
            board[i][j] = '.';
            row[i][num] = col[j][num] = box[(i/3)*3 + j/3][num] = 0;
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        int n = 9;
        vector<vector<int>> row(9, vector<int>(10, 0));
        vector<vector<int>> col(9, vector<int>(10, 0));
        vector<vector<int>> box(9, vector<int>(10, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] != '.'){
                    row[i][board[i][j] - '0'] = 1;
                    col[j][board[i][j] - '0'] = 1;
                    box[(i/3)*3 + j/3][board[i][j] - '0'] = 1;
                }
            }
        }
        dfs(board, row, col, box, 0, 0);
        return;
    }
};