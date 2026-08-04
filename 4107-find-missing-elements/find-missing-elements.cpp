class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int low = *lower_bound(nums.begin(), nums.end(), 1);
        int max = *max_element(nums.begin(), nums.end());
        vector<int> ans;
        for(int i = low + 1; i < max; i++){
            auto it = lower_bound(nums.begin(), nums.end(), i);

            if (it == nums.end() || *it != i) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};