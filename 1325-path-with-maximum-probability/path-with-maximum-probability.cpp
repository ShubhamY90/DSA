class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<double, int>>> graph(n);
        for(int i = 0; i < edges.size(); i++){
            graph[edges[i][0]].push_back({(-1)*log(succProb[i]), edges[i][1]});
            graph[edges[i][1]].push_back({(-1)*log(succProb[i]), edges[i][0]});
        }
        
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;

        vector<double> dist(n, INT_MAX);
        pq.push({0, start_node});
        dist[start_node] = 0;
        while(!pq.empty()){
            auto [cost, curr] = pq.top();
            pq.pop();
            
            for(auto ne : graph[curr]){
                if(dist[ne.second] > cost + ne.first){
                    dist[ne.second] = cost + ne.first;
                    pq.push({dist[ne.second], ne.second});
                }
            }
        }
        if(dist[end_node] != INT_MAX) return exp(-dist[end_node]);
        return 0;
    }
};