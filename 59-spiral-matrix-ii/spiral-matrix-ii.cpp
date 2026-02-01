class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int t = 0;
        int b = n - 1;
        int l = 0;
        int r = n - 1;
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int num = 1;
        while(t <= b || l <= r){
            if(t > b || l > r) break;
            //left -> right
            for(int j = l; j <= r; j++){
                ans[t][j] = num;
                num++;
            }
            t++;
            if(t > b || l > r) break;
            //top -> bottom
            for(int i = t; i <= b; i++){
                ans[i][r] = num;
                num++;
            }
            r--;
            if(t > b || l > r) break;
            //right -> left;
            for(int j = r; j >= l; j--){
                ans[b][j] = num;
                num++;
            }
            b--;
            if(t > b || l > r) break;
            //bottom -> top
            for(int i = b; i >= t; i--){
                ans[i][l] = num;
                num++;
            }
            l++;
        }
        return ans;
    }
};