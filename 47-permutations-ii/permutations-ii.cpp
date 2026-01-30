class Solution {
public:
    void helper(vector<int>& nums, set<vector<int>>& ans, vector<bool>& visited, vector<int>& temp){
        if(temp.size() == nums.size()){
            ans.insert(temp);
            //temp.clear();
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(visited[i]) continue;
            visited[i] = true;
            temp.push_back(nums[i]);
            helper(nums, ans, visited, temp);
            temp.pop_back();
            visited[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        set<vector<int>> ans;
        vector<bool> visited(n, false);
        helper(nums, ans, visited, temp);
        vector<vector<int>> sol;
        for(auto s : ans){
            sol.push_back(s);
        }
        return sol;
    }
};