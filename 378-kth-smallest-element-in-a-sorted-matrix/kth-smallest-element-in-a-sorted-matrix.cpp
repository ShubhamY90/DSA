class Solution {
public:
typedef pair<int, pair<int, int>> pp;
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        for(int i = 0; i < n; i++){
            pq.push({matrix[i][0], {i, 0}});
        }
        while(--k){
            auto [temp1, temp2] = pq.top();
            auto [i, j] = temp2;
            pq.pop();

            if(j < n - 1){
                if(temp1 <= matrix[i][j + 1]){
                    pq.push({matrix[i][j + 1], {i, j + 1}});
                }
            }
        }
        return pq.top().first;
    }
};