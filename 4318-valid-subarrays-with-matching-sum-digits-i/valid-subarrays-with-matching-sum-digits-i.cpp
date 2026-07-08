class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        vector<long long> pre(n + 1, 0);
        for(int i = 0; i < n; i++){
            pre[i + 1] = pre[i] + nums[i];
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                long long temp = pre[j + 1] - pre[i];
                int first = temp%10;
                int last = 0;
                while(temp){
                    last = temp%10;
                    temp /= 10;
                }
                if(first == x && last == x) ans++;
            }
        }
        return ans;
    }
};