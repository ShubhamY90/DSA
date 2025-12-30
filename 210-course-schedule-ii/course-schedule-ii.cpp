class Solution {
public:
    void dfs(vector<vector<int>>& graph, int i, vector<int>& visited, bool& found, vector<int>& ans){
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
                dfs(graph, l, visited, found, ans);
            }
        }
        visited[i] = 2;
        ans.push_back(i);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto p : prerequisites){
            graph[p[1]].push_back(p[0]);
        }
        vector<int> visited(numCourses);
        vector<int> ans;
        for(int i = 0; i < numCourses; i++){
            if(visited[i] == 0){
                bool found  = false;
                dfs(graph, i, visited, found, ans);
                if(found){
                    return {};
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};