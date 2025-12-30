class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& state) {
        if(state[node] == 1) return false; // found a cycle
        if(state[node] == 2) return true;  // already safe
        if(state[node] == 3) return false; // already unsafe

        state[node] = 1; // mark as visiting
        for(int nei : graph[node]) {
            if(!dfs(nei, graph, state)) {
                state[node] = 3; // mark as unsafe
                return false;
            }
        }
        state[node] = 2; // mark as safe
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n, 0); // all nodes unvisited initially
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(dfs(i, graph, state)) {
                ans.push_back(i);
            }
        }
        return ans;
    }

};