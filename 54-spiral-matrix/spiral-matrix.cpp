class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int t = 0;
        int b = n - 1;
        int l = 0;
        int r = m - 1;
        vector<int> ans;
        //if(t <= b || l <= r) break;
        while(t <= b || l <= r){
            if(t > b || l > r) break;
            //left -> right
            for(int j = l; j <= r; j++){
                ans.push_back(matrix[t][j]);
            }
            cout << t << "," << l << " -> " << t << "," << r << endl;
            t++;
            if(t > b || l > r) break;
            //top -> bottom
            for(int i = t; i <= b; i++){
                ans.push_back(matrix[i][r]);
            }
            cout << t << "," << r << " -> " << b << "," << r << endl;
            r--;
            if(t > b || l > r) break;
            //right -> left;
            for(int j = r; j >= l; j--){
                ans.push_back(matrix[b][j]);
            }
            cout << b << "," << r << " -> " << b << "," << l << endl;
            b--;
            if(t > b || l > r) break;
            //bottom -> top
            for(int i = b; i >= t; i--){
                ans.push_back(matrix[i][l]);
            }
            cout << b << "," << l << " -> " << t << "," << l << endl;
            l++;
        }
        return ans;
    }
};