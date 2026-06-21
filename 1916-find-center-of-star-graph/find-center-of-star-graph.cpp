class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        //vector<vector<int>> adj(n + 2);
        vector<int> adj(n + 2);
        int ans = -1;
        for(auto e : edges){
            adj[e[0]]++;
            adj[e[1]]++;
            if(adj[e[0]] == n) ans = e[0];
            if(adj[e[1]] == n) ans = e[1];
        }
        // for(auto a : adj){
        //     for(auto i : a){
        //         cout << i << ", ";
        //     }
        //     cout << endl;
        // }
        return ans;
    }
};