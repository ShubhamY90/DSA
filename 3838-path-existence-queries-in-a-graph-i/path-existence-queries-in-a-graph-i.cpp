class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> arr(n);
        arr[0].first = nums[0];
        arr[0].second = 0;
        for(int i = 1; i < n; i++){
            arr[i].first = nums[i];
            if(abs(arr[i].first - arr[i - 1].first) <= maxDiff){
                arr[i].second = arr[i - 1].second;
            }
            else{
                arr[i].second = i;
            }
        }
        
        vector<bool> ans;
        for(auto q : queries){
            if(arr[q[0]].second == arr[q[1]].second) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};