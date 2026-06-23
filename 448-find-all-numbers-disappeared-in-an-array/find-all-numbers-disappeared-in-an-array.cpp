class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i < n){
            if(i + 1 != nums[i] && nums[i] != nums[nums[i] - 1]){
                swap(nums[i], nums[nums[i] - 1]);
            }
            else{
                i++;
            }
        }
        vector<int> ans;
        for(int j = 0; j < n; j++){
            if(nums[j] != j + 1) ans.push_back(j+1);
        }
        return ans;
    }
};