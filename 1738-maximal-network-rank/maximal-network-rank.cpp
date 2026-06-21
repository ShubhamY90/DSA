class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n);
        for(auto r : roads){
            adj[r[0]].push_back(r[1]);
            adj[r[1]].push_back(r[0]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int sum = adj[i].size() + adj[j].size();
                for(int k = 0; k < adj[i].size(); k++){
                    if(adj[i][k] == j){
                        sum--;
                        break;
                    }
                }
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};