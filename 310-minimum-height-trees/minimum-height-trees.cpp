class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        if (n == 1) return {0};

        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);

        // Build adjacency list and count degree of every node.
        // degree[i] = number of neighbours currently connected to i.
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);

            degree[e[0]]++;
            degree[e[1]]++;
        }

        queue<int> q;

        // Initially all leaves (degree == 1) are the outermost layer.
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1)
                q.push(i);
        }

        // Number of nodes still remaining in the tree.
        int remaining = n;

        // Tree always has either 1 or 2 centres.
        // So keep removing outer layers until only <= 2 nodes remain.
        while (remaining > 2) {

            // Current leaves belong to the same layer.
            int sz = q.size();

            // These leaves are now removed from the tree.
            remaining -= sz;

            while (sz--) {

                int leaf = q.front();
                q.pop();

                // Removing a leaf only affects its neighbours.
                // Hence only neighbour's degree decreases.
                for (int ne : adj[leaf]) {

                    degree[ne]--;

                    // The moment neighbour's degree becomes 1,
                    // it has become a NEW leaf for the next round.
                    // We DO NOT wait for degree == 0 because
                    // it would already have been pushed once.
                    if (degree[ne] == 1)
                        q.push(ne);
                }
            }
        }

        // Queue now contains the last remaining 1 or 2 nodes,
        // which are exactly the centres of the tree.
        vector<int> ans;

        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};
// class Solution {
// public:
//     int dfs(vector<vector<int>>& adj, int i, vector<bool>& visited){
//         visited[i] = true;
//         int ans = -1;
//         for(auto ne : adj[i]){
//             if(!visited[ne]){
//                 int h = dfs(adj, ne, visited);
//                 ans = max(h, ans);
//             }
//         }
//         return ans + 1;
//     }
//     vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
//         vector<vector<int>> adj(n + 1);
//         for(auto e : edges){
//             adj[e[0]].push_back(e[1]);
//             adj[e[1]].push_back(e[0]);
//         }
//         vector<pair<int, int>> ans;
//         for(int i = 0; i < n; i++){
//             vector<bool> visited(n + 1, false);
//             int h = dfs(adj, i, visited);
//             ans.push_back({h, i});
//             //cout << "i: " << i << " -> height: " << h << endl;
//         }
//         sort(ans.begin(), ans.end());
//         int i = 0;
//         for(; i < n; i++){
//             //cout << ans[i].second << " " << ans[i].first << endl;
//             if(ans[i].first > ans[0].first) break;
//         }
//         vector<int> sol;
//         for(int j = 0; j < i; j++){
//             sol.push_back(ans[j].second);
//         }
//         return sol;
//     }
// };