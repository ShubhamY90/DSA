class Solution {
public:
    void dijkstra(vector<vector<int>>& times, vector<vector<pair<int,int>>>& graph, vector<int>& dist, int n, int k){
        

        //vector<int> dist(n + 1, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({0, k});
        dist[k] = 0;

        while (!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();

            if (cost > dist[node]) continue;

            for (auto &[next, wt] : graph[node]) {
                int newCost = cost + wt;
                if (newCost < dist[next]) {
                    dist[next] = newCost;
                    pq.push({newCost, next});
                }
            }
        }
        return;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //int ans = 0;
        //unordered_map<int, vector<int>> map;
        vector<vector<pair<int,int>>> graph(n);
        for (auto &t : edges) {
            graph[t[0]].push_back({t[1], t[2]});
            graph[t[1]].push_back({t[0], t[2]});
        }
        int ans = INT_MAX;
        int m = INT_MAX;
        for(int i = 0; i < n; i++){
            vector<int> dist(n, INT_MAX);
            dijkstra(edges, graph, dist, n, i);
            int temp = 0;
            for(int j = 0; j < n; j++){
                cout << i << " : " << j << " -> " << dist[j] << endl;
                if(j == i) continue;
                if(dist[j] <= distanceThreshold){
                    temp++;
                    //map[i].push_back(j);
                    cout << j << endl;
                }
            }
            //cout << "temp : " << temp << " ans : " << ans << endl;
            if(temp <= m){
                //cout << "updating ans" << endl;
                m = temp;
                ans = i;
            }
        }
        
        return ans;
    }
};