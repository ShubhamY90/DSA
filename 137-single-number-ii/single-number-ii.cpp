class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bits(32, 0);
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 32; j++){
                bits[j] += (nums[i] >> j) & 1;
            }
        }
        for(int i = 0; i < 32; i++){
            bits[i] = bits[i] % 3;
        }
        int ans = 0;
        for(int i = 0; i < 32; i++){
            if(bits[i]) ans |= (1 << i);
        }
        return ans;
    }
};