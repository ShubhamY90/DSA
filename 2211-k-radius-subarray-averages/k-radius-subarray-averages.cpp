class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        //if(k == 0) k = 1;
        int n = nums.size();
        if((2*k) + 1 > n){
            vector<int> temp(n, -1);
            return temp;
        }
        vector<int> ans(n, -1);
        long long sum = 0;
        for(int i = 0; i < ((2*k) + 1); i++){
            sum += nums[i];
        }
        //cout << "from: " << 0 << " to: " << ((2*k) + 1) << " sum: " << sum << endl;
        ans[k] = ((int)(sum/(long long)((k*2) + 1)));
        for(int i = k + 1; i < n - k; i++){
            sum -= nums[i - k - 1];
            sum += nums[i + k];
            //cout << "from: " << i - k << " to: " << i + k << " sum: " << sum << endl;
            ans[i] = ((int)(sum/(long long)((k*2) + 1)));
        }
        
        return ans;
    }
};