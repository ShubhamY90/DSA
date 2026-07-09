class DSU{
public:
    vector<int> parent;
    DSU(int n){
        parent.resize(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }
    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    bool unite(int u, int v){
        int pu = find(u);
        int pv = find(v);

        if(pu == pv) return false;

        parent[pv] = pu;
        return true;
    }
};

class Solution {
public:
    vector<bool> helper(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries){
        DSU dsu(n);
        for(int i = 1; i < n; i++){
            if(abs(nums[i] - nums[i - 1]) <= maxDiff){
                dsu.unite(i, i - 1);
            }
        }
        vector<bool> ans;
        for(auto q : queries){
            if(dsu.find(q[0]) == dsu.find(q[1])) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        //using DSU for finding connected components
        return helper(n, nums, maxDiff, queries);

        //just checking where does the condition of diff breaks 
        //same approach as DSU just simpler
        vector<pair<int, int>> arr(n);
        arr[0].first = nums[0];
        arr[0].second = 0;
        for(int i = 1; i < n; i++){
            arr[i].first = nums[i];
            if(abs(arr[i].first - arr[i - 1].first) <= maxDiff){
                arr[i].second = arr[i - 1].second;
            }
            else{
                arr[i].second = i;
            }
        }
        
        vector<bool> ans;
        for(auto q : queries){
            if(arr[q[0]].second == arr[q[1]].second) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};