class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        if(nums.size() < 3){
            return nums.size();
        }
        int ans = 0;
        for(int i = nums.size(); i > 0; i /= 2){
            ans++;
        }
        return pow(2, ans);
    }
};