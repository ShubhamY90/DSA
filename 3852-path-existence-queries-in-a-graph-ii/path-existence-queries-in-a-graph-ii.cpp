class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& arr, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> nums(n);
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            nums[i] = {arr[i], i};
        }

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++){
            mp[nums[i].second] = i;
        }

        vector<int> to_max(n);
        int j = 0;
        for(int i = 0; i < n; i++){
            if(j < i) j = i;
            while(j + 1 < n &&
                  nums[j + 1].first - nums[j].first <= maxDiff &&
                  nums[j + 1].first - nums[i].first <= maxDiff){
                j++;
            }
            to_max[i] = j;
        }

        // Binary lifting table
        const int LOG = 18;
        vector<vector<int>> up(n, vector<int>(LOG));

        for(int i = 0; i < n; i++)
            up[i][0] = to_max[i];

        for(int k = 1; k < LOG; k++){
            for(int i = 0; i < n; i++){
                up[i][k] = up[up[i][k - 1]][k - 1];
            }
        }

        vector<int> ans;

        for(auto &q : queries){
            int i = mp[q[0]];
            int j = mp[q[1]];

            if(i > j) swap(i, j);

            if(i == j){
                ans.push_back(0);
                continue;
            }

            int curr = i;
            int steps = 0;

            for(int k = LOG - 1; k >= 0; k--){
                if(up[curr][k] < j){
                    curr = up[curr][k];
                    steps += (1 << k);
                }
            }

            if(up[curr][0] >= j)
                ans.push_back(steps + 1);
            else
                ans.push_back(-1);
        }

        return ans;
    }
};