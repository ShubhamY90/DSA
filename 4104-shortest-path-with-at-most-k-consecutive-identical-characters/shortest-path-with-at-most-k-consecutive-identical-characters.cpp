// State = (node, consecutiveCount). Since future moves depend on how many
// consecutive equal labels have been used so far, reaching the same node
// with different counts represents different states. Therefore, we run
// Dijkstra on (node, count) instead of just (node), where dist[node][count]
// stores the minimum cost to reach that exact state.

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        priority_queue<
            pair<int, vector<int>>,
            vector<pair<int, vector<int>>>,
            greater<pair<int, vector<int>>>
        > pq;

        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));
        vector<vector<vector<int>>> adj(n);

        for(auto e : edges){
            adj[e[0]].push_back({e[1], e[2], labels[e[1]]});
        }

        dist[0][1] = 0;
        pq.push({0, {0, labels[0], 1}});

        while(!pq.empty()){
            auto [wt, temp] = pq.top();
            pq.pop();

            int curr = temp[0];
            int l = temp[1];
            int cnt = temp[2];

            if(wt > dist[curr][cnt]) continue;

            for(auto ne : adj[curr]){
                int ncnt;

                if(ne[2] == l){
                    ncnt = cnt + 1;
                }
                else{
                    ncnt = 1;
                }

                if(ncnt > k){
                    continue;
                }

                int nwt = wt + ne[1];

                if(nwt < dist[ne[0]][ncnt]){
                    dist[ne[0]][ncnt] = nwt;
                    pq.push({nwt, {ne[0], ne[2], ncnt}});
                }
            }
        }

        int ans = INT_MAX;
        for(int i = 1; i <= k; i++){
            ans = min(ans, dist[n - 1][i]);
        }

        if(ans == INT_MAX) return -1;
        return ans;
    }
};