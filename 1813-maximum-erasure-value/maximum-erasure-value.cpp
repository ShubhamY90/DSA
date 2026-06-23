class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        vector<int> pre(n + 1, 0);
        for(int i = 0; i < n; i++){
            pre[i + 1] = pre[i] + nums[i];
        }
        int repeat = 0;
        int j = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            m[nums[i]]++;
            if(m[nums[i]] > 1) repeat++;
            //cout << repeat << ", at i: " << i <<endl;
            while(repeat > 0){
                if(m[nums[j]] > 1){
                    m[nums[j]]--;
                    repeat--;
                }
                else{
                    m.erase(nums[j]);
                }
                j++;
            }
            
            ans = max(ans, pre[i + 1] - pre[j]);
            //cout << ans << endl;
        }
        return ans;
    }
};