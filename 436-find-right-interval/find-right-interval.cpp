class Solution {
public:
    int bs(vector<vector<int>>& intervals, int target){
        int l = 0;
        int r = intervals.size() - 1;
        int ans = -1;
        while(l <= r){
            int mid = l + (r - l) / 2;

            if(intervals[mid][0] >= target){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        if(ans == -1) return -1;
        return intervals[ans][2];
    }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        for(int i = 0; i < n; i++){
            intervals[i].push_back(i);
        }
        sort(intervals.begin(), intervals.end());
        vector<int> ans(n, -1);
        for(int i = 0; i < n; i++){
            ans[intervals[i][2]] = (bs(intervals, intervals[i][1]));
        }
        return ans;
    }
};