class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i - 1] + 1 == nums[i]){
                //cout << nums[i] << endl;
                sum += nums[i];
            }
            else break;
        }
        //cout << sum << endl;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }
        int last = accumulate(nums.begin(), nums.end(), 0);
        for(int i = sum; i <= last + 1; i++){
            if(!mp.count(i)) return i;
        }
        return -1;
    }
};