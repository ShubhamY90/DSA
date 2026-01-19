class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        long long n = nums.size();
        vector<long long> pre(n, 0);
        vector<long long> suf(n, LLONG_MAX);
        pre[0] = nums[0];
        for(long long i = 1; i < n; i++){
            pre[i] = pre[i - 1] + (long long)nums[i];
        }
        suf[n - 1] = nums[n - 1];
        for(long long i = n - 2; i >= 0; i--){
            suf[i] = min(suf[i + 1], (long long)nums[i + 1]);
        }
        long long ans = LLONG_MIN;
        for(long long i = 0; i < n - 1; i++){
            //cout << "pre[" << i << "] : " << pre[i] << ", suf[" << i << "] : " << suf[i] << endl;
            ans = max(ans, pre[i] - suf[i]);
        }
        return ans;
    }
};