class Solution {
public:
    void rotate90(vector<vector<int>>& mat){
        for(int i = 0; i < mat.size(); i++){
            for(int j = i; j < mat.size(); j++){
                swap(mat[i][j], mat[j][i]);
            }
        }
        for(int i = 0; i < mat.size(); i++){
            reverse(mat[i].begin(), mat[i].end());
        }
    }

    void print(const vector<vector<int>>& matrix) {
        cout << "{ ";
        for (auto row : matrix) {
            for (auto val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
        cout << " }" << endl;
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat == target) return true;
        //print(mat);
        for(int i = 0; i < 3; i++){
            rotate90(mat);
            //print(mat);
            if(mat == target) return true;
        }
        return false;
    }
};