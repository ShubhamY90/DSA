class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        priority_queue<pair<double, int>> pq;
        vector<double> dist(n, INT_MIN);
        pq.push({1.0, start_node});
        dist[start_node] = 1;
        while(!pq.empty()){
            auto [wt, curr] = pq.top();
            pq.pop();

            //if(wt > dist[curr]) continue;

            for(auto nex : adj[curr]){
                double wn = nex.second;
                int ne = nex.first;
                if(dist[ne] < (wn * wt)){
                    dist[ne] = (wn*wt);
                    pq.push({dist[ne], ne});
                }
            }
        }

        if(dist[end_node]==INT_MIN) return 0;
        return dist[end_node];
    }
};