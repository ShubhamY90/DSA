class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> left;
        vector<int> right;
        for(int i = 0; i < n; i++){
            if(nums[i] < pivot) left.push_back(nums[i]);
            else if(nums[i] > pivot) right.push_back(nums[i]);
        }
        for(int i = 0; i < left.size(); i++){
            nums[i] = left[i];
        }
        for(int i = left.size(); i < (n - right.size()); i++){
            nums[i] = pivot;
        }
        for(int i = (n - right.size()); i < n; i++){
            nums[i] = right[i - (n - right.size())];
        }
        return nums;
    }
};