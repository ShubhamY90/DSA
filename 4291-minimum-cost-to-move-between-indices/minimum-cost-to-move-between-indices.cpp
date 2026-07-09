class Solution {
public:
    vector<int> forward(vector<int>& nums, vector<int>& closest){
        int n = nums.size();
        vector<int> ans(n, 0);
        ans[0] = 0;
        for(int x = 0; x < n - 1; x++){
            if(closest[x] == x + 1){
                ans[x + 1] = ans[x] + 1;
            }
            else{
                ans[x + 1] = ans[x] + abs(nums[x + 1] - nums[x]);
            }
        }
        return ans;
    }
    vector<int> backward(vector<int>& nums, vector<int>& closest){
        int n = nums.size();
        vector<int> ans(n, 0);
        ans[n - 1] = 0;
        for(int x = n - 1; x > 0; x--){
            if(closest[x] == x - 1){
                ans[x - 1] = ans[x] + 1;
            }
            else{
                ans[x - 1] = ans[x] + abs(nums[x - 1] - nums[x]);
            }
        }
        return ans;
    }
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> closest(n);
        closest[0] = 1;
        for(int i = 1; i < n - 1; i++){
            if(abs(nums[i + 1] - nums[i]) < abs(nums[i - 1] - nums[i])){
                closest[i] = i + 1;
            }
            else{
                closest[i] = i - 1;
            }
        }
        closest[n - 1] = n - 2;

        vector<int> forw = forward(nums, closest);
        vector<int> back = backward(nums, closest);

        vector<int> ans;

        for(auto q : queries){
            int i = q[0];
            int j = q[1];
            if(i == j){
                ans.push_back(0);
            }
            else if(i < j){
                int currCost = forw[j] - forw[i];
                ans.push_back(currCost);
            }
            else{
                int currCost = back[j] - back[i];
                ans.push_back(currCost);
            }
        }
        return ans;
    }
};