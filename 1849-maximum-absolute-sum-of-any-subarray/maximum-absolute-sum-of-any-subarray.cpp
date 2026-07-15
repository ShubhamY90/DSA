class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int minSum = INT_MAX;
        int maxSum = INT_MIN;
        int curr = 0;
        int sMax = 0;
        int sMin = 0;
        for(int i = 0; i < n; i++){
            if(curr < 0){
                curr = 0;
                sMax = i;
            }
            curr += nums[i];
            maxSum = max(maxSum, curr);
        }
        curr = 0;
        for(int i = 0; i < n; i++){
            if(curr > 0){
                curr = 0;
                sMin = i;
            }
            curr += nums[i];
            minSum = min(minSum, curr);
        }
        // cout << "sMin: " << sMin << " minSum: " << minSum << endl;
        // cout << "sMax: " << sMax << " maxSum: " << maxSum << endl;
        return max(abs(minSum), abs(maxSum));
    }
};