class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        vector<int> pre(n + 1, 0);
        for(int i = 1; i <= n; i++){
            pre[i] = pre[i - 1] + nums[i - 1];
        }
        int ans = INT_MAX;
        for (int i = 0; i <= n; i++) {
            while (!q.empty() && pre[i] - pre[q.front()] >= k) {
                ans = min(ans, i - q.front());
                q.pop_front();
            }

            while (!q.empty() && pre[i] <= pre[q.back()]) {
                q.pop_back();
            }

            q.push_back(i);
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};