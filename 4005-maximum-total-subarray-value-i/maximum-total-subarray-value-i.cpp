class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int maxE = INT_MIN;
        int minE = INT_MAX;
        for(int i = 0; i < n; i++){
            maxE = max(maxE, nums[i]);
            minE = min(minE, nums[i]);
        }
        long long ans = (long long)k * ((long long)maxE - (long long)minE);
        return ans;
    }
};