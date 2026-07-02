class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> m;
        int n = nums.size();
        vector<int> pre(n + 1, 0);
        m[0].push_back(-1);
        for(int i = 0; i < n; i++){
            pre[i + 1] = pre[i] + nums[i];
            m[pre[i + 1]].push_back(i);
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            int temp = pre[i] - k;
            //cout << "pre[i]: " << pre[i] << ", pre[i] - k: " << temp << endl;
            
            if(m.find(temp) != m.end()){
                //cout << "i: " << endl;
                cnt += lower_bound(m[temp].begin(), m[temp].end(), i - 1) - m[temp].begin();
            }
        }
        return cnt;
    }
};