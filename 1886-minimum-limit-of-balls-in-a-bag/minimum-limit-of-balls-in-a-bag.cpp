class Solution {
public:
    bool can(vector<int>& nums, int maxO, int maxC){
        long long ans = 0;
        for(auto n : nums){
            ans += (n - 1)/maxC;
        }
        return (ans <= (long long)maxO);
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());
        int ans = 0;
        while(l <= r){
            int mid = l + (r - l)/2;
            //cout << "mid: " << mid << endl;
            if(can(nums, maxOperations, mid)){
                ans = mid;
                //cout << "can at mid: " << mid << endl;
                r = mid - 1;
            }
            else{
                l = mid + 1;
                //cout << "cannot at mid: " << mid << endl;
            }
        }
        return ans;
    }
};