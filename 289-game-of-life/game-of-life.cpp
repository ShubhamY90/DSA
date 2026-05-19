class Solution {
public:
    void gameOfLife(vector<vector<int>>& temp) {
        vector<vector<int>> board = temp;
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int curr = temp[i][j];
                vector<int> l = {-1, -1, -1, 0, 0, 1, 1, 1};
                vector<int> r = {-1, 0, 1, -1, 1, -1, 0, 1};
                int count = 0;
                for(int k = 0; k < 8; k++){
                    int t1 = i + l[k];
                    int t2 = j + r[k];
                    if(t1 >= 0 && t1 < m && t2 >= 0 && t2 < n){
                        if(temp[t1][t2]) count++;
                    }
                }
                cout << i << ", " << j << " -> " << count << endl;
                if(count == 3) board[i][j] = 1;
                if(count < 2 || count > 3) board[i][j] = 0;
            }
        }
        temp = board;
        return;
    }
};