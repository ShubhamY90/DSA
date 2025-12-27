class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<int>& visit, int n, bool& found, int i){
        visit[i] = 1;
        
        for(int l : graph[i]){
            if(visit[l] == 0){
                dfs(graph, visit, n, found, l);
            }
            if(visit[l] == 1){
                found = true;
                return;
            }
        }
        visit[i] = 2;
        
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> graph(numCourses);
        for(auto &p : prerequisites){
            graph[p[1]].push_back(p[0]);
        }
        vector<int> visit(n, 0);
        for(int i = 0; i < n; i++){
            if(!visit[i]){
                bool found = false;
                dfs(graph, visit, n, found, i);
                if(found){
                    return false;
                }
            }
        }
        return true;
    }
};