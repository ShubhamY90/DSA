class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n, -1);
        vector<int> maxE(n, -1);
        maxE[0] = nums[0];
        pref[0] = nums[0];
        for(int i = 1; i < n; i++){
            maxE[i] = max(maxE[i - 1], nums[i]);
            pref[i] = gcd(maxE[i], nums[i]);
        }
        sort(pref.begin(), pref.end());
        long long ans = 0;
        int l = 0;
        int r = n - 1;
        while(l < r){
            ans += gcd(pref[l], pref[r]);
            l++;
            r--;
        }
        return ans;
    }
};