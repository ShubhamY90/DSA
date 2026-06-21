class Solution {
public:
    void dfs(int src,
             int curr,
             vector<vector<int>>& adj,
             vector<vector<int>>& ans,
             vector<bool>& visited) {

        visited[curr] = true;

        for (int nxt : adj[curr]) {
            if (!visited[nxt]) {
                ans[nxt].push_back(src);
                dfs(src, nxt, adj, ans, visited);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }

        vector<vector<int>> ans(n);

        for (int src = 0; src < n; src++) {
            vector<bool> visited(n, false);
            dfs(src, src, adj, ans, visited);
        }

        return ans;
    }
};