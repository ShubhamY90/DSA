class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for(auto it : times){
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<bool> vis(n + 1, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        vis[k] = true;
        vector<int> dis(n + 1, INT_MAX);
        dis[k] = 0;
        while(!pq.empty()){
            auto [wi, curr] = pq.top();
            pq.pop();

            if(dis[curr] < wi) continue;
            
            for(auto nex : adj[curr]){
                int nnex = nex.first;
                int wn = wi + nex.second;
                if(wn < dis[nnex]){
                    dis[nnex] = wn;
                    pq.push({wn, nnex});
                    vis[nnex] = true;
                }
            }
        }
        int ans = INT_MIN;
        for(int i = 1; i < n + 1; i++){
            ans = max(ans, dis[i]);
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};