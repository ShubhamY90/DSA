class DSU{
public:
    vector<int> sz, parent;
    DSU(int n){
        sz.resize(n + 1, 1);
        parent.resize(n + 1);
        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }
    }

    int find(int n){
        if(parent[n] == n) return n;
        return parent[n] = find(parent[n]);
    }

    int size(int n){
        return sz[n];
    }

    bool unite(int a, int b){
        int pa = find(a);
        int pb = find(b);

        if(pa == pb) return false;

        if(sz[pa] < sz[pb]){
            swap(pa, pb);
        }
        parent[pb] = pa;
        sz[pa] += sz[pb];
        return true;
    }
};
class Solution {
public:
    vector<int> primeFactors(int n) {
        vector<int> factors;

        for (int p = 2; p * p <= n; p++) {
            if (n % p == 0) {
                factors.push_back(p);

                while (n % p == 0)
                    n /= p;
            }
        }

        if (n > 1)
            factors.push_back(n);

        return factors;
    }

    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        DSU dsu(1e5);
        for(int i = 0; i < n; i++){
            vector<int> temp = primeFactors(nums[i]);
            for(auto& j : temp){
                dsu.unite(j, nums[i]);
            }
        }

        unordered_map<int,int> cnt;

        for(int x : nums){
            cnt[dsu.find(x)]++;
        }

        int ans = 0;

        for(auto &[root, c] : cnt){
            ans = max(ans, c);
        }
        return ans;
    }
};