class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int oc = 0;
        int zc = 0;
        int best = 0;
        mp[0] = -1;
        for(int i = 0; i < n; i++){
            if(nums[i] == 1) oc++;
            else zc++;

            int diff = oc - zc;
            if(mp.find(diff) != mp.end()){
                best = max(best, i - mp[diff]);
            }
            else{
                mp[diff] = i;
            }
            
        }
        return best;
    }
};