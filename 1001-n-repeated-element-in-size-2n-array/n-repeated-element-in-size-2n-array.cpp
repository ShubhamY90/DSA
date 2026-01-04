class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        
        unordered_map<int, int> map;
        for(auto i : nums){
            map[i]++;
        }
        for(auto it : map){
            if(it.second ==  nums.size()/2) return it.first;
        }
        return -1;
    }
};