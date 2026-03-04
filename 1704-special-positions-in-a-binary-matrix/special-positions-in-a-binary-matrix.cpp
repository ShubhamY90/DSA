class Solution {
public:
    bool check(vector<vector<int>>& mat, int i, int j){
        for(int x = 0; x < mat[0].size(); x++){
            if(x == j) continue;
            if(mat[i][x] == 1) return false;
        }
        for(int x = 0; x < mat.size(); x++){
            if(x == i) continue;
            if(mat[x][j] == 1) return false;
        }
        return true;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0;
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                if(mat[i][j] == 1){
                    if(check(mat, i, j)){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};