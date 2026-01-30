class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& ans, vector<bool>& visited, vector<int>& temp){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
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
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        vector<vector<int>> ans;
        vector<bool> visited(n, false);
        helper(nums, ans, visited, temp);
        return ans;
    }
};