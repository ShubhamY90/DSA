class DSU{
    vector<int> parent, size;
public:

    DSU(int n){
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }
    int find(int x){
        if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void unionBS(int pu, int pv){
        int u = find(pu);
        int v = find(pv);
        if(u == v){
            return;
        }
        // if(size[u] > size[v]){
        //     parent[v] = u;
        //     size[u] += size[v];
        // }
        if(size[v] > size[u]){
            parent[u] = v;
            size[v] += size[u];
        }
        else{
            parent[v] = u;
            size[u] += size[v];
        }
        return;
    }

};

class Solution {
public:

    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int i){
        visited[i] = true;
        for(auto g : graph[i]){
            if(!visited[g]){
                dfs(graph, visited, g);
            }
        }
        return;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1){
            return -1;
        }
        DSU d(n);
        for(int i = 0; i < connections.size(); i++){
            d.unionBS(connections[i][0], connections[i][1]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            //find(i);
            if(d.find(i) == i){
                ans++;
            }
        }
        return ans - 1;
        // if(connections.size() < n - 1){
        //     return -1;
        // }
        // vector<vector<int>> graph(n);
        // for(int i = 0; i < connections.size(); i++){
        //     graph[connections[i][0]].push_back(connections[i][1]);
        //     graph[connections[i][1]].push_back(connections[i][0]);
        // }
        // vector<bool> visited(n, false);
        // int sol = 0;
        // for(int i = 0; i < graph.size(); i++){
        //     if(!visited[i]){
        //         sol++;
        //         dfs(graph, visited, i);
        //     }
        // }
        // return sol - 1;
    }
};