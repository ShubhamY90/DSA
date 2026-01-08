class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        //vector<vector<int>> res;
        int ans = 0;
        //res.push_back(intervals[0]);
        int prev = intervals[0][1];
        // for(int i = 0; i < n; i++){
        //     cout << "[" << intervals[i][0] << "," << intervals[i][1] << "],";
        // }
        // cout << endl;
        for(int i = 1; i < n; i++){
            //cout << prev << endl;
            if(prev > intervals[i][0]){
                prev = min(prev, intervals[i][1]);
                //res.back()[1] = max(res.back()[1], intervals[i][1]);
                ans++;
                //i++;
            }
            else{
                prev = intervals[i][1];
            }
        }
        return ans;
    }
};