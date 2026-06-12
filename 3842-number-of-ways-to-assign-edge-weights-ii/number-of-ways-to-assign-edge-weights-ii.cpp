class Solution {
public:
    int MOD = 1e9+7;
    //lca calculated
    int lca(int u, int v, vector<int>& depth, vector<vector<int>>& up){
        if(depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];

        for(int j = 20 - 1; j >= 0; j--){
            if(diff & (1 << j))
                u = up[u][j];
        }

        if(u == v)
            return u;

        for(int j = 20 - 1; j >= 0; j--){
            if(up[u][j] != up[v][j])
            {
                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0];
    }

    long long modPow(long long base, long long exp, int mod) {
        long long res = 1;
        long long cur = base % mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * cur) % mod;
            cur = (cur * cur) % mod;
            exp = exp / 2;
        }
        return res;
    }


    //up binary table calculated
    void bfs(vector<vector<int>>& g, vector<int>& depth, vector<int>& parent, vector<vector<int>>& up, int& n){
        queue<int> q;
        q.push(1);
        vector<bool> vis(n + 1, false);
        vis[1] = true;
        parent[1] = 1;
        depth[1] = 0;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            for(auto to : g[temp]){
                if(vis[to]) continue;
                vis[to] = true;
                q.push(to);
                parent[to] = temp;
                depth[to] = 1 + depth[temp];
            }
        }
        // for(int i = 1; i <= n; i++){
        //     cout << "Node: " << i << " Parent: " << parent[i] << " Depth: " << depth[i] << endl;
        // }
        for(int i = 1; i <= n; i++){
            up[i][0] = parent[i];
        }
        for(int i = 1; i < 20; i++){
            for(int j = 1; j <= n; j++){
                up[j][i] = up[up[j][i - 1]][i - 1];
            }
        }
        return;
    }
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        vector<vector<int>> g(n + 1);
        for(auto e : edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<vector<int>> up(n + 1, vector<int>(20, 1));
        vector<int> parent(n + 1);
        vector<int> depth(n + 1);

        bfs(g, depth, parent, up, n);

        vector<int> ans;

        for(auto q : queries){
            int from = q[0];
            int to = q[1];
            int common = lca(from, to, depth, up);
            int final = depth[from] + depth[to] - 2*depth[common];
            if(final == 0) ans.push_back(0);
            else ans.push_back((int)modPow(2, final - 1, MOD));
        }
        return ans;
    }
};