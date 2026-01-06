class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 0;
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            int j = nums[i] + i;
            ans++;
            if(j >= n - 1) break;
            int temp = j + nums[j];
            int l = j;
            while(j > i){
                if(j + nums[j] > temp){
                    temp = nums[j] + j;
                    l = j;
                }
                j--;
            }
            
            i = l - 1;
        }
        return ans;
    }
};