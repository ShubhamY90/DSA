class Solution {
public:
    bool helper(vector<int>& nums, int s1, int s2, int i, int j, bool turnP1){
        if(i > j) return (s1 >= s2);
        bool ans;
        if(turnP1){
            bool temp1 = helper(nums, s1 + nums[i], s2, i + 1, j, false);
            bool temp2 = helper(nums, s1 + nums[j], s2, i, j - 1, false);
            ans = temp1 || temp2;
        }
        else{
            bool temp1 = helper(nums, s1, s2 + nums[i], i + 1, j, true);
            bool temp2 = helper(nums, s1, s2 + nums[j], i, j - 1, true);
            ans = temp1 && temp2;
        }
        return ans;
    }
    bool predictTheWinner(vector<int>& nums) {
        return helper(nums, 0, 0, 0, nums.size() - 1, true);
    }
};