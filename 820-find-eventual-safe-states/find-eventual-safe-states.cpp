class Solution {
public:
    void dfs(vector<vector<int>>& graph, int i, vector<int>& visited, bool& found){
        if(found){
            return;
        }
        visited[i] = 1;
        for(auto l : graph[i]){
            if(visited[l] == 1){
                found = true;
                return;
            }
            if(visited[l] == 0){
                dfs(graph, l, visited, found);
            }
        }
        visited[i] = 2;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans;
        
        for(int i = 0; i < n; i++){
            vector<int> visited(n);
            //if(visited[i] == 0){
                bool found  = false;
                dfs(graph, i, visited, found);
                if(!found){
                    ans.push_back(i);
                }
            //}
        }
        return ans;
    }
};