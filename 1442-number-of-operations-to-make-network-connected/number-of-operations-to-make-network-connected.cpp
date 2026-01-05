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
        vector<vector<int>> graph(n);
        for(int i = 0; i < connections.size(); i++){
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }
        vector<bool> visited(n, false);
        int sol = 0;
        for(int i = 0; i < graph.size(); i++){
            if(!visited[i]){
                sol++;
                dfs(graph, visited, i);
            }
        }
        return sol - 1;
    }
};