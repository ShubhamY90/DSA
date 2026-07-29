class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        int n = points.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for(int i = 0; i < n; i++){
            pq.push({((points[i][0]*points[i][0]) + (points[i][1]*points[i][1])), points[i][0], points[i][1]});
        }
        for(int i = 0; i < k; i++){
            ans.push_back({pq.top()[1], pq.top()[2]});
            pq.pop();
        }
        return ans;
    }
};