class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        int minE = INT_MAX;
        int maxE = INT_MIN;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                minE = min(minE, matrix[i][j]);
                maxE = max(maxE, matrix[i][j]);
            }
        }
        int ans = -1;
        while(minE <= maxE){
            int mid = minE + (maxE - minE)/2;
            if(count(matrix, mid, m, n) >= k){
                ans = mid;
                maxE = mid - 1;
            }
            else minE = mid + 1;
        }
        return ans;
    }
    int count(vector<vector<int>>& matrix, int num, int m, int n){
        int cnt = 0;
        for(int i = 0; i < m; i++){
            if(matrix[i][n - 1] > num){
                int j = n - 1;
                int temp = n;
                while(j >= 0 && matrix[i][j] > num){
                    j--;
                    temp--;
                }
                cnt += temp;
                //break;
            }
            else cnt += n;
        }
        return cnt;
    }
};