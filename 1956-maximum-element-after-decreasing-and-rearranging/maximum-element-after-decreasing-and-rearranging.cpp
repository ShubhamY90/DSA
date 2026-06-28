class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return 1;
        sort(arr.begin(), arr.end());
        int prev = min(1, arr[0]);
        int ans = prev;
        for(int i = 1; i < n; i++){
            cout << "arr[i]: " << arr[i] << ", prev: " << prev << ", ans: " << ans << endl;
            ans = max(min(arr[i], prev + 1), ans);
            prev = min(arr[i], prev + 1);
        }
        return ans;
    }
};