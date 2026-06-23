class Solution {
public:
    int search(vector<int>& nums, int t, int l, int r){
        int i = l;
        int j = r;
        while(i <= j){
            int mid = i + (j - i)/2;
            if(nums[mid] == t) return mid;
            else if(nums[mid] > t){
                j = mid - 1;
            }
            else{
                i = mid + 1;
            }
        }
        return -1;
    }
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int ans = INT_MAX;
        vector<int> suf(n + 1, 0);
        vector<int> pre(n + 1, 0);
        pre[0] = 0;
        suf[n] = 0;
        for(int i = 1; i <= n; i++){
            pre[i] += pre[i - 1] + nums[i - 1];
        }
        for(int i = n - 1; i >= 0; i--){
            suf[i] += suf[i + 1] + nums[i];
        }
        // cout << "prefix array: ";
        // for(int i = 0; i <= n; i++){
        //     cout << pre[i] << ", ";
        // }
        // cout << endl;
        // cout << "suffix array : ";
        // for(int i = 0; i <= n; i++){
        //     cout << suf[i] << ", ";
        // }
        // cout << endl;
    
        for(int i = n; i >= 0 && suf[i] <= x; i--){
            int to = x - suf[i];
            int temp = search(pre, to, 0, i);
            //cout << 0 << " to " << i << endl;
            //cout << "in for loop finding x - pre[i]: " << x - suf[i] << ", index: " << temp << endl;
            if(temp != -1) ans = min(ans, (n - i + temp));
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};